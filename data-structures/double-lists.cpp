
/*
Single Linked Lists
|node|n|->|node|n|->|node|n|->NULL

Doubly Linked Lists
NULL<-|a|node|n|<->|a|node|n|<->|a|node|n|->NULL

Circular Linked Lists
last-node<-|a|node|n|<->|a|node|n|<->|a|node|n|->first-node
*/

#include <iostream>

using namespace std;

struct node
{
    int number;
    node *next;     // stores the address of the next node
    node *previous; // stores the address of the previous node
    node *start;    // stores the address of the first node
};

// Abstract Data Type
typedef struct node *LD;

// Function to create each node
LD createNode(int n)
{
    LD Node = new node;
    Node->number = n;
    Node->next = NULL;
    Node->previous = NULL;

    // Node =   NULL<-|number|->NULL

    return Node;
}

// Function to create the list
LD createDoubleList()
{
    LD list = new node;
    list->start = NULL;
    return list;
}

void insertEnd(int num, LD &list)
{
    LD node = createNode(num);
    LD aux = NULL;

    if (list->start == NULL) // If the list is empty
    {
        list->start = node;
    }
    else // if it's not empty
    {
        aux = list->start;
        // Finding the last node.
        // The node that is pointing to null in its next pointer
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = node;
        node->previous = aux;
    }
}

void ShowDoubleList(LD list)
{
    LD aux = list->start;
    if (aux == NULL)
    {
        cout << endl
             << "The list is empty..." << endl;
    }
    else
    {
        cout << endl
             << "NULL <- ";
        while (aux != NULL)
        {
            cout << aux->number << " <-> ";
            aux = aux->next;
        }
        cout << "-> NULL" << endl
             << endl;
    }
}

void deleteDoubleList(LD &list)
{
    LD aux = NULL;
    while (list->start != NULL)
    {
        aux = list->start;
        list->start = aux->next;
        aux->next = NULL;
        aux->previous = NULL;
        delete (aux);
    }
}

void deleteLastNode(LD &list)
{
    LD aux = list->start;

    if (aux == NULL) // If the list is empty
    {
        cout << endl
             << "The list is empty..." << endl;
        return;
    }
    else // if it's not empty
    {
        // Finding the last node.
        // The node that is pointing to null in its next pointer
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = NULL;
        aux->previous->next = NULL;
        aux->previous = NULL;
        delete (aux);
    }
}

void deleteSpecificNode(LD &list, int opToDelete)
{
    LD aux = list->start;
    if (opToDelete == 1)
    {
        list->start = aux->next;
        list->start->previous = NULL;
        aux->next = NULL;
    }
    else
    {
        for (int i = 1; aux != NULL; i++)
        {
            if (i == opToDelete)
            { // Deletion of the node at position opToDelete
                aux->previous->next = aux->next;
                aux->next->previous = aux->previous;
            }
            aux = aux->next; // Traverse the nodes.
        }
    }
}

void deleteFirstNode(LD &list)
{
    LD aux = list->start;
    list->start = aux->next; // Move the start of the list to the second node
    list->start->previous = NULL;
    aux->next = NULL;
}

int main()
{
    LD list = createDoubleList();
    int choice, num, opToDelete;

    do
    {
        cout << endl
             << endl
             << " * * * DOUBLE LIST * * *" << endl
             << "1 Insert node at end" << endl
             << "2 Show list" << endl
             << "3 Delete list" << endl
             << "4 Delete last node" << endl
             << "5 Delete specific node" << endl
             << "6 Delete first node" << endl
             << "0 Exit" << endl
             << "Enter option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            insertEnd(num, list);
            break;
        case 2:
            ShowDoubleList(list);
            break;
        case 3:
            deleteDoubleList(list);
            break;
        case 4:
            deleteLastNode(list);
            break;
        case 5:
            cout << endl
                 << "Enter position to delete: ";
            cin >> opToDelete;
            deleteSpecificNode(list, opToDelete);
            break;
        case 6:
            deleteFirstNode(list);
            break;
        case 0:
            cout << endl
                 << "Exiting the program...";
            break;
        default:
            cout << endl
                 << "Option does not exist..." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
