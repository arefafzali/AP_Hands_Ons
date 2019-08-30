#include <iostream>

using namespace std;

class Node 
{
public:
	Node(int degree, int maxPossibleDegree)
	{
		if(degree > maxPossibleDegree)
			throw 1;
		else
		{
			this->nodeData = new int[2];
			nodeData[0] = degree;
			nodeData[1] = maxPossibleDegree;
		}
	}
	~Node()
	{
		delete[] this->nodeData;
	}

private:
	int* nodeData;
};

int main()
{
	int* firstData ;
	int* secondData = new int[2];

	secondData[0] = 5;
	secondData[1] = 4;
	firstData = secondData;

	try {
		Node node(firstData[0], firstData[1]);
	}
	catch (int a)
	{
		cout << a << endl;
	}

	delete[] secondData;
}
/*Output: 
1
*/