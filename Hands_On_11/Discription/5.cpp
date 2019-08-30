// You can only change the Pointer Class
// Hint : count the number of refrences to input of the Pointer constructor
// For more information search smart pointers

#include <iostream>

using namespace std;

class Pointer
{
public:
    Pointer() = default;


    Pointer(int* _refrence)
    : refrence(_refrence)       // You can not change the refrence field constructor
    {
    }

    Pointer(const Pointer& source) = default; //    Hint : Implement this method
    Pointer& operator=(const Pointer& source) = default; //      Hint : Implement this method

    ~Pointer() //   Hint : Change this method
    {
        delete refrence;
    }

private:
    int* refrence;
};

class A
{
public:
    A()
    {
    }

    A(Pointer _p)
    {
        p = _p;
    }

private:
    Pointer p;
};

int main()
{
    A a_array[10];

    Pointer p(new int);

    for (int i = 0; i < 10; i++)
        a_array[i] = A(p);

}
