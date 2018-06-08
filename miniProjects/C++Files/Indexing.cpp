#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

enum DATA{ID, MODEL, PRICE};
struct Printer {char ID[30];char Model[30];char Description[50];char Price[30];};
struct Wrapper {char KEY[30];int goToIndex=-1;};

ostream& operator<<(ostream& out, Printer& p){
    out << "\nID: " << p.ID << ", Model: " << p.Model
        << ", Description: " << p.Description << ", Price: " << p.Price << endl;
    return out;
}

bool compare_ID(Wrapper& f, Wrapper& s){return strcmp(f.KEY,s.KEY) < 0;}

class SimpleIndex
{
	vector<Wrapper> ID_INDEX;       //PRIMARY KEY list
	vector<Wrapper> MODEL_INDEX;    //SEKANDARY KEY list(Model)
	vector<Wrapper> MODEL_INVLS;    //SEKANDARY KEY inverted list(Model)
	vector<Wrapper> PRICE_INDEX;    //SEKANDARY KEY list(Price)
	vector<Wrapper> PRICE_INVLS;    //SEKANDARY KEY inverted list(Price)

	string dataFilePath = "dataFile.txt";

public:
	SimpleIndex(){};
	bool exists(string name){
	ifstream f( name.c_str() );
	if (f.good()) {f.close();return true;}
	else {f.close();return false;}
    }

    int IndexBinarySearch(DATA d, string key){
        vector<Wrapper> *temp;
        switch(d){
            case ID:    temp = &ID_INDEX; break;
            case MODEL: temp = &MODEL_INDEX; break;
            case PRICE: temp = &PRICE_INDEX; break;
        }
        int low = 0;
        int high = temp->size()-1;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            int c = strcmp((*temp)[middle].KEY, key.c_str());
            if (c == 0)
                return middle;
            else if (c < 0)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return -1;
    }

    void printPrinter_ID(string PK){
        ifstream fin;
        fin.open(dataFilePath, ios::binary | ios::in);
        int address = IndexBinarySearch(ID, PK);
        if (address == -1){
            cout << "\n\t\tThis Printer Does not exist." << endl;
            return;
        }
        int offset = ID_INDEX[address].goToIndex;
        short len;
        Printer p;
        fin.seekg(offset, ios::beg);
        fin.read((char*)&len, sizeof(len));
        char *buffer = new char[len];
        fin.read(buffer, len);
        istringstream stream(buffer);
        stream.getline(p.ID, 30, '|');
        stream.getline(p.Model, 30, '|');
        stream.getline(p.Description, 50, '|');
        stream.getline(p.Price, 20, '#');
        if(p.ID[0] == '*') {cout << "\n\t\tThis Printer Does not exist." << endl; return;}
        cout << p << endl;
        fin.close(); delete buffer;
    }

    void printPrinter(DATA d, string SK){
        ifstream fin;
        fin.open(dataFilePath, ios::binary | ios::in);
        int PlaceInIndexVector = IndexBinarySearch(d, SK);
        if(PlaceInIndexVector == -1) {cout << "\t\tDoes not Exist." << endl; return;}
        int InInvList = (d == MODEL ? MODEL_INDEX:PRICE_INDEX)[PlaceInIndexVector].goToIndex;

        vector<Wrapper> *tempVector = (d == MODEL ? &MODEL_INVLS:&PRICE_INVLS);
        while(InInvList != -1){
            printPrinter_ID((*tempVector)[InInvList].KEY);
            InInvList = (*tempVector)[InInvList].goToIndex;
        }
    }

    void insertPrinter(Printer& p){
        ofstream fout;
        fout.open(dataFilePath, ios::app | ios::out | ios::binary);

        char buffer[200];
        strcpy(buffer, p.ID);			strcat(buffer, "|");
        strcat(buffer, p.Model);		strcat(buffer, "|");
        strcat(buffer, p.Description);	strcat(buffer, "|");
        strcat(buffer, p.Price);        strcat(buffer, "#");
        short len = strlen(buffer);

        fout.seekp(0, ios::end);
        int addess = fout.tellp();
        fout.write((char*)&len, sizeof(len));
        fout.write(buffer, len);

        Wrapper temp1;
        strcpy(temp1.KEY, p.ID);
        temp1.goToIndex = addess;
        ID_INDEX.push_back(temp1);

        PutInIvertedList(MODEL, p.Model, p.ID);
        PutInIvertedList(PRICE, p.Price, p.ID);

        sortIndex();
        fout.close();
    }

    void UpdatePrinter(Printer& p){
        fstream fout;
        fout.open(dataFilePath, ios::in | ios::out | ios::binary);

        char buffer[200];
        strcpy(buffer, p.ID);			strcat(buffer, "|");
        strcat(buffer, p.Model);		strcat(buffer, "|");
        strcat(buffer, p.Description);	strcat(buffer, "|");
        strcat(buffer, p.Price);        strcat(buffer, "#");
        short newLen = strlen(buffer);

        int indexInIdVector = IndexBinarySearch(ID, p.ID);
        int offset = ID_INDEX[indexInIdVector].goToIndex;
        fout.seekg(offset, ios::beg);
        short oldLen;
        fout.read((char*)&oldLen, 2);
        if(newLen < oldLen-2){
            fout.seekg(offset, ios::beg);
            fout.write((char*)&newLen, 2);
            fout.write(buffer, newLen);
            short diff = oldLen-newLen;
            fout.write((char*)&diff, 2);
            fout.write("*", 1);

            int indexInModelVector = IndexBinarySearch(MODEL, p.Model);
            int indexInPriceVector = IndexBinarySearch(PRICE, p.Price);

            DeleteFromInvList(MODEL, p.ID, indexInModelVector);
            DeleteFromInvList(PRICE, p.ID, indexInPriceVector);
            PutInIvertedList(MODEL, p.Model, p.ID);
            PutInIvertedList(PRICE, p.Price, p.ID);
        }else{
            deletePrinter(p.ID);
            insertPrinter(p);
        }

    }

    void PutInIvertedList(DATA d, char* key, char* Id){

        Wrapper temp1, temp2;
        vector<Wrapper> *tempVector = (d == MODEL ? &MODEL_INVLS:&PRICE_INVLS);
        int InIndex = IndexBinarySearch(d, key);

        strcpy(temp1.KEY, Id); temp1.goToIndex = -1;
        strcpy(temp2.KEY, key); temp2.goToIndex = (*tempVector).size();

        if(InIndex != -1){
            int InInvList = (d == MODEL ? MODEL_INDEX:PRICE_INDEX)[InIndex].goToIndex;
            while((*tempVector)[InInvList].goToIndex != -1){
                InInvList = (*tempVector)[InInvList].goToIndex;
            }
            (*tempVector)[InInvList].goToIndex = (*tempVector).size();
            (*tempVector).push_back( temp1 );
        }else{
            (d == MODEL ? MODEL_INDEX:PRICE_INDEX).push_back(temp2);
            (*tempVector).push_back(temp1);
        }
    }

    void deletePrinter(string PK){
        fstream fout(dataFilePath, ios::binary | ios::out | ios::in);
        int address = IndexBinarySearch(ID, PK);
        if (address == -1){
            cout << "\nPrinter not found." << endl;
            return;
        }
        short len;
        Printer p;
        fout.seekg(ID_INDEX[address].goToIndex, ios::beg);
        fout.read((char*)&len, sizeof(len));

        char *buffer = new char[len];
        fout.read(buffer, len);
        istringstream stream(buffer);
        stream.getline(p.ID, 30, '|');
        stream.getline(p.Model, 30, '|');
        stream.getline(p.Description, 50, '|');
        stream.getline(p.Price, 20, '#');

        fout.seekg(ID_INDEX[address].goToIndex+2, ios::beg);
        fout << '*';

        int PosInModel = IndexBinarySearch(MODEL, p.Model);
        int PosInPrice = IndexBinarySearch(PRICE, p.Price);
        //delete from THREE indexes
        ID_INDEX.erase(ID_INDEX.begin()+address-1);
        DeleteFromInvList(MODEL, p.ID, PosInModel);
        DeleteFromInvList(PRICE, p.ID, PosInPrice);
        fout.close();
    }

    void DeleteFromInvList(DATA d, char* Id, int PosInIndexVec){
        int InInvList = (d == MODEL ? MODEL_INDEX:PRICE_INDEX)[PosInIndexVec].goToIndex;
        vector<Wrapper> *tempVector = (d == MODEL ? &MODEL_INVLS:&PRICE_INVLS);

        if((*tempVector)[InInvList].goToIndex == -1){
            (*tempVector).erase((*tempVector).begin()+PosInIndexVec-1);
            return;
        }

        int ElementBefore = InInvList;
        while(InInvList != -1){
            if(strcmp(Id, (*tempVector)[InInvList].KEY) == 0) break;
            ElementBefore = InInvList;
            InInvList = (*tempVector)[InInvList].goToIndex;
        }
        if(InInvList != -1)
            (*tempVector)[ElementBefore].goToIndex = (*tempVector)[InInvList].goToIndex;
        else{
            (*tempVector)[ElementBefore].goToIndex = -1;
        }
    }

    void ReconstructIndex(){
        ifstream fin;
        if(!exists(dataFilePath))return;
        fin.open(dataFilePath, ios::in | ios::binary);
        while (fin.tellg() != -1)
        {
            int offset = fin.tellg();
            short len;
            fin.read((char*)&len, sizeof(len));
            if(len < 0) return;
            char *buffer = new char[len];
            fin.read(buffer, len);
            if (buffer[0] == '*') continue;
            istringstream strbuf(buffer);
            Printer p;
            strbuf.getline(p.ID, 30, '|');
            strbuf.getline(p.Model, 30, '|');
            strbuf.getline(p.Description, 60, '|');
            strbuf.get(p.Price, 20, '#');
            Wrapper temp1;
            strcpy(temp1.KEY, p.ID);
            temp1.goToIndex = offset;
            ID_INDEX.push_back(temp1);
            PutInIvertedList(MODEL, p.Model, p.ID);
            PutInIvertedList(PRICE, p.Price, p.ID);
        }
        sortIndex();
        fin.close();
    }

    void Visualize(){
        ifstream fin;
        fin.open(dataFilePath, ios::in | ios::binary);
        if(!exists(dataFilePath))return;
        while (!fin.eof())
        {
            short len;
            char temp;
            fin.read((char*)&len, sizeof(len));
            if (fin.eof()) break;
            char c;
            fin.get(c);
            fin.seekg(-1+len, ios::cur);
            cout << (c == '*' ? '*':'-');
        }
        cout << endl;
        fin.close();
    }

    void sortIndex(){
        sort(&ID_INDEX[0], &ID_INDEX[ID_INDEX.size()], compare_ID);
        sort(&MODEL_INDEX[0], &MODEL_INDEX[ID_INDEX.size()], compare_ID);
        sort(&PRICE_INDEX[0], &PRICE_INDEX[ID_INDEX.size()], compare_ID);
    }

    void CompactFile(){
        fstream _file(dataFilePath, ios::in | ios::out | ios::ate);
        _file.seekg(0, ios::end);
        int len = _file.tellg();
        char* arr = new char[len];
        int curIndex = 0;
        _file.seekg(0, ios::beg);
        while(_file.tellg() != -1){
            char c;
            _file.get(c);
            if(c == '*'){
                curIndex-=2;
                while(c != '#'){ _file.get(c);}
                continue;
            }
            arr[curIndex] = c;curIndex++;
        }
        _file.close();
        _file.open(dataFilePath, ios::out | ios::in | ios::trunc);
        _file.write(arr, curIndex);
        _file.close();
        ReconstructIndex();
    }
};

SimpleIndex i;

void insertPrinter();
void deletePrinter();
void printPrinter();
void printPrinter(DATA d);
void UpdatePrinter();

int main()
{
    i.ReconstructIndex();

    Start:
    cout << " \t\t Welcome \n "
	<< "1) Add New printer \n "
    << "2) Update printer \n "
    << "3) Delete printer \n "
    << "4) Search for a printer using ID (using primary Index) \n "
    << "5) Search for a printer using model (using secondary Index) \n "
    << "6) Search for a printer using price (using secondary Index) \n "
    << "7) Compact File \n "
    << "8) Visualize File \n "
    << "9) Exit \n "
    << "Your Choice: ";
    int c; cin >> c;
    switch (c){
        case 1: insertPrinter();break;
        case 2: UpdatePrinter();break;
        case 3: deletePrinter();break;
        case 4: printPrinter();break;
        case 5: printPrinter(MODEL);break;
        case 6: printPrinter(PRICE);break;
        case 7: i.CompactFile();break;
        case 8: i.Visualize();break;
        case 9: return 0;
    }
    goto Start;
}
void insertPrinter(){
    Printer p;
    cin.ignore();
    cout << "Enter ID: "; cin.getline(p.ID, 30);
    cout << "Enter Model: "; cin.getline(p.Model, 30);
    cout << "Enter Description: "; cin.getline(p.Description, 50);
    cout << "Enter Price: "; cin.getline(p.Price, 20);
    i.insertPrinter(p);
}

void deletePrinter(){
    string PK;
    cout << "Enter ID of Printer to Delete: "; cin >> PK;
    i.deletePrinter(PK);
}

void printPrinter(){
    string PK;
    cout << "Enter ID of Printer to Print: "; cin >> PK;
    i.printPrinter_ID(PK);
}

void printPrinter(DATA d){
    string PK;
    cout << "Enter " << (d == MODEL ? "Model":"Price") << " of Printer to Print: "; cin >> PK;
    i.printPrinter(d, PK);
}

void UpdatePrinter(){
    string PK;
    cout << "Enter ID of Printer to Update: "; cin >> PK;
    int srch = i.IndexBinarySearch(ID, PK);
    if(srch == -1){
        cout << "Not Exist!" << endl;
        return;
    }
    Printer p;
    cin.ignore();
    cout << "Enter Model: "; cin.getline(p.Model, 30);
    cout << "Enter Description: "; cin.getline(p.Description, 30);
    cout << "Enter Price: "; cin.getline(p.Price, 30);
    i.UpdatePrinter(p);
}


