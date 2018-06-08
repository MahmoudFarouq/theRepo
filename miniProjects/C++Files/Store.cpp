#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <strstream>

using namespace std;
fstream availList("AvailList.txt", ios::out | ios::in | ios::ate);
fstream _file("Devices.txt", ios::out | ios::in | ios::ate);

string toString(int x)
{
	string res = "";
	while(x > 0)
	{
		int z = (x%10);
		char c = (char)(z+48);
		res = c + res;
		x /= 10;
	}
	return res;
}
int toInt(string x)
{
	int len = x.length();
	int result = 0;
	for(int i = 0; i < len; i++)
	{
	    result *= 10;
	    result += ((int)x[i]-48);
	}
	return result;
}
struct Device
{
    char ID[20];
    char Name[30];
    char Brand[30];
    char Price[10];
};
istream& operator>>(istream & in, Device &d)
{
	cout << "Enter Device ID: "; in.ignore(); in.getline(d.ID, 20);
	cout << "Enter Device Name: "; in.getline(d.Name, 30);
	cout << "Enter Device Brand: "; in.getline(d.Brand, 30);
	cout << "Enter Device Price: "; in.getline(d.Price, 10);
	return in;
}
ostream& operator<<(ostream & os, Device &d)
{
	os << "Device's ID: " << d.ID << endl;
	os << "Device's Name: " << d.Name << endl;
	os << "Device's Brand: " << d.Brand << endl;
	os << "Device's Price: " << d.Price << endl;
	return os;
}
int CheckAvailList(int neededLen)
{
    availList.seekg(0, ios::beg);
    while(!availList.eof())
    {
        int startPos = availList.tellg();
        char length[10];
        availList.getline(length, 10, '|');
        int len = toInt(length);
        if(len == 0 && strlen(length) == 0)
			return -1;
        if(neededLen <= len)
        {
            char pos[5];
            availList.getline(pos, 5, '\n');
            int result = toInt(pos);
            availList.seekg(startPos, ios::beg);
            availList.write("00|00\n", 6);
            return result;
        }
        else
        {
			availList.getline(length, 10, '\n');
		}
    }
    availList.clear();
    return -1;
}
void CompactFile()
{
    fstream TempFile;
    TempFile.open("tempFile.txt", ios::out | ios::in | ios::ate);
    _file.seekg(0, ios::beg);
    while(!_file.eof())
    {
		char c;
		_file.get(c);
        if(c == '*')
        {
            while(c != '\n') 
				_file.get(c);
			continue;
        }
        if(c != '*') 
			TempFile.put(c);
    }
    _file.close();
    _file.open("Devices.txt", ios::out | ios::in | ios::trunc);
    _file.close();
    _file.open("Devices.txt", ios::out | ios::in | ios::ate);
    TempFile.seekg(0, ios::beg);
    while(!TempFile.eof())
    {
		char c;
		TempFile.get(c);
		_file.put(c);
    }
    TempFile.close();
    TempFile.open("tempFile.txt", ios::out | ios::in | ios::trunc);
    TempFile.close();
    
}
int AddDevice(fstream& stream, Device & d)
{
    string all = d.ID;
    all = all + "#" + d.Name + "#" + d.Brand + "#" + d.Price + "\n";
	string lenStr = toString(all.length());
	int availPlace = CheckAvailList(all.length());
    all.insert(0, "$" + lenStr + "|");
    if(availPlace != -1){
        all += "*0|";
        stream.seekp(availPlace, ios::beg);
    }
    else{
		stream.seekp(0, ios::end);
	}
	stream.write(all.c_str(), all.length());
	return all.length();
}
void GetDevice(fstream& stream, char* id)
{
    stream.seekg(0, ios::beg);
    int idInt = toInt(id);					//convert the id to int
    while(!stream.eof())
    {
		char avail;			//available device, $ for exist, * for deleted
        char length[5];		//length of the device
        stream.get(avail);					//read the avail char
        stream.getline(length, 5, '|');		//read the length
        if(avail == '*')					//if not available, skip to whiteSpace
        {
			while(true)
			{
				char c;
				stream.get(c);
				if(c == '\n')
					break;
			}
			continue;
		}
        int len = toInt(length);			//transform length str to int
        char* buffer = new char[len];		//new char array of length len, to store the whole record
        stream.getline(buffer, len, '\n');	//read untill new line
        Device *d = new Device();			//device to put in
        istrstream strbuf(buffer);			//buffer for device manipulation
        strbuf.getline(d->ID, 20, '#');		//get the id of device
        if(toInt(d->ID) == idInt)			//if id == needed id
        {
            strbuf.getline(d->Name, 30, '#');	//cout the device and return
            strbuf.getline(d->Brand, 30, '#');
            strbuf.getline(d->Price, 10, '\n');
            delete buffer;
            cout << *d << endl;
            delete d;
            return;
        }
        delete[] buffer;
        delete d;
    }
    stream.clear();
    cout << "not found" << endl;
}
bool DeleteDevice(fstream& stream, char* id)
{
    stream.seekg(0, ios::beg);				//start from beginning
    int idInt = toInt(id);					//convert the id to int
    while(!stream.eof())					//while in file
    {
        int curpos = stream.tellg();		//get current position
        char avail;							//available device, $ for exist, * for deleted
        char length[5];						//length of the device
        stream.get(avail);					//read the avail char
        stream.getline(length, 5, '|');		//read the length	
        if(avail == '*')
        {
			while(true)
			{
				char c;
				stream.get(c);
				if(c == '\n')
					break;
			}
			continue;
		}
        int len = toInt(length);			//transforming the length to int
        char* buffer = new char[len];		//new char array
        stream.read(buffer, len);			//read the record
        Device *d = new Device();			//new device
        istrstream strbuf(buffer);			//string stream for buffer
        strbuf.getline(d->ID, 20, '#');		//put record id in the device id
        if(toInt(d->ID) == idInt)			//if id is exist, write the length and position in the availList file
        {
			stream.seekg(curpos, ios::beg);
			stream.put('*');				//make it unavailable
            char buffer[20];
            strcpy(buffer, length);
            strcat(buffer, "|");
            strcat(buffer, curpos == 0 ? "0":toString(curpos).c_str());
            strcat(buffer, "\n");
            availList.write(buffer, strlen(buffer));
            return true;
        }
        delete[] buffer;
        delete d;
    }
    return false;
}
void callAddDevice()
{
	Device d;
	cin >> d;
	AddDevice(_file, d);
	cout << "Done..." << endl;
}
void callUpdateDevice()
{
	cout << "Enter ID for the DEvice You want to Update: ";
	char id[20];
	cin >> id;
	bool done = DeleteDevice(_file, id);
	if(!done){
		cout << "This Device Doesnt Exist." << endl;
		return;
	}
	cout << " >>Enter new Data <<" << endl;
	callAddDevice();
}
void callDeleteDevice()
{
	cout << "Enter ID for the DEvice You want to Delete: ";
	char id[20];
	cin >> id;
	bool done = DeleteDevice(_file, id);
	if(!done){
		cout << "This Device Doesnt Exist." << endl;
	}else{
		cout << "Deleting..\nDone." << endl;
	}
	return;
}
void callSearchDevice()
{
	cout << "Enter ID for the DEvice You want to Search for: ";
	char id[20];
	cin >> id;
	GetDevice(_file, id);
	return;
}
void callCompact()
{
	cout << "Compacting..\nDone." << endl;
	CompactFile();
}
int main()
{
	START:
	cout << "\t\t\tHi to MahmoudFarouk'S Store\n"
		 << "1) Add New Device \n" 
		 << "2) Update Device\n" 
		 << "3) Delete Device\n"
		 << "4) Search for a Device By ID\n" 
		 << "5) Compact File\n"
		 << "6) Exit" << endl;
	
	cout << "Please Enter Your Choice: ";
	int choice;
	cin >> choice; 
	switch(choice)
	{
		case 1: callAddDevice(); break;
		case 2: callUpdateDevice(); break;
		case 3: callDeleteDevice(); break;
		case 4: callSearchDevice(); break;
		case 5: callCompact(); break;
		case 6: cout << "Nice to see you" << endl; _file.close(); availList.close();exit(1);
		default:
			cout << "Wrong Input, retry" << endl;
	}
	//system("cls");
	goto START;
	
		
    _file.close();
    availList.close();
    return 0;
}

