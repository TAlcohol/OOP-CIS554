// <> for system file
// "" for user created file

// incremental compilation
// one file has been modified, only need to recompile it.
// it's much faster

#include <iostream>
#include "Header1.h"
#include <vector>
#include <list>
using namespace std;

// you return const reference
const int& f3{};
// return by reference is faster than return by value
// usually, you return reference, the value can be put on both left/right hand side
// but if you put const, you don't want it to be modified, it's read-only
// it's a right hand side value, is a R-value


int main() {
    ThreeD t1{ 3,4,5 }; // new feature, although you have no constuctor,
    // it will put in one by one
    f1();
    typedef vector<list<int>> vl;
    // some compiler you can change "typedef" to "using"

    int A[] = { 1, 2, 3, 4, 5 };
    cout << sizeof(A) / sizeof(int);
    // sizeof(A) exactly how many byte
    // sizeof(int) how many byte for int

    const int* p1 = new (int){5};
    int const* p2 = new (int){10};
    // these two are the same
    // means the object pointed by pointer is const, you can't modify it
    // *p1 = 20; // error
    // p1++; //OK, because pointer is not const

    int* const p3 = new (int){20};
    // only pointer is const, object is not const
    // *p3 = 100; // OK
    // p3++; // error

    // weird
    // you can not change *p6
    int w = 66;
    const int* p6 = &w;
    // *p6 = 21; // error
    // w++; // OK


    const int* const p4 = new (int){31};


    cin.get();
    return 0;
}