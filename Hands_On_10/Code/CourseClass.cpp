#include "CourseClass.h"

void Course::prof_info(string name){
	if(name==coursename){
		cout<<professorname;
	}
}

bool Course::checkprof(string professor){
	if(professor==professorname){
		return true;
	}
	else{
		return false;
	}
}

string Course::course(){
	return coursename;
}