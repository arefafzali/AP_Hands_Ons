#include <iostream>

using namespace std;

class ReferenceGenerator
{
	// Don't change this class
public:
 	ReferenceGenerator(int input)
	{
		field = new int;
		*field = input;
	}

	int* getReference()
	{
		return field;
	}

	~ReferenceGenerator()
	{
		delete field;
	};
private:
	int* field;
};
/*
int* generateIntPointer()
{
	ReferenceGenerator referenceGenerator(40);
	return referenceGenerator.getReference();
}
*/
int main()
{
	ReferenceGenerator referenceGenerator(40);
	int* reference = referenceGenerator.getReference();
	*reference = (*reference) + 1;
	cout << *reference << endl;
//	delete[] reference;
}
/*Output: 
41
*/