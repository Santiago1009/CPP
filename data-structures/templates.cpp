/*
    STL: Standard Template Library
*/
#include <iostream>
using namespace std;

template <class T>
T bigger(T data1, T data2)
{
    return (data1 > data2 ? data1 : data2);
}

int main()
{
    int a = 5, b = 7, n;
    float c = 2, d = 4, m;

    n = bigger(a, b);
    m = bigger(c, d);

    cout << endl
         << "Bigger integer number: " << n << endl;
    cout << endl
         << "Bigger floating number: " << m << endl;

    return 0;
}
