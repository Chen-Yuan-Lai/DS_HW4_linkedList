#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

template <class T>
class Chain
{
    class Node;

public:
    Chain();
    ~Chain();
    void InsertBack(const T &e);
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
        ChainIterator(Node *startNode = 0) : current(startNode) {}
        // deferencing operators
        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        // increment
        ChainIterator &operator++() // preincrement
        {
            current = current->link;
            return *this;
        }
        ChainIterator &operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }
        // equality testing
        bool operator!=(const ChainIterator right) const
        {
            return current != right.current;
        }
        bool operator==(const ChainIterator right) const
        {
            return current == right.current;
        }

    private:
        Node *current;
    };

private:
    class Node
    { // nested class for node
    public:
        T data;
        Node *link;
        // 0 is the defult value for element and next
        Node(T element = 0, Node *next = 0)
        {
            data = element;
            link = next;
        }
    };
    Node *first;
    Node *last;
};

#endif