#include "Triangle.hpp"
#include <cassert>
#include <stdexcept>

class TriangleTest{
public:
	void run();
private:
	void Check_Constructor();
	void Check_get_perimeter();
	void Check_get_area();
	void Check_get_kind();
};

void TriangleTest::Check_Constructor(){
	try{
		Triangle t(2,2,5);
		Triangle t1(0,0,0);
		Triangle t2(-2,-3,-5);
		Triangle t3(3,4,5);
		assert(false);
	}catch(std::invalid_argument){}
}

void TriangleTest::Check_get_perimeter(){
	Triangle t(2,2,2);
	assert(t.get_perimeter()==6);
}

void TriangleTest::Check_get_area(){
	Triangle t(3,4,5);
	assert(t.get_area()==6);
}

// void TriangleTest::Check_isosceles(){
// 	Triangle t(2,3,4);
// 	assert(t.get_kind()==Triangle::Kind::ISOSCELES);
// }

void TriangleTest::Check_get_kind(){
	Triangle t1(2,2,2);
	assert(t1.get_kind()==Triangle::Kind::EQUILATERAL);
	Triangle t2(2,2,3);
	assert(t2.get_kind()==Triangle::Kind::ISOSCELES);
	Triangle t3(2,4,3);
	assert(t3.get_kind()==Triangle::Kind::SCALENE);
}
void TriangleTest::run(){
	Check_Constructor();
	Check_get_kind();
	Check_get_area();
	Check_get_perimeter();
}

int main(){
	TriangleTest test;
	test.run();
	return 0;
}