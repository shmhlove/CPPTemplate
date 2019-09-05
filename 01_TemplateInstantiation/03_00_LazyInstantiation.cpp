#include <iostream>
using namespace std;

struct Resource1
{
    Resource1()     { cout << "Resource1()" << endl; }
    ~Resource1()    { cout << "~Resource1()" << endl; }
};

struct Resource2
{
    Resource2()     { cout << "Resource2()" << endl; }
    ~Resource2()    { cout << "~Resource2()" << endl; }
};

//struct Test
//{
//    Resource1 res1;
//    static Resource2 res2;
//};
//Resource2 Test::res2;

template<typename T> struct Test
{
    Resource1 res1;
    static Resource2 res2;
};
template<typename T> Resource2 Test<T>::res2;

int main()
{
    cout << "main" << endl;
    Test<int> t;
}