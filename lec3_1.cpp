// Linked List
#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int value;
    Node() {next = nullptr;}
    Node(int i) {value = i; next = nullptr;}
};

class LinkedList {
public:
    Node* head;
    LinkedList() {head = nullptr;}
    void makeList(int m, int n);
    void printList();
    void reverse();
    void sort();
    void removeOne(int k);
};

void LinkedList::makeList(int m, int n) {
    // create a link list of m nodes with n nodes
    // values being randomly distributed in 0 .. n-1
    Node* p1;
    for (int i = 0; i < m; i++) {
        p1 = new Node(rand() % n);
        p1->next = head;
        head = p1;
    }
}

void LinkedList::printList() {
    cout << endl;
    Node* p1 = head;
    while (p1) { // you can also write: while (p1 != nullptr)
        cout << p1->value << " ";
        p1 = p1->next;
    }
}

void LinkedList::reverse() {
    if (!head || !(head->next)) return; //contains 0 and 1 node, no need to reverse
    Node* p1 = head, *p2, *p3; // p3 is for record why should p2 go next step
    p2 = p1->next;
    while (p2) {
        p3 = p2->next;
        p2->next = p1;
        if (p1 == head) p1->next = nullptr;
        p1 = p2;
        p2 = p3;
    }
    head = p1;
}

void LinkedList::sort() {
    // selection sort
    if (!head || !(head->next)) return;
    // you can't swap this two conditions in C++
    // like: if (!(head->next) || !head) return;
    // if the head is a nullptr, there is no next, the program will crash
    Node *p1 = head, *p2;
    int min;
    Node* p_min;
    while (p1) {
        min = p1->value;
        p_min = p1;
        p2 = p1->next;
        while (p2) {
            if (p2->value < min) {
                min = p2->value;
                p_min = p2;
            }
            p2 = p2->next;
        }
        p_min->value = p1->value;
        p1->value = min;
        p1 = p1->next;
    }
}

void LinkedList::removeOne(int k) {
    // if the LinkedList contains the value k, only the first one will be removed
    if (!head) return;
    Node *p1 = head, *p2;
    if (head -> value == k) { // if the first node contains value k
        head = head->next; // new head is the next node
        delete p1;
        return;
    }
    p2 = p1->next;
    while (p2) {
        if (p2->value == k) {
            p1->next = p2->next;
            delete p2;
            return;
        }
        p1 = p2;
        p2 = p2->next;
    }
}


int main() {
    LinkedList L1;
    L1.makeList(20, 30);
    L1.printList();
    L1.reverse();
    L1.printList();
    L1.sort();
    L1.printList();
    L1.removeOne(29);
    L1.removeOne(1);
    L1.removeOne(14);
    L1.printList();

    getchar();
    getchar();
    return 0;
}