#include <iostream>

using namespace std;

struct node
{
    int number;
    node *next;
};
typedef struct node *R;

R first = NULL;
R last = NULL;

void pushFila(R &row)
{
    int n;

    cout << "Specify a number: ";
    cin >> n;

    row = new node;

    row->number = n;
    row->next = NULL;

    if (first == NULL)
        last = first = row;
    else
    {
        last->next = row;
        last = row;
    }
}

void mostrarFila(R row)
{
    R aux;
    aux = first;

    if (aux == NULL)
    {
        cout << "The row is empty" << endl;
        return;
    }
    else
    {
        while (aux != NULL)
        {
            cout << aux->number << " ";
            aux = aux->next;
        }
    }
}

void popFila(R &row)
{
    if (row == NULL)
        cout << "The row is empty" << endl;
    else
    {
        first = row->next;
        row->next = NULL;
        row = first;
    }
}

int main()
{
    int opc = 0;
    R row = NULL;

    do
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Show row" << endl;
        cout << "0. Exit" << endl;
        cout << "Select an option: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            pushFila(row);
            break;

        case 2:
            popFila(row);
            break;

        case 3:
            mostrarFila(row);
            break;

        case 0:
            cout << "Exiting program. " << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}
