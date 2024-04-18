/*
    Datos: int, float, char, double y manejo de constructor y destructor con letreos y anexar un friend
*/

#include <iostream>
using namespace std;

template <class T>
class Number
{
private:
    T numb;

public:
    Number(T a) : numb(a) {}
    T get() { return numb; }
};
int main()
{
    Number<int> integerNumber(50);
    Number<double> doubleNumber(8.9);
    cout << "integer Number = " << integerNumber.get() << endl;
    cout << "double Number = " << doubleNumber.get() << endl;
    return 0;
}