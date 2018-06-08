#include "DataBase.h"

bool compare_Student(const Student& lhs, const Student& rhs){
   return lhs < rhs;
}
DataBase::DataBase(){
    Container = new set<Student, CompareFunc>(compare_Student);
}
bool DataBase::AddStudent( Student s){
    (*Container).insert(s);
    return true;
}
bool DataBase::Search(string name){
    for(it = Container->begin(); it != Container->end(); it++)
    {
        if(it->name == name)
        {
            return true;
        }
    }
    return false;
}
bool DataBase::Update(string name, int newGrade){
    bool sr4 = Search(name);
    if(sr4 == false)
    {
        return false;
    }
    Student s = *it;
    s.grade = newGrade;
    (*Container).erase(it);
    (*Container).insert(s);
    return true;
}
void DataBase::ShowAll(){
    copy(Container->begin(), Container->end(), ostream_iterator<Student>(cout, "\n"));
}
Student DataBase::GetMaxGrade(){
    it = Container->begin();
    Student s = *it;
    for(; it != Container->end(); it++)
    {
        if(it->grade > s.grade)
        {
            s = *it;
        }
    }
    return s;
}
DataBase::~DataBase(){
    delete Container;
}
