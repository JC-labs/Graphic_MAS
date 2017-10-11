#include "Data.h"

Data::Data() : t(0), n(0.0), s('\0'), f("\0\0\0"), b(0)
{
}

Data::Data(int i) : t(1), n(i), s('\0'), f("\0\0\0"), b(0)
{
}

Data::Data(double d) : t(1), n(d), s('\0'), f("\0\0\0"), b(0)
{
}

Data::Data(char c) : t(2), n(0), s(c), f("\0\0\0"), b(0)
{
}

Data::Data(char c, char) : t(3), n(0), s('\0'), f("\0\0\0"), b(0)
{
}

Data::Data(char c, int i) : t(4), n(0), s('\0'), f("\0\0\0"), b(i)
{
}

Data::Data(int i, char c) : t(5), n(0), s('\0'), f("\0\0\0"), b(i)
{
}

Data::Data(string str) : t(6), n(0), s('\0'), f(str), b(0)
{
}

Data::Data(char* str) : t(6), n(0), s('\0'), b(0)
{
    f = static_cast<string>(str);
}

Data::Data(string str, double a) : t(7), n(a), s('\0'), f(str), b(0)
{
}

Data::Data(char* str, double a) : t(7), n(a), s('\0'), b(0)
{
    f = static_cast<string>(str);
}

int Data::T()
{
    return t;
}

int Data::B()
{
    return b;
}

double Data::N()
{
    return n;
}

char Data::S()
{
    return s;
}

string Data::F()
{
    return f;
}

void Data::sN(double dd)
{
    t = 1;
    n = dd;
}

void Data::sS(char cc)
{
    t = 2;
    s = cc;
}

void Data::sF(string ss)
{
    t = 6;
    f = ss;
}
