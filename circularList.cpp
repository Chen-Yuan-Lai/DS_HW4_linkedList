#include <iostream>
#include "circularList.h"
using namespace std;

template <class T>
circularChain<T>::circularChain() : Chain<T>()
{
    this->last->next = first;
}

template <class T>
circularChain<T>::~circularChain() {}

// template <class T>
// void circularChain<T>::InsertBack(const T e)
// {
//     last->next = new Node(e);
//     last = last->next;
//     last->next = first;
// }