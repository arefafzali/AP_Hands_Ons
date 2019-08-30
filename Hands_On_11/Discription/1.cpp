#include <iostream>

using namespace std;

class Node 
{
public:
	Node(int degree, int maxPossibleDegree)
	{
		this->nodeData = new int[2];
		if(degree > maxPossibleDegree)
			throw 1;
		else
		{
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
	int* firstData = new int[2];
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

	delete[] firstData;
	delete[] secondData;
}
/*Output: 
1
*/