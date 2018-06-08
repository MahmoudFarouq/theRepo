#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const int deleted = -2;
static const int empty = -1;

static const int Size = 997;
static const string dataFilePath = "dataFile.txt";
static const string hashFile = "HashFile.txt";
static const string OverFlowFile = "OverFlowFile.txt";


string generateRandomString(){
    string x;
    for(int i = 0; i < 40; i++)
        x += alphanum[ rand()%(strlen(alphanum)) ];
    return x;
}

int getRandomNumber(){
    return (rand() % 10000)*(rand() % 10000);
}

int getDigitCount(int n){
    int numDigits = 1;
    while (n > 9) {
        n /= 10;
        numDigits++;
    }
    return numDigits;
}

string toString(int x){
    stringstream ss;
    ss << x;
    return ss.str();
}

int toInt(string x){
    int res = 0;
    int len = x.length();
    for(int i = 0; i < len; i++){
        res *= 10;
        res += x[i]-48;
    }
    return res;
}

int FoldShift(int key){
    int arraySize = 997;
    int keyDigitCount = getDigitCount(key);
    int groupSize = getDigitCount(arraySize);
    int groupSum = 0;
    string keyString = toString(key);
    unsigned i;
    for (i = 0; i < keyString.length(); i += groupSize) {
        if (i + groupSize <= keyString.length()) {
            string group = keyString.substr(i, i + groupSize);
            groupSum += toInt(group);
        }
    }
    // There is no remaining part if count is divisible by groupsize.
    if (keyDigitCount % groupSize != 0) {
        string remainingPart =
               keyString.substr(i-groupSize, keyString.length());
        groupSum += toInt(remainingPart);
    }
    return groupSum % arraySize;
}

int midSquare(int key){
    int sqr = key*key;
    if(key < 0)
		return -1;
    string keyString = toString(sqr);
    string resString = keyString.substr( (keyString.length())/2-1, (keyString.length())/2+1 );
    int res = toInt(resString);
    return res;
}

int MultiplicationMethod(int k){
    int m = 997;
    double a = 0.618033;
    float ka = k*a;
    int h = floor(m*(ka - (int)ka));
    return h;
}


struct Student{int ID = -1;char Name[50];};

struct Wrapper{int PK = -1;int offset = -1;};

ostream& operator<<(ostream& out, Student& s){
    out << "\nID: " << s.ID << ", Name: " << s.Name << endl;
    return out;
}
ostream& operator<<(ostream& out, Wrapper& w){
    out << "\nID: " << w.PK << ", Offset: " << w.offset << endl;
    return out;
}

class Method{
public:
    Wrapper hashTable[2][997];
    Method(){}
    virtual int IDSearch(int id) = 0;		//returns the position in hashtable
    virtual int Hash(int key) = 0;
    virtual void insertInTable(Wrapper& temp) = 0;

	bool exists(string name){
        ifstream f( name.c_str() );
        if (f.good()) {f.close();return true;}
        else {f.close();return false;}
    }

    bool printStudent(int PK){
        ifstream fin;
        fin.open(dataFilePath, ios::binary | ios::in);
        int pos = this->IDSearch(PK);
        if(pos == empty) return false;

        int offset;
        if(pos > Size || (hashTable[0][pos].PK != PK && hashTable[1][pos].PK == PK)){ // this is an offset, from overflow area
			offset = pos;
		}else{
			offset = (hashTable[0][pos].PK == PK ? hashTable[0][pos].offset:hashTable[1][pos].offset);
		}
        if (offset == -1){
            return false;
        }
        Student s;
        fin.seekg(offset, ios::beg);
        fin.read((char*)&s, sizeof(s));
        if(s.ID == deleted || s.ID == -1) {return false;}
        cout << s << endl;
        fin.close();
        return true;
    }

    void insertStudent(Student& s){
        ofstream fout;
        fout.open(dataFilePath, ios::app | ios::out | ios::binary);
        fout.seekp(0, ios::end);
        int offset = fout.tellp();
        fout.write((char*)&s, sizeof(s));
        Wrapper temp;
        temp.offset = offset; temp.PK = s.ID;
        insertInTable(temp);
        fout.close();
    }

    bool deleteStudent(int PK){
        fstream fout(dataFilePath, ios::binary | ios::out | ios::in);
        int pos = IDSearch(PK);
        if(pos == empty) return false;
		int offset;
        if(pos > Size || (hashTable[0][pos].PK != PK && hashTable[1][pos].PK != PK)){ // this is an offset, from overflow area
			offset = pos;
		}else{
			offset = (hashTable[0][pos].PK == PK ? hashTable[0][pos].offset:hashTable[1][pos].offset);
			hashTable[0][pos].PK == PK ? (hashTable[0][pos].PK = -2):(hashTable[0][pos].PK = -2);
		}
        if (offset == -1){
            return false;
        }
        fout.seekg(offset, ios::beg);
        fout.write((char*)&deleted, 4);
        fout.close();
        return true;
    }

    void ReconstructIndex(){
        ifstream fin;
        if(!exists(hashFile)){return;}
        fin.open(hashFile, ios::in | ios::binary);
        while (fin.tellg() != -1)
        {
            Wrapper w;
            fin.read((char*)&w, sizeof(w));
            insertInTable(w);
        }
        fin.close();
    }
    ~Method(){
        ofstream fout;
        fout.open(hashFile, ios::out | ios::binary);
        for(int i = 0; i < 977; i++)
        {
            fout.write((char*)&hashTable[0][i], sizeof(Wrapper));
            fout.write((char*)&hashTable[1][i], sizeof(Wrapper));
        }
        fout.close();
    }
};

class MethodI : public Method{
    int IDSearch(int id){
        int h = Hash(id);
        int start = h;
        do{
            if(hashTable[0][h].offset == empty) return -1;
            if(hashTable[0][h].PK == id) return h;
            if(hashTable[1][h].offset == empty) return -1;
            if(hashTable[1][h].PK == id) return h;
            h++; h %= Size;
        }while(start != h);
        return -1;
    }
    void insertInTable(Wrapper& temp){
        int h = Hash(temp.PK);
        int start = h;
        do{
            if(hashTable[0][h].offset == empty || hashTable[0][h].offset == deleted){
                hashTable[0][h] = temp;
                return;
            }
            if(hashTable[1][h].offset == empty || hashTable[1][h].offset == deleted){
                hashTable[1][h] = temp;
                return;
            }
            h++; h %= Size;
        }while(start != h);
    }
    int Hash(int key){
        return MultiplicationMethod(key);
    }
};

class MethodII : public Method{
    int IDSearch(int id){
        int h = Hash(id);
        int i = 0;
        int curIndex = h;
        do{
            if(hashTable[0][curIndex].offset == empty) return -1;
            if(hashTable[0][curIndex].PK == id) return curIndex;
            if(hashTable[1][curIndex].offset == empty) return -1;
            if(hashTable[1][curIndex].PK == id) return curIndex;
            i++;
            curIndex = h+i*i % Size;
        }while(curIndex != h);
        return -1;
    }
    void insertInTable(Wrapper& temp){
        int h = Hash(temp.PK);
        int i = 0;
        int curIndex = h;
        do{
            if(hashTable[0][curIndex].PK == empty || hashTable[0][curIndex].PK == deleted){
                hashTable[0][curIndex] = temp;
                return;
            }
            if(hashTable[1][curIndex].PK == empty || hashTable[1][curIndex].PK == deleted){
                hashTable[1][curIndex] = temp;
                return;
            }
            i++;
            curIndex = h+i*i % Size;
        }while(curIndex != h);
    }
    int Hash(int key){
        return MultiplicationMethod(key);
    }
};

class MethodIII : public Method{
    int IDSearch(int id){
        int h = Hash(id);
        int step = midSquare(id);
        int i = 0;
        int curIndex = h;
        do{
            if(hashTable[0][curIndex].offset == -1) return -1;
            if(hashTable[0][curIndex].PK == id) return curIndex;
            if(hashTable[1][curIndex].offset == -1) return -1;
            if(hashTable[1][curIndex].PK == id) return curIndex;
            i++;
            curIndex = (h+step*i%Size);
        }while(curIndex != h);
        return -1;
    }
    void insertInTable(Wrapper& temp){
        int h = Hash(temp.PK);
        int step = midSquare(temp.PK);
        int i = 0;
        int curIndex = h;
        do{
            if(hashTable[0][curIndex].PK == -1 || hashTable[0][curIndex].PK == deleted){
                hashTable[0][curIndex] = temp;
                return;
            }
            if(hashTable[1][curIndex].PK == -1 || hashTable[1][curIndex].PK == deleted){
                hashTable[1][curIndex] = temp;
                return;
            }
            i++;
            curIndex = (h+step*i)%Size;
        }while(curIndex != h);
    }
    int Hash(int key){
        return FoldShift(key);
    }
};

class MethodIV  : public Method{
    Wrapper OverFlowArea[1000];
    int lastElementInOverFlow = -1;
public:
    MethodIV(){
        ReconstructIndex_IV();
    }
private:
    void ReconstructIndex_IV(){
        ReconstructIndex();
        ifstream fin;
        if(!exists(OverFlowFile))return;
        fin.open(OverFlowFile, ios::in | ios::binary);
        while (fin.tellg() != -1)
        {
            Wrapper w;
            fin.read((char*)&w, sizeof(w));
            insertInTable(w);
        }
        fin.close();
    }

    int IDSearch(int id){
        int h = Hash(id);
        int i = 0;
        if(hashTable[0][h].offset == -1) return -1;
        if(hashTable[0][h].PK == id) return h;
        if(hashTable[1][h].offset == -1) return -1;
        if(hashTable[1][h].PK == id) return h;
        do{
            if(OverFlowArea[i].offset == -1) return -1;
            if(OverFlowArea[i].PK == id) return OverFlowArea[i].offset;
            i++;
        }while(i < lastElementInOverFlow);
        return -1;
    }
    void insertInTable(Wrapper& temp){
        int h = Hash(temp.PK);
        int i = 0;
        if(hashTable[0][h].PK == -1 || hashTable[0][h].PK == deleted){
            hashTable[0][h] = temp;
            return;
        }
        if(hashTable[1][h].PK == -1 || hashTable[1][h].PK == deleted){
            hashTable[1][h] = temp;
            return;
        }
        do{
            if(OverFlowArea[i].PK == -1 || OverFlowArea[i].PK == temp.PK){
                OverFlowArea[i] = temp;
                return;
            }
            i++;
        }while(i < lastElementInOverFlow);
    }
    int Hash(int key){
        return MultiplicationMethod(key);
    }
};

void Computer(Method* m);

int main()
{
    srand(time(0));
    MethodI m;
	m.ReconstructIndex();
	Computer((Method*)&m);
    return 0;
}

void Computer(Method* m){
	// Inserting 500 REcord //
	/*for( int i = 0; i < 500;i++ ){
        int id = getRandomNumber();
        Student s; s.ID = id;  strcpy(s.Name, generateRandomString().c_str());
        m->insertStudent(s);
    }*/
	// PRinting 500 REcord //
	int c = 0;
	for( int i = 0; i < 997;i++ ){
        if(m->printStudent(m->hashTable[0][i].PK))
			c++;
        if(m->printStudent(m->hashTable[1][i].PK))
			c++;
    }
    cout << c << endl;
	// Deleting 50 REcord //
    /*int deletedREcords = 0;
    int i = 0;
    while( deletedREcords <= 50 ){
        if(m->deleteStudent(m->hashTable[0][i].PK))
            deletedREcords++;
        if(m->deleteStudent(m->hashTable[1][i].PK))
            deletedREcords++;
        i++;
    }*/
}





