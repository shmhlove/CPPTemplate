template<typename T> class Vector
{
    T* buff;
public:
    Vector() {}
    Vector(int sz, T initValue) {}
};
// user define deduction guide
Vector()->Vector<int>;

int main()
{
    Vector<int> v1(10, 3);
    Vector      v2(10, 3);  // C++ 17 부터 컴파일 가능
    Vector      v3;
}