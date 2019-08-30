#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course{
public:
	Course(string course,string professor) : coursename(course) , professorname(professor) {}
	void prof_info(string name);
	bool checkprof(string professor);
	string course();
protected:
	string coursename;
	string professorname;
};