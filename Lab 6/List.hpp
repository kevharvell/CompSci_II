/*****************************************************************************
 * Program Name: Doubly Linked Lists
 * Author: Kevin Harvell
 * Date: 5/13/2018
 * Description: Doubly Linked Lists experiments with doubly linked lists with
 * the following functions: adding a new node to the head, adding a new node
 * to the tail, deleting the first node in a list, deleting the last node in
 * a list, and traversing the list reversely.
*****************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List {
private:
    struct Node {
        Node* next;
        Node* prev;
        int val;
        Node(int valIn, Node* nextIn = NULL, Node* prevIn = NULL) {
            val = valIn;
            next = nextIn;
            prev = prevIn;
        }
    };
    Node* head;
    Node* tail;

public:
    List();
    ~List();
    void addToHead(int input);
    void addToTail(int);
    void removeHead();
    void removeTail();
    void displayList() const;
    void reverseTraverse() const;
};

#endif

