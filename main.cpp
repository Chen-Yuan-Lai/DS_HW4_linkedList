#include <iostream>
#include "linkedList.h"
#include "linkedList.cpp"

int main()
{
    Chain<int> x;
    for (int i = 1; i <= 10; i++)
    {
        x.InsertBack(i);
    }

    cout << x << endl;

    cout << x.expr() << endl;

    // Chain<int> y;
    // y.InsertBack(3);
    // y.InsertBack(5);
    // y.InsertBack(7);
    // y.InsertBack(10);
    // y.InsertBack(10);

    // for (Chain<int>::ChainIterator i = y.begin(); i != y.end(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;

    // Chain<int> z = x.merge2(y);

    // for (Chain<int>::ChainIterator i = z.begin(); i != z.end(); i++)
    // {
    //     cout << *i << " ";
    // }

    return 0;
}