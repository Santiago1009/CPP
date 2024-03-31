#include <iostream>

using namespace std;

struct node
{
    int number;
    node *next;
};

// Abstract Data Type
typedef node *P;

void push(int num, P &stack)
{
    P aux;
    // aux.number
    aux = new node;
    aux->number = num;
    aux->next = stack;
    stack = aux;
}

void show(P stack)
{
    P aux;
    aux = stack;

    while (aux != NULL)
    {
        cout << endl
             << aux->number << endl;
        aux = aux->next;
    }
}

int pop(P &stack)
{
    int temp;
    P aux;
    aux = stack;
    temp = aux->number;
    stack = aux->next;
    delete (aux);
    return temp;
}

int main()
{
    P stack = NULL;

    int choice, num;

    do
    {
        cout << "Stack Menu" << endl
             << endl
             << "1 Push" << endl
             << "2 Pop" << endl
             << "3 Show stack" << endl
             << "0 Exit" << endl
             << "Enter an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl
                 << "Enter a number: ";
            cin >> num;
            push(num, stack);
            break;
        case 2:
            num = pop(stack);
            cout << endl
                 << "The node was removed: " << num << endl;
            break;
        case 3:
            if (stack != NULL)
                show(stack);
            else
                cout << endl
                     << "The stack is empty" << endl;
            break;
        case 0:
            break;
        default:
            cout << endl
                 << "The option does not exist";
            break;
        }
    } while (choice != 0);

    return 0;
}
