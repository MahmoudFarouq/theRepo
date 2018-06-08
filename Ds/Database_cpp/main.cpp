#include <iostream>
#include <DataBase.h>

using namespace std;

int main()
{
    DataBase db;

    Student s1("mahmoudRedaFarouk", 21, 3.8)
          , s2("mohamadAhmadAbdallah", 20, 2.5)
          , s3("mohamadAymanHassan", 19, 1.9);

    cout << db.AddStudent(s1) << endl;
    cout << db.AddStudent(s2) << endl;
    cout << db.AddStudent(s3) << endl;

    db.ShowAll();

    cout << db.Update("mohamadAymanHassan", 5) << endl;
    cout << db.Update("asd", 5) << endl;

    db.ShowAll();

    cout << "Maximum Grade: " << db.GetMaxGrade() << endl;

    return 0;
}
