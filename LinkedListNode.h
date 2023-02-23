#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

template <class T>
class LinkedListNode {
public:
    LinkedListNode(const T& data);
    ~LinkedListNode();
    T data;
    LinkedListNode<T>* next;
};

#endif  // LINKEDLISTNODE_H
