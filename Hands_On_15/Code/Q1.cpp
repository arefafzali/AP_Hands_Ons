#include <iostream>
#include <algorithm>
#include <vector> 
#include <ctime>
#include <string>
#define NUMBER_OF_STUDENTS 10 
using namespace std;

class Student
{
private:
    string name;
    float grade;
public:
    Student(string _name, float _grade);
    ~Student();
    static bool comp(Student& a , Student& b)
    {
        if ( b.grade < a.grade )
            return true;
        return false;
    }
    //TODO: Implement a binary operator for Student class
    string toString() const { return name + "  " + to_string(grade);}
};

Student::Student(string _name, float _grade)
{
    name = _name;
    grade = _grade;
}
Student::~Student()
{
}
ostream& operator<<(ostream& out, const Student& student)
{
    out << student.toString();
    return out;
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)(clock()));
    vector<Student> allStudents;
    for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        float grade = float(rand() % 20) + (float(rand() % 100) / 100); 
        Student student("student" + to_string(i), grade);
        allStudents.push_back(student);
    }

    //TODO: Sort allStudents vector using sort function and iterators
    sort(allStudents.begin() , allStudents.end() , Student::comp);

    // vector<Student>::iterator ptr; 
    for(int i = 0 ; i < allStudents.size() ; i++)
        cout << allStudents[i].toString() << endl;
    
    return 0;
}

