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
{ // merge two list by specific order
    Chain z;

    while (first->next != 0 || y.first->next != 0)
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

template <class T>
Chain<T> Chain<T>::merge2(Chain<T> &y)
{ // merge two nondecreasing order list and matain this order
    Chain z;

    while (first->next != 0 && y.first->next != 0)
    { // when two lists are not empty
        if (first->next->data < y.first->next->data)
        {
            z.InsertBack(first->next->data);
            DeleteFront();
        }
        else if (first->next->data > y.first->next->data)
        {
            z.InsertBack(y.first->next->data);
            y.DeleteFront();
        }
        else
        {
            z.InsertBack(first->next->data);
            DeleteFront();
            z.InsertBack(y.first->next->data);
            y.DeleteFront();
        }
    }
    while (first->next != 0)
    { // insert remaining node in *this
        z.InsertBack(first->next->data);
        DeleteFront();
    }

    while (y.first->next != 0)
    { // insert remaining node in y
        z.InsertBack(y.first->next->data);
        y.DeleteFront();
    }
    return z;
}

template <class T>
int Chain<T>::expr()
{
    int sum = 0;
    for (typename Chain<T>::ChainIterator i = begin(); i != end(); i++)
    {
        int count = 0;
        for (typename Chain<T>::ChainIterator j = i; j != end(); j++)
        {
            if (count == 5)
            {
                sum += (*i) * (*j);
                break;
            }
            count++;
        }
    }
    return sum;
}

template <class T>
ostream &operator<<(ostream &os, Chain<T> &s)
{
    for (typename Chain<T>::ChainIterator i = s.begin(); i != s.end(); i++)
    {
        os << *i << " -> ";
    }
    os << "|";
    return os;
}