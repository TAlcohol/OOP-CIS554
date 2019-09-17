// call by value, call by reference
#include <iostream>
using namespace std;

void F1(int i) {i++;} // call by value
// a new copy is created and used inside the function

void F2(int& i) {i++;} // call by reference
// The original object is used inside the function
// No new copy is created.

// array argument only supports call by reference
void F3(int A[]) // void F3(int *A) is the same, A is a pointer to integer
{
    for (int i = 0; i < 5; i++) A[i]++;
}


int main() {
    int a = 10;
    F1(a);
    cout << a << endl;
    F2(a);
    cout << a << endl;

    int B[5] = { 0,1,2,3,4 };
    F3(B);
    for (int i = 0; i < 5; i++){
        cout << B[i] << endl;
    }

    // same way
    // it will go through all the array elements and print it out
    for (int i: B) {cout << i << endl;}

    // it could be more powerful
    for (int i : B) {i++;}
    for (int i: B) {cout << i << endl;}
    // it won't add, because it's call by value!

    // this is call by reference!
    for (int &i : B) {i++;}
    for (int i: B) {cout << i << endl;}

    getchar();
    getchar();
    return 0;
}