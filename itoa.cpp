#include <stdio.h>
#include <iostream>

using std::cout;

int main()
{
    char a = '7';

    int b = a-'0';

    char c = (char)a;

    int d = (int)a;

    int e = a & 0xff;

    cout << "a is " << a << ", b is " << b << ", c is " << c << ", d is " << d << ", e is " << e << std::endl;
}