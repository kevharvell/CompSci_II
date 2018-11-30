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

#include "Character.hpp"

#include <iostream>

class List {
private:
    struct Node {
        Node* next;
        Node* prev;
        Character* character;
        Node(Character* characterIn, Node* nextIn = NULL, Node* prevIn = NULL) {
            character = characterIn;
            next = nextIn;
            prev = prevIn;
        }
    };
    Node* head;
    Node* tail;

public:
    List();
    ~List();
    bool isEmpty() const;
    void clear();
    void addToHead(Character* characterIn);
    void addToTail(Character* characterIn);
    void removeHead();
    void removeTail();
    Character* getFront();
    void displayList() const;
    void reverseTraverse() const;


};

#endif

