#include <iostream>
#include "linkedList.h"
using namespace std;

template <class T>
Chain<T>::Chain()
{
    Node head = new Node;
    first = last = &head;
}

template <class T>
Chain<T>::~Chain()
{
    Node *cur = first;
    while (cur != 0)
    {
        Node *temp = cur;
        cur = cur->link;
        delete temp;
    }
}

template <class T>
void Chain<T>::InsertBack(const T &e)
{ // Insert a node in end of the list
    last->link = new Node(e);
    last = last->link;
}