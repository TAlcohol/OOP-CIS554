// linked list

#include <iostream>
using namespace std;

class ThreeD // user defined data type
{
public:
    int ht;
    int wid;
    int dep;

    // constructor
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
    int GetArea() { return ht*wid*dep; }

};

class node
{
public:
    node *next;
    int value;
    node() { next = nullptr; }
    node(int i) { value = i; next = nullptr; }

};

class linked_list
{
public:
    node *head;
    linked_list() { head = nullptr; }

    void MakeList(int m, int n) {
        for (int i = 0; i < m; i++) {
            node *p1 = new node (rand() %n);
            p1->next = head;
            head = p1;
        }
    } // 一个一个node往前面加


};

int main()
{
    int i  = 10; // int is a system defined data type

    ThreeD j;
    cout << j.ht << " " << j.wid << " " << j.dep << " " << j.GetArea() << endl;
    ThreeD k(3,4,5);
    cout << k.ht << " " << k.wid << " " << k.dep << " " << k.GetArea() << endl;

    // int *p = &i, w1, w2; // p is a pointer, w1 and w2 are int variables initialized
    int *p = &i, w1, *w2; // p and w2 are pointers, and w1 is an int variable
    ThreeD *p1 = &k;

    cout << (*p1).GetArea() << endl; // *p1 is the same as k
    cout << p1->GetArea() << endl; // -> is pronounced as select





    getchar();
    getchar();
    return 0;
}