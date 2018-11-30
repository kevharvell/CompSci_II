/*****************************************************************************
 * Program Name: Circular Linked List (Queue)
 * Author: Kevin Harvell
 * Date: 5/15/2018
 * Description: Circular Linked List gives some practice creating a circular
 * linked list queue, including functions that add a value to the back of a
 * queue, displaying the front in line, removing the front in line, and
 * displaying the queue's content.
*****************************************************************************/

#include "Queue.hpp"

using std::cout;
using std::endl;

Queue::Queue() {
    head = nullptr;
}

Queue::~Queue() {
    while(!isEmpty())
    {
        removeFront();
    }
}

/*************************************************************************
 * isEmpty checks to see if the queue is empty, returns true if empty,
 * false if not.
 ************************************************************************/

bool Queue::isEmpty() const {
    if(head == nullptr) {
        cout << "\nThere are no values in the queue" << endl << endl;
        return true;
    }
    else {
        return false;
    }
}

/*************************************************************************
 * addBack adds a new element to the end of the queue.
 ************************************************************************/
void Queue::addBack(int valIn) {
    // add first element to queue
    if(isEmpty())
    {
        head = new QueueNode(valIn);
        head->next = head;
        head->prev = head;
        cout << "First element added." << endl << endl;
    }
    // add second element to queue
    else if(head->next == head && head->prev == head)
    {
        head->next = new QueueNode(valIn, head, head);
        head->prev = head->next;
    }
    // add nth element to queue
    else
    {
        QueueNode* tempPtr = head->prev;
        head->prev = new QueueNode(valIn, head, tempPtr);
        tempPtr->next = head->prev;
    }
}

/*************************************************************************
 * getFront checks to see if the queue is empty, and if not, displays the
 * front value of the queue
 ************************************************************************/
int Queue::getFront() {
    // Check to see if the queue is empty
    if(!isEmpty())
    {
        return head->val;
    }
    else
    {
        return -1;
    }
}

/*************************************************************************
 * removeFront removes the first value in the queue
 ************************************************************************/
void Queue::removeFront() {
    // Set temporary head and tail pointers
    QueueNode* tempHeadPtr = nullptr;
    QueueNode* tempTailPtr = nullptr;

    // If not empty, display the front value of the queue
    if(!isEmpty()) {
        // Check to see if queue only has 1 value
        if (head->next == head && head->prev == head) {
            // Delete the one in line and set head to null
            delete head;
            head = nullptr;
        }

        // Check to see if queue only has 2 values
        else if (head->next == head->prev) {
            tempHeadPtr = head;

            // Set head to be the 2nd in line
            head = tempHeadPtr->next;
            // Delete the first in line
            delete tempHeadPtr;
            // There is only one left in the queue, so set prev and next to head
            head->prev = head;
            head->next = head;
        }

        // In all other cases, good to delete from front of queue without issues
        else {
            tempHeadPtr = head;
            tempTailPtr = head->prev;

            // Set head to be the 2nd in line
            head = tempHeadPtr->next;
            // Delete the first in line
            delete tempHeadPtr;
            // Point the new head to the tail
            head->prev = tempTailPtr;
            // Point the tail to the new head
            tempTailPtr->next = head;
        }
    }
}

/*************************************************************************
 * displayList outputs a sequence of all values currently stored in the
 * list.
 ************************************************************************/
void Queue::printQueue() const {
    // If queue is not empty, go ahead and print.
    if(!isEmpty()) {
        QueueNode *nodePtr = head;

        cout << "\nYour queue is: ";
        do {
            // Print the value in the current node
            cout << nodePtr->val << " ";
            // Move on to the next node
            nodePtr = nodePtr->next;
        } while (nodePtr != head && nodePtr != nullptr);
        cout << endl << endl;

    }
}









