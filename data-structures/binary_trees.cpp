/*
    The weight on a binary tree depends on the total nodes that exist in a level

    Unorder: left, root, right
    Pre-order: root, left, right
    Post-order: left, right, root

    Methods:
        Add:
            if tree is NULL
                create new node
                left_pointer = NULL
                right_pointer = NULL

            if value is less than the tree node (root)
                add new node to the left

            if value is bigger than the tree node (root)
                add new node to the right

        Show:
            if tree is NULL
                Show a message
            else
                Show the left tree first
                Then show the right tree

*/
#include <iostream>
using namespace std;

struct nodo
{
};

int main()
{

    return 0;
}
