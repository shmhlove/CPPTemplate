#include <list>
using namespace std;

template<typename T> class Vector
{
    T* buff;
public:
    Vector() {}
    Vector(int sz, T initValue) {}
    template<typename C> Vector(C& c) {}
};

// user define deduction guide
Vector()->Vector<int>;

// C의 value_type 즉, C는 list<int> 형이니깐 T = int
template<typename C> Vector(C& c)->Vector<typename C::value_type>;

int main()
{
    // c++ 17 style
    list      s = {1,2,3};
    
    // template<typename C> Vector(C& c) {} 생성자를 사용, 단, T에 대한 타입추론이 없음, 해서 추론 가이드를 작성해야 함.
    Vector    v1(s);
}