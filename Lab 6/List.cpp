/*****************************************************************************
 * Program Name: Doubly Linked Lists
 * Author: Kevin Harvell
 * Date: 5/13/2018
 * Description: Doubly Linked Lists experiments with doubly linked lists with
 * the following functions: adding a new node to the head, adding a new node
 * to the tail, deleting the first node in a list, deleting the last node in
 * a list, and traversing the list reversely.
*****************************************************************************/

#include "List.hpp"


using std::cout;
using std::endl;

List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    // Start at head of list
    Node* nodePtr = head;
    while (nodePtr != nullptr)
    {
        // garbage keeps track of node to be deleted
        Node* garbage = nodePtr;
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        // Delete the "garbage" node
        delete garbage;
    }
}

/*************************************************************************
 * addToHead adds a new element to the beginning of the list
 ************************************************************************/
void List::addToHead(int valIn) {
    if(head == nullptr && tail == nullptr)
    {
        head = new Node(valIn, nullptr, nullptr);
        tail = head;
    }
    else
    {
        // The list is not empty
        // Use nodePtr to traverse the list
        Node* nodePtr = head;
        // Add new item to head of list
        head = new Node(valIn, nodePtr, nullptr);
        nodePtr->prev = head;
    }
}

/*************************************************************************
 * addToTail adds a new element to the end of the list
 ************************************************************************/
void List::addToTail(int valIn) {
    if(head == nullptr && tail == nullptr)
    {
        head = new Node(valIn, nullptr, nullptr);
        tail = head;
    }
    else
    {
        // The list is not empty
        // Use nodePtr to traverse the list
        Node* nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        // nodePtr->next is nullptr so nodePtr points to last node
        // Create a new node and put it after the last node
        nodePtr->next = new Node(valIn, nullptr, nodePtr);
        tail = nodePtr->next;
    }
}

/*************************************************************************
 * removeHead deletes the first item in the list.
 ************************************************************************/
void List::removeHead() {
    Node* nodePtr = head;
    if(nodePtr == nullptr)
    {
        cout << "There are no values stored in the linkedList." << endl;
    }
    else
    {
        if(nodePtr->next == nullptr && nodePtr->prev == nullptr)
        {
            delete nodePtr;
            head = nullptr;
            tail = head;
        }
        else if(nodePtr->next) {
            head = nodePtr->next;
            delete nodePtr;
            head->prev = nullptr;
        }
    }
}

/*************************************************************************
 * removeTail deletes the last item in the list.
 ************************************************************************/
void List::removeTail() {
    Node* nodePtr = tail;
    if(nodePtr == nullptr)
    {
        cout << "There are no values stored in the linkedList." << endl;
    }
    else
    {
        if(nodePtr->next == nullptr && nodePtr->prev == nullptr)
        {
            delete nodePtr;
            tail = nullptr;
            head = tail;
        }
        else if(nodePtr->prev) {
            tail = nodePtr->prev;
            delete nodePtr;
            tail->next = nullptr;
        } else {
            cout << "seg fault..." << endl;
        }
    }
}

/*************************************************************************
 * displayList outputs a sequence of all values currently stored in the
 * list.
 ************************************************************************/
void List::displayList() const {
    // Start at head of list
    Node* nodePtr = head;
    while(nodePtr != nullptr)
    {
        // Print the value in the current node
        cout << nodePtr->val << " ";
        // Move on to the next node
        nodePtr = nodePtr->next;
    }
    cout << endl << endl;
}

/*************************************************************************
 * reverseTraverse outputs a sequence of all values currently stored in the
 * list in reverse order.
 ************************************************************************/

void List::reverseTraverse() const {
    // Start at tail of list
    Node* nodePtr = tail;
    while(nodePtr != nullptr)
    {
        // Print the value in the current node
        cout << nodePtr->val << " ";
        // Move on to the next node
        nodePtr = nodePtr->prev;
    }
    cout << endl << endl;
}





