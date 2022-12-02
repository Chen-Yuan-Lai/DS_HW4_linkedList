#include <iostream>
#include "linkedList.h"
#include "linkedList.cpp"

int main()
{
    Chain<int> x;
    x.InsertBack(1);
    x.InsertBack(3);
    x.InsertBack(5);
    x.InsertBack(7);
    x.InsertBack(9);
    for (Chain<int>::ChainIterator i = x.begin(); i != x.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    Chain<int> y;
    y.InsertBack(2);
    y.InsertBack(4);
    y.InsertBack(6);
    y.InsertBack(8);
    y.InsertBack(10);

    Chain<int> z = x.merge(y);

    for (Chain<int>::ChainIterator i = z.begin(); i != z.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}