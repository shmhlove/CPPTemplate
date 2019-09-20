template<typename T> class Complex
{
    T re, im;
public:
    // 1. 템플릿의 디폴트 초기화
    // c++ 98/03
    Complex(T a = T(), T b = T()) : re(a), im(b) {}
    // c++ 11
    // Complex(T a = {}, T b = {}) : re(a), im(b) {}
    
    T getReal() const;
    
    static int cnt;
    
    template<typename U> T func(const U& c);
};

// 2. 멤버함수를 외부구현 형태
template<typename T>
T Complex<T>::getReal() const
{
    return re;
}

// 3. static 멤버의 외부선언 형태
template<typename T>
int Complex<T>::cnt = 0;

// 4. 클래스 템플릿의 멤버함수 템플릿 외부구현 형태
template<typename T> template<typename U>
T Complex<T>::func(const U& c)
{
    return re;
}

int main()
{
    Complex<int> c;
    c.func(0.1);
    c.func<double>(0.1);
}