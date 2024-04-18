/*
    Adecuarlo para el ejercicio de volumen de figura con herencia, colocar constructor y destructor
*/

#include <iostream>
using namespace std;

template <class T>
class Base
{
private:
    T val;

public:
    void setVal(T a) { val = a; }
};
template <class T>
class Derived : public Base<T>
{
public:
    void setVal(T b) { Base<T>::setVal(b); }
};
int main()
{
    Derived<int> a;
    a.setVal(4);
    return 0;
}