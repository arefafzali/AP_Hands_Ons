#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
public:
	Student(string name): username(name){}
	void Getcourse();
	void course_info(string coursename);
	void printcourse(string studentlist);
protected:
	int c=0;
	bool firsttime=true;
	vector<string> studentcourse;
	string allcourses;
	string username;
};
