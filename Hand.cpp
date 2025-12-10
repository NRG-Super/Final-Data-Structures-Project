#include "Hand.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Constructor initializes empty list
Hand::Hand() : head(nullptr) {}

//Destructor frees all allocated nodes
Hand::~Hand() {
    clear();
}

//Adds a card to the end of the linked list
void Hand::addCard(const Card& c) {
    Node* newNode = new Node(c);

    //If list emptry, new node becomes head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    //Traverse to end of list
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}

//Compute score with Ace logic
int Hand::getScore() const {
    int total = 0;
    int aceCount = 0;

    Node* curr = head;
    while (curr != nullptr) {
        total += curr->data.getValue();
        if (curr->data.isAce()) aceCount++;
        curr = curr->next;
    }

    //Adjust Ace values if necessary
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

//Removes all nodes from the linked list
void Hand::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}

void Hand::sortDescending() {
    if (!head || !head->next) return;   //0 or 1 element

    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->data.getValue() < curr->next->data.getValue()) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

//Display cards, hide 2nd dealer card if required
void Hand::showHand(bool showAll) const {
    Node* curr = head;
    int index = 0;

    while (curr != nullptr) {
        if (!showAll && index == 1)
            cout << "[ ? ]";
        else 
            cout << "[" << curr->data.toString() << "] ";

        curr = curr->next;
        index++;
    }

    if (showAll)
        cout << "(Score: " << getScore() << ")";

    cout << endl;
}

