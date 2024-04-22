/*
    Adecuarlo para el ejercicio de volumen de figura con herencia, colocar constructor y destructor
*/

// #include <iostream>
// using namespace std;

// template <class T>
// class Base
// {
// private:
//     T val;

// public:
//     void setVal(T a) { val = a; }
// };
// template <class T>
// class Derived : public Base<T>
// {
// public:
//     void setVal(T b) { Base<T>::setVal(b); }
// };
// int main()
// {
//     Derived<int> a;
//     a.setVal(4);
//     return 0;
// }
/*
    Integrantes:
        Leslie Lucero Franco Calleros 223053
        Santiago Mendivil Alvarez 226129
*/

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
class Figura
{
protected:
    T base;
    T altura;
    T radio;
    T PI;

public:
    Figura(T b, T a, T r)
    {
        cout << endl
             << "Figura Construida" << endl;

        base = b;
        altura = a;
        radio = r;
        PI = 3.1415926535;
    }
    virtual ~Figura()
    {
        cout << endl
             << "Figura Destruida" << endl;
    }

    virtual T calcularArea() const
    {
        return 0.0;
    }
    virtual T calcularVolumen() const
    {
        return 0.0;
    }
};

template <class T>
class Cuadrado : public Figura<T>
{
public:
    Cuadrado(T b) : Figura(b, b, 0)
    {
        cout << endl
             << "Cuadrado - Cubo Construido" << endl;
    }
    virtual ~Cuadrado()
    {
        cout << endl
             << "Cuadrado - Cubo Destruido " << endl;
    }
    T calcularArea() const
    {
        return this->base * this->altura;
    }
    T calcularVolumen() const
    {
        return pow(this->base, 3);
    }
};

template <class T>
class Circulo : public Figura<T>
{
public:
    Circulo(T r, T h) : Figura(0, h, r)
    {
        cout << endl
             << "Circulo - Cilindro Construido" << endl;
    }
    virtual ~Circulo()
    {
        cout << endl
             << "Circulo - Cilindro Destruido " << endl;
    }
    T calcularArea() const
    {
        return PI * pow(this->radio, 2);
    }
    T calcularVolumen() const
    {
        return calcularArea() * this->altura;
    }
};

template <class T>
class Triangulo : public Figura<T>
{
public:
    Triangulo(T b, T a) : Figura(b, a, 0)
    {
        cout << endl
             << "Triangulo - Piramide Construida" << endl;
    }
    virtual ~Triangulo()
    {
        cout << endl
             << "Triangulo - Piramide Destruida" << endl;
    }
    T calcularArea() const
    {
        return (this->base * this->altura) / 2;
    }
    T calcularVolumen() const
    {
        return calcularArea() * this->altura / 3;
    }
};

template <class T>
class Piramide : public Figura<T>
{
public:
    Piramide(T b, T a) : Figura(b, a, 0)
    {
        cout << endl
             << "Piramide Construida" << endl;
    }
    virtual ~Piramide()
    {
        cout << endl
             << "Piramide Destruida" << endl;
    }
    T calcularArea() const
    {
        return (this->base * this->altura) / 2;
    }
    T calcularVolumen() const
    {
        return calcularArea() * this->altura / 3;
    }
};

int main()
{
    int opc;
    float base, altura, radio;

    do
    {
        system("cls");
        cout << endl
             << "***MENU***"
             << endl
             << "1. Cuadrado - Cubo"
             << endl
             << "2. Circulo - Cilindro"
             << endl
             << "3. Triangulo - Piramide"
             << endl
             << "0. Salir"
             << endl
             << "Opcion: ";
        cin >> opc;

        if (opc == 1)
        {
            cout << endl
                 << "Ingresa un lado del cuadrado: ";
            cin >> base;

            Figura<float> *cuadrado = new Cuadrado(base);

            cout << endl
                 << "Area del cuadrado: " << cuadrado->calcularArea() << endl;
            cout << endl
                 << "Volumen del cubo: " << cuadrado->calcularVolumen() << endl;

            delete cuadrado;
            cout << endl;
            system("pause");
        }
        else if (opc == 2)
        {
            cout << endl
                 << "Ingresa el radio del circulo: ";
            cin >> radio;
            cout << endl
                 << "Ingresa la altura del cilindro: ";
            cin >> altura;

            Figura<float> *circulo = new Circulo(radio, altura);
            cout << endl
                 << "Area del circulo: " << circulo->calcularArea() << endl;
            cout << endl
                 << "Volumen del cilindro: " << circulo->calcularVolumen() << endl;

            delete circulo;
            cout << endl;
            system("pause");
        }
        else if (opc == 3)
        {
            cout << endl
                 << "Ingresa la base del triangulo: ";
            cin >> base;
            cout << endl
                 << "Ingresa la altura del triangulo: ";
            cin >> altura;

            Figura<float> *triangulo = new Triangulo(base, altura);
            cout << endl
                 << "Area del triangulo: " << triangulo->calcularArea() << endl;
            cout << endl
                 << "Volumen de la piramide: " << triangulo->calcularVolumen() << endl;

            delete triangulo;
            cout << endl;
            system("pause");
        }
        else if (opc == 0)
        {
            cout << endl
                 << "Saliendo del programa..." << endl;
        }
        else
        {
            cout << endl
                 << "Error: opcion invalida" << endl;
            cout << endl;
            system("pause");
        }

    } while (opc != 0);

    return 0;
}
