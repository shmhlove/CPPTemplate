template<typename T> void foo(T& a)
{
    ++a;
}

int main()
{
    int n = 0;
    int& r = n;
    const int c = n;
    const int& cr = c;
    
    foo(n); // int          -> T : int, a : int&
    foo(r); // int&         -> T : int, a : int&
    //foo(c); // const int    -> T : int, a : const int&
    //foo(cr); // const int&  -> T : int, a : const int&???
    
    //const char* s1 = "hello";           // s1의 value가 const   --> const char*
    //foo(s1);                            // -> T : const char*, a : ??
    
    //const char* const s2 = "hello";     // s2도 const고 value도 const    --> const char*
    //foo(s2);                            // -> T : const char*, a : ??
}