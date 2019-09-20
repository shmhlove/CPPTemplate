#include <iostream>
#include <boost\type_index.hpp>
using namespace std;
using namespace boost::typeindex;

template<typename T> void foo(const T& a)
{
    cout << "foo boost T : " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "foo boost a : " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

template<typename T> void goo(T&& a)
{
    cout << "goo boost T : " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "goo boost a : " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

int main()
{
    int n = 0;
    int& r = n;
    const int c = n;
    const int& cr = c;
    const int* p = &n;
    
    foo(n);                             // int          -> T : int,        a : const int&
    foo(r);                             // int&         -> T : int,        a : const int&
    foo(c);                             // const int    -> T : int,        a : const int&
    foo(cr);                            // const int&   -> T : int,        a : const int&
    foo(p);                             // const int*   -> T : const int*, a : const int* const&
    
    const char* s1 = "hello";           // const char*  -> T : const char*, a : const char* const&
    foo(s1);
    
    const char* const s2 = "hello";     // const char* const -> T : const char*, a : const char* const&
    foo(s2);
    
    const char* &s3 = s1;
    foo(s3);                            // const char* & -> T : const char*, a : const char* const &
    
    goo(n);                             // int -> T : int&, a : int&
    goo(cr);                            // const int& -> T : const int&, a : const int&
}