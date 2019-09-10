// g++ 04_00_TemplateTypeDeduction.cpp -Ic:\\boost_1_70_0

#include <iostream>
#include <boost\type_index.hpp>
using namespace std;
using namespace boost::typeindex;

template<typename T> void foo(const T a)
{
    // const 가 정확히 조사되지 않는다.
    cout << "standard T : " << typeid(T).name() << endl;
    cout << "standard a : " << typeid(a).name() << endl;
    
    // boost::type_index를 활용하면 정확한 타입을 조사할 수 있다.
    cout << "boost T : " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "boost a : " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

int main()
{
    foo(3);     // T : int, a : const int
    foo(3.3);   // T : double, a : const double
}