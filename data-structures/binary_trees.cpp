#include <iostream>
using namespace std;

template <typename T>
void print(T arg)
{
    cout << endl
         << arg;
}

typedef struct nodo
{
    int num;
    nodo *izq, *der;
} *AB;

void insertarNodo(AB &arbol, int numero)
{
    if (arbol == NULL)
    {
        // Creamos nodo raiz
        AB Nodo = new struct nodo;

        Nodo->num = numero;
        Nodo->izq = NULL;
        Nodo->der = NULL;

        arbol = Nodo;
    }
    else if (numero < arbol->num) // Izquierda
    {
        insertarNodo(arbol->izq, numero);
    }
    else if (numero > arbol->num)
    {
        insertarNodo(arbol->der, numero);
    }
    else
    {
        print("El numero ingresado, ya existe en el arbol");
    }
}

void mostrarArbol(AB arbol, int nivel)
{
    if (arbol == NULL)
        return;

    mostrarArbol(arbol->der, nivel + 1);

    for (int i = 0; i < nivel; i++)
    {
        cout << "\t";
    }

    cout << arbol->num << endl;

    mostrarArbol(arbol->izq, nivel + 1);
}

void recorridoInorden(AB arbol) // IZQ - RAIZ- DER
{
    if (arbol != NULL)
    {
        recorridoInorden(arbol->izq);
        cout << arbol->num << " ";
        recorridoInorden(arbol->der);
    }
    else
        return;
}

void recorridoPreorden(AB arbol) // RAIZ - IZQ - DER
{
    if (arbol != NULL)
    {
        cout << arbol->num << " ";
        recorridoPreorden(arbol->izq);
        recorridoPreorden(arbol->der);
    }
    else
        return;
}

void recorridoPostorden(AB arbol) // IZQ - DER - RAIZ
{
    if (arbol != NULL)
    {
        recorridoPostorden(arbol->izq);
        recorridoPostorden(arbol->der);
        cout << arbol->num << " ";
    }
    else
        return;
}

void recorridosProfundidad(AB arbol)
{
    print("Recorrido Inorden: ");
    recorridoInorden(arbol);

    print("Recorrido Preorden: ");
    recorridoPreorden(arbol);

    print("Recorrido Postorden: ");
    recorridoPostorden(arbol);
}

int main()
{
    int opc, numero;
    AB arbol = NULL;

    do
    {
        print("Arbol binario");
        print("1. Insertar el nodo");
        print("2. Mostrar el arbol jerarquico");
        print("3. Mostrar el arbol plano");
        print("4. Mostrar los recorridos");
        print("0 Salir");
        print("Opcion: ");
        cin >> opc;

        switch (opc)
        {
        case 1:
            print("Ingresa el numero: ");
            cin >> numero;
            insertarNodo(arbol, numero);
            break;

        case 2:
            mostrarArbol(arbol, 0); // 0 Es para los niveles
            break;

        case 3:
            recorridoInorden(arbol);
            break;

        case 4:
            recorridosProfundidad(arbol);
            break;

        case 0:
            print("Saliendo del programa.");
            break;

        default:
            break;
        }

    } while (opc != 0);

    return 0;
}
