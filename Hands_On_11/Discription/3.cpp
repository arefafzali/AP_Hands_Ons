#include <iostream>

using namespace std;

class ReferenceGenerator
{
	// Don't change the this class
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

int* generateIntPointer()
{
	ReferenceGenerator referenceGenerator(40);
	return referenceGenerator.getReference();
}

int main()
{
	int* reference = generateIntPointer();
	*reference = (*reference) + 1;
	cout << *reference << endl;
	delete[] reference;
}
/*Output: 
41
*/