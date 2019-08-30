#include "get_avg_of_vector.hpp"
#include <stdexcept>
#include <cassert>
#include <vector>
#include <cmath>

class GetAvgOfVectorTest{
public:
	void run();
private:
	void Check_All();
};

void GetAvgOfVectorTest::Check_All(){
	std::vector<int> a;
	try{
		get_avg_of_vector(a);
		assert(false);
	}catch(std::length_error){}
	int b[10]={1,1,1,1,1,1,1,1,1,1};
	for(int i=0;i<10;i++){
		a.push_back(b[i]);
	}
	assert(abs(get_avg_of_vector(a)-1.0)<pow(10,-3));
}

void GetAvgOfVectorTest::run(){
	Check_All();
}

int main(){
	GetAvgOfVectorTest i;
	i.run();
	return 0;
}