#include <iostream>
#include "linkedList.h"
using namespace std;

template <class T>
Chain<T>::Chain()
{
    Node header = new Node();
    first = last = &header;
}

template <class T>
void Chain<T>::InsertBack(const T &e)
{ // Insert a node in end of the list
    last->link = new Node(e);
    last = last->link;
}