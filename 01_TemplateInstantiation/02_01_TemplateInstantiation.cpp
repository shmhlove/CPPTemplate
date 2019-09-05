template<typename T> class Test
{
public:
    void foo() {}
    void goo() {}
};

template<typename T> T square(T a)
{
    return a * a;
}

int main()
{
    // 아래 처럼 사용을 하면 컴파일러에 의해 암시적으로 int형으로 인스턴스화 된다.
    int n1 = square(3);
    
    // 명확히 인스턴스화
    int n2 = square<int>(3);
    
    // 클래스템플릿은 명확히 <int>를 넣어주어야한다.
    // 단, c++17부터는 <int>를 명시하지 않아도 생성자를 통해 암시적변환이 가능하다.
    Test<int> t1;
    
    // foo만 인스턴스화 한다. goo는 인스턴스화 하지 않는다.
    t1.foo();
}