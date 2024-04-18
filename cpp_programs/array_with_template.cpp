/*
    Datos: int, float, char, double y tamaño del arreglo N(1-20)
*/

#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
void sortArray(T arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
        for (int j = s - 1; i < j; j--)
            if (arr[j] < arr[j - 1])
            {
                int var = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = var;
            }

    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class T>
void mostrarArreglos(T arr[], int s)
{
    cout << endl
         << "Arreglo de " << typeid(arr).name() << " en desorden: ";

    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";

    cout << endl
         << "Arreglo de " << typeid(arr).name() << " en orden: ";
    sortArray(arr, s);
}

int main()
{
    int a[5] = {10, 50, 30, 40, 20};
    float b[5] = {10.5, 2.3, 10.8, 20.57, 10.4};
    char c[5] = {'a', 'A', 'R', 'G', 'f'};
    double d[5] = {10.35462, 12.5357, 104.2435, 10.4356, 34.5555};
    int n = 5;

    cout << endl
         << "Pi = Entero" << endl
         << "Pf = Flotante" << endl
         << "Pc = Caracter" << endl
         << "Pd = Double" << endl;

    mostrarArreglos(a, n);
    mostrarArreglos(b, n);
    mostrarArreglos(c, n);
    mostrarArreglos(d, n);

    return 0;
}
