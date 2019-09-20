template<typename T> class Complex
{
    T re, im;
public:
    Complex(T a = T(), T b = T()) : re(a), im(b) { }
    // 디폴트 복사 생성자
    // Complex(const Complex<T>& c) { }
    
    // 복사 생성자 특수화
    // Complex(const Complex<int>& c) { }
    
    // 복사 생성자 일반화
    template<typename U>
    Complex(const Complex<U>& c);
    
    // 모든 타입의 Complex 클래스에 private 멤버로 접근할 수 있도록 friend 선언
    template<typename> friend class Complex;
};

template<typename T> template<typename U>
Complex<T>::Complex(const Complex<U>& c) : re(c.re), im(c.im)
{

}
    
int main()
{
    Complex<int> c1(1, 1);
    Complex<int> c2 = c1;       // ok, 디폴트 복사생성자
    Complex<double> c3 = c1;    // error, 다른클래스임. 복사생성자 특수화 혹은 일반화 필요
}