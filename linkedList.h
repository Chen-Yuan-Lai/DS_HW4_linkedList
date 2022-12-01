#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

template <class T>
class Chain
{
public:
    Chain();
    void Insert(const T &e);
    // insert q node in front of the list
    void Delete(const T &e);
    // delte a node in the list
    template <typename U>
    friend ostream &operator<<(ostream &os, Chain<U> &s);

    // Forward declaration
    class ChainIterator;
    // root of linkedlist wrapped in Iterator type
    ChainIterator begin() { return ChainIterator(first); }
    // end of linkedList wrapped in Iterator type
    ChainIterator end() { return ChainIterator(0); }

    class ChainIterator
    {
    public:
        // contructor
        ChainIterator(Node *startNode = 0) : current(startNode) private : Node * current;
    }

    private : class Node
    { // nested class for node
    public:
        // 0 is the defult value for element and next
        Node() : data(0), link(0) {}
        Node(T &a) : data(a), link(0) {}

    private:
        T data;
        Node *link;
    };
    Node *first;
    Node *last;
};

#endif