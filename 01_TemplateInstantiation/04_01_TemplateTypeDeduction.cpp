template<typename T> void foo(T a)
{
    ++a;
}

int main()
{
    int n = 0;
    int& r = n;
    const int c = n;
    const int& cr = c;
    
    // 템플릿 타입추론 규칙1 : 인자가 가진 const 속성만 제거 된다. 즉, point일 경우 point 변수 자체 속성만 제거 된다.
    
    foo(n); // int          -> int
    foo(r); // int&         -> int
    foo(c); // const int    -> int
    foo(cr); // const int&  -> int
    
    const char* s1 = "hello";       // s1의 value가 const   --> const char*
    foo(s1);
    
    const char* const s2 = "hello"; // s2도 const고 value도 const    --> const char*
    foo(s2);
}