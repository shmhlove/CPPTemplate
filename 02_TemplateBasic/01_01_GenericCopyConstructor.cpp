template<typename T> class Complex
{
    T re, im;
public:
    Complex(T a = T(), T b = T()) : re(a), im(b) { }
    
    // 복사 생성자 특수화
    Complex(const Complex<int> &c) { }
};

int main()
{
    Complex<int> c1(1, 1);
    Complex<int> c2 = c1;
    Complex<double> c3 = c1;    // error, 다른클래스임. 복사생성자 특수화 필요
}