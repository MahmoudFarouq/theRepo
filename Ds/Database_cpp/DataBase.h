#ifndef DATABASE_H
#define DATABASE_H
#include <set>
#include <iostream>
#include <iterator>
using namespace std;

struct Student{
    Student(string n, int a = 0, float g = 0):name(n), age(a), grade(g){};
    Student(const Student& other):name(other.name), age(other.age), grade(other.grade){};

    string name;
    int age;
    float grade;

    bool operator<(const Student& other) const
    {
      return name < other.name;
    }
    friend ostream& operator<<(ostream& os, const Student& s)
    {
         os << "Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade << endl;
         return os;
    }
    Student& operator=(const Student& se)
    {
        age = se.age;grade = se.grade;name = se.name;
        return *this;
    }
};

typedef bool(*CompareFunc)(const Student&,const Student&);

class DataBase
{
    public:
        DataBase();
        bool AddStudent( Student s);
        bool Search(string name);
        void ShowAll();
        bool Update(string name, int newGrade);
        Student GetMaxGrade();
        virtual ~DataBase();
    private:
        set<Student, CompareFunc>* Container;
        set<Student,CompareFunc>::iterator it;
};
#endif // DATABASE_H
