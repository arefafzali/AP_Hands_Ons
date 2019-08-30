#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <class T>
class Stack{
public:
	Stack(int n_):n(n_){};
	~Stack(){}
	class Iterator{
	public:
		bool has_more_elements(){return mystack.size()>x;}
		T next_element(){x++;return mystack[x];}
	private:
		friend class Stack;
		Iterator(){};
		int x=0;
	};
	void push(T x){if(mystack.size()<=n){mystack.push_back(x);topelement++;}else{cerr<<"Invalid push function"<<endl;}}
	void pop(){if(topelement>=0){mystack.pop_back();topelement--;}else{cerr<<"Invalid pop function"<<endl;}}
	void top(){cout<<mystack[topelement]<<endl;}
	void size(){cout<<mystack.size()<<endl;}
	Iterator get_iterator(){return it;}
private:
	friend class Iterator;
	int topelement=0;
	int n=0;
	Iterator it;
	vector<T> mystack;
};

