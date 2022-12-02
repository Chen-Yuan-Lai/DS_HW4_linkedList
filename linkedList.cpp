#include <iostream>
#include "linkedList.h"
using namespace std;

template <class T>
Chain<T>::Chain()
{
    Node *head = new Node;
    first = last = head;
}

template <class T>
Chain<T>::~Chain()
{
    Node *cur = first;
    while (cur != 0)
    {
        Node *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

template <class T>
void Chain<T>::InsertBack(const T e)
{ // Insert a node in end of the list
    last->next = new Node(e);
    last = last->next;
}

template <class T>
void Chain<T>::DeleteFront()
{ // delete a node in front of the list
    Node *temp = first->next;
    if (temp == last)
    { // the list only have one node
        last = first;
    }
    first->next = temp->next;
    delete temp;
}

template <class T>
Chain<T> Chain<T>::merge(Chain<T> &y)
{
    Chain z;

    while (first->next != 0 && y.first->next != 0)
    {
        if (first->next != 0)
        {
            z.InsertBack(first->next->data);
            DeleteFront();
        }
        if (y.first->next != 0)
        {
            z.InsertBack(y.first->next->data);
            y.DeleteFront();
        }
    }

    return z;
}
