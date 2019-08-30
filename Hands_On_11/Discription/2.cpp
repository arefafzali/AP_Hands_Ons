#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <string.h>

using namespace std;

string convertIntToString(int num);

class Date
{
	//Add a new method to this class
public:
	Date(int day, int month, int year)
	{
        dateVars = new int[3];
		dateVars[0] = day;
		dateVars[1] = month;
		dateVars[2] = year;
	}
	string getDate()
	{
		string result = convertIntToString(dateVars[0]) + "." ;
		result += convertIntToString(dateVars[1]) + "." ;
		result += convertIntToString(dateVars[2]);
		return result;
	}
private:
	int* dateVars;
};

class Person
{
public:
	Person(string n, int day, int month, int year)
	{
		name = n;
		birthday = new Date(day, month, year);
		numbers = new int[10];
	} 
	~Person()
	{
		delete[] numbers;
	}
	string getInfo()
	{
		string result = "Name: " + name + "\tBirthday: " + birthday->getDate(); 
		return result;
	}
private:
	Date* birthday;
	string name;
	int* numbers;

};

string convertIntToString(int num)
{
	stringstream ss;
	ss << num;
	string result = ss.str();
	return result;
}

int main(){
	char *textString = (char*)malloc(128*sizeof(char)); //Don't change this line 
	strcpy(textString , "Sadaf"); 
	string name(textString);
	delete(textString); //check usage of delete function

    Person* P1 = new Person(name, 22, 7, 1998); //Don't delete this line
	cout << P1->getInfo() << endl;
}

/*Output: 
Name: Sadaf	Birthday: 22.7.1998
*/