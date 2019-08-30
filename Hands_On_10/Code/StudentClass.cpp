#include "StudentClass.h"

void Student::Getcourse(){
	getline(cin,allcourses);
	string course;
	for(int i=0;i<allcourses.size();i++){
		if(allcourses[i]==' '){
			if(firsttime){
				firsttime=false;
			}
			else{
				studentcourse.push_back(course);
				course.erase();
			}
		}
		else{
			course.push_back(allcourses[i]);
		}
	}
	firsttime=true;
	studentcourse.push_back(course);
}

void Student::course_info(string coursename){
	for(int i=0;i<studentcourse.size();i++){
		if(studentcourse[i]==coursename){
			cout<<username<<" ";
		}
	}
}

void Student::printcourse(string studentlist){
	if(studentlist==username){
		for(int i=0;i<studentcourse.size();i++){
			cout<<studentcourse[i]<<" ";
		}
	}
}