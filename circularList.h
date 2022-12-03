#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include "linkedList.h"
using namespace std;

template <class T>
class circularChain : public Chain<T>
{
public:
    circularChain();
    ~circularChain();
    void InsertBack(const T e);
    void DeleteFront();
};

#endif