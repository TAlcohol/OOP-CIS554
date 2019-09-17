#include <iostream>
using namespace std;

int main(){
    /*
    int i, j;
    cout << " input i and j" << endl;
    cin >> i >> j;

    cout << "i = " << i << " j = " << j << endl;

    char c;
    cin >> c;
    */

    // Pointers
    int k = 10, q = 15;
    int* p1; // p1 is a pointer which carries the address of an int variable
    p1 = &k;
    cout << *p1 << " " << k << endl;
    // * is a function which returns the value stored at the address

    // array
    int A[5] = { 1,2,3,4,5 };
    cout << *A << endl;
    // array name without index is the address of its first element
    // A is the same as &A[0]
    // *A is the same as A[0]

    cout << *(A + 2) << endl; // the same as cout << A[2]
    cout << 2[A] << endl; // both A[2] and 2[A] with be converted to *(A + 2)
    // address arithmetics are logical rather than physical

    // cout << A[8] << endl;
    // c++ won't check for out-of-bound error, java and python will check this

    // dynamic memory allocation
    int *p2;
    p2 = new int(100); // new is a function which asks system to create
    // a storage space and returns the address of this memory space
    // whatever objects created by new are global objects
    // it applys to every scope, it's a global object
    // others are local objects, when function(scope) ends, it will be removed

    delete p2; // return the object pointed by p2 to the system
    // p2 is still there, but you can't cout it, but you still can use it,
    // like:
    p2 = A + 1;
    // now p2 you can't use delete to delete it, it's a local one
    // because only dynamic created can be deleted by "delete"

    p2 = new int[10];
    p2[3] = 25;
    cout << *(p2 + 3) << " " << p2[3] << endl;
    int i1 = *(p2 +3); // i1 will be 25
    *(p2 +3) = 10000;

    delete[] p2; // delete the entire array, if you only write "delete p2"
    // you only delete the first element

    p2 = A;




    getchar(); // 两个这个 getchar,防止 program 自动结束关闭，可以等你再输入点东西
    getchar();

    return 0;
}