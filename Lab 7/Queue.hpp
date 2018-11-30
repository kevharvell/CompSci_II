/*****************************************************************************
 * Program Name: Circular Linked List (Queue)
 * Author: Kevin Harvell
 * Date: 5/15/2018
 * Description: Circular Linked List gives some practice creating a circular
 * linked list queue, including functions that add a value to the back of a
 * queue, displaying the front in line, removing the front in line, and
 * displaying the queue's content.
*****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
private:
    struct QueueNode {
        QueueNode* next;
        QueueNode* prev;
        int val;
        QueueNode(int valIn, QueueNode* nextIn = NULL, QueueNode* prevIn = NULL) {
            val = valIn;
            next = nextIn;
            prev = prevIn;
        }
    };
    QueueNode* head;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void addBack(int);
    int getFront();
    void removeFront();
    void printQueue() const;
};

#endif

