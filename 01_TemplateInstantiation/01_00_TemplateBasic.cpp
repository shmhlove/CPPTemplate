#define MAKE_SQUARE(T) \
T square(T a)          \
{                      \
    return a*a;        \
}                      \

MAKE_SQUARE(int)
MAKE_SQUARE(double)

int main()
{
    square(3);
    square(3.3);
}