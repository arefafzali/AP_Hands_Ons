#include "CourseClass.h"
#include "StudentClass.h"

int main()
{
	string command;
	vector<Student> student;
	vector<Course> course;
	while(cin>>command){
		if(command=="course"){
			string coursename, teachername;
			cin>>coursename>>teachername;
			Course courseplus(coursename,teachername);
			course.push_back(courseplus);
		}
		else if(command=="student"){
			string username;
			cin>>username;
			Student studentplus(username);
			student.push_back(studentplus);
			student[student.size()-1].Getcourse();
		}
		else if(command=="course_info"){
			string coursename;
			cin>>coursename;
			cout<<"Professor: ";
			for(int i=0;i<course.size();i++){
				course[i].prof_info(coursename);
			}
			cout<<endl<<"Students: ";
			for(int i=0;i<student.size();i++){
				student[i].course_info(coursename);
			}
			cout<<endl;
		}
		else if(command=="student_list"){
			string prof,profcourse;
			cin>>prof;
			for(int i=0;i<course.size();i++){
				if(course[i].checkprof(prof)){
					profcourse=course[i].course();
				}
			}
			for(int i=0;i<student.size();i++){
				student[i].course_info(profcourse);
			}
			cout<<endl;
		}
		else if(command=="course_list"){
			string studentlist;
			cin>>studentlist;
			for(int i=0;i<student.size();i++){
				student[i].printcourse(studentlist);
			}
			cout<<endl;
		}
	}
	return 0;
}