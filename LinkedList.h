#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void pushFront(const T& data);
    void pushBack(const T& data);
    bool remove(const T& data);
    bool isEmpty() const;
    int size() const;
    void clear();

private:
    LinkedListNode<T>* head;
    int count;
};

#endif  // LINKEDLIST_H
