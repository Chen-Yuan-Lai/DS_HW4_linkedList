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

private:
    class Node
    { // nested class
    public:
        Node(int element = 0, Node *next = 0)
        { // 0 is the defult value for element and next
            data = element;
            link = next;
        }

    private:
        T data;
        Node *link;
    };
    Node *first;
};

#endif