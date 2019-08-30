#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void introduce() = 0;
	virtual ~Animal(){};
};

class Lion : public Animal
{// Don't change the Lion private fields
public:
	Lion(int _age)
	: Animal()
	{
		age = new int;
		*age = _age;
	}
	
	void introduce()
	{
		cout << "I'm a lion \t age: " << *age << endl;
		//delete age;
	}

	~Lion()
	{
		delete age;
	}

private:
	int* age;
};

int main()
{
	//Don't change the main body
	Animal* animal = new Lion(8);
	animal->introduce();
	delete animal; 
}
/*Output: 
I'm a lion 	 age: 8
*/