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
    // insert q node in front of the list
    void InsertBack(const T e);
    // delte a node in end of the list
    void DeleteFront();
    // Exercise 4 of Chapter 4.2
    Chain merge(Chain &y);
    // Exercise 5 of Chapter 4.2
    Chain merge2(Chain &y);

    // Exercise 4 of Chapter 4.3
    int expr();

    // Forward declaration
    class ChainIterator;
    // root of linkedlist wrapped in Iterator type
    ChainIterator begin() { return ChainIterator(first->next); }
    // end of linkedList wrapped in Iterator type
    ChainIterator end() { return ChainIterator(0); }

    template <typename U>
    friend ostream &operator<<(ostream &os, Chain<U> &s);

    class ChainIterator
    {
    public:
        // contructor
        ChainIterator(Node *startNode = 0) : current(startNode){};
        // deferencing operators
        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        // increment
        ChainIterator &operator++() // preincrement
        {
            current = current->next;
            return *this;
        }
        ChainIterator operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->next;
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

protected:
    class Node
    { // nested class for node
    public:
        // 0 is the defult value for element and next
        Node(T element = 0) : data(element), next(0){};
        T data;
        Node *next;
    };
    Node *first;
    Node *last;
};

#endif