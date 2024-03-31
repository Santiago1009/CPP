/*Circular List*/

#include <iostream>

using namespace std;

struct node
{
    int num;
    node *previous;
    node *next;
};

// ADT
typedef node *CL;

// Anchor pointers
CL first = NULL, last = NULL;

void insertNodeAtEnd()
{
    node *new_node = new node();
    cout << endl
         << "Enter a number: ";
    cin >> new_node->num;

    if (first == NULL) // List is empty
    {
        first = new_node;
        last = new_node;
        first->next = first;
        first->previous = last;
    }
    else
    {
        last->next = new_node;
        new_node->next = first;
        new_node->previous = last;
        last = new_node;
        first->previous = last;
    }
}

void DisplayListF_L()
{
    node *current = new node();
    current = first;
    cout << endl
         << endl;
    if (first != NULL)
    {
        do
        {
            cout << current->num << " -> ";
            current = current->next;
        } while (current != first);
    }
    else
    {
        cout << endl
             << "The list is empty..." << endl;
    }
}

void DisplayListL_F()
{
    CL current = new node();
    current = last;
    cout << endl
         << "List from last to first";
    if (last != NULL)
    {
        do
        {
            cout << "<-" << current->num;
            current = current->previous;
        } while (current != last);
    }
    else
    {
        cout << endl
             << "The list is empty...";
    }
}

int main()
{
    int choice;
    do
    {
        cout << endl
             << "1 Insert at end" << endl
             << "2 Display list (First-Last)" << endl
             << "3 Display list (Last-First)" << endl
             << "0 Exit" << endl
             << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertNodeAtEnd();
            break;
        case 2:
            DisplayListF_L();
            break;
        case 3:
            DisplayListL_F();
            break;
        case 0:
            cout << endl
                 << "Exiting program" << endl;
            break;
        default:
            cout << endl
                 << "Option does not exist..." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
