#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class ThreeD {
public:

    int ht;
    int wid;
    int dep;
};


int main() {

    int i;
    int A[5];
    // cout << i << A[2];
    // int i;
    // if you don't use it, it will give you an error. values not initialized
    // however, container always initialize values
    vector<int> V1(5); // V1 has 5 elements
    for (int i: V1) { cout << i << " "; }
    vector<int> V2(10, 5); // V2 will have 10 elements all with the value 5
    cout << endl;
    V1.assign(6, 9); // V1 becomes to having 6 elements all with value 9
    // V1.insert(V1.begin(), 8); // before the first
    V1.insert(V1.begin() + 2, 8);
    V1.insert(V1.begin(), 3, 100); // insert 100 repeated three times
    for (int i: V1) { cout << i << " "; }

    vector<int> V3 = { 1, 2, 3, 4 }; // this syntax is only introduce for vector, not for list/map...
    vector<int> V4({1, 2, 3, 4});
    // vector<int> V4 = ({1, 2, 3, 4}); // this is wrong syntax
    vector<int> V5{1, 2, 3, 4}; // this year
    int j(5); // 20 years ago
    int k = 6; // now
    int w{8}; // this year

    int x = 5;
    // int B[x]; // it will give you compile error, because array size
    // should only be constant
    // if you put a "const" is OK like:
    // const int x = 5;

    // vector has no problem
    vector<int> V6(x, 77); // vector size could be a variable

    int C[6]{ 1,2,4 }; // 1 2 4 0 0 0 // default for int is 0
    // you also can put a equal sign, but it's not needed
    // int C[6] = { 1,2,4 };
    // this is also work
    // int C[6]({ 1,2,4 });

    int* p = new int[x] {1,2,3}; // dynamic created array you can use variable
    // this will results in 1 2 3 0 0

    vector<int *> V7(5); // it will initialize to nullptr
    // NULL carry the meaning of nullptr and 0
    // in the past, the syntax is:
    // vector<int *> V7(5, nullptr);

    if (V7[2] == nullptr) { cout << "Yes, it is initialized to nullptr" << endl; }

    ThreeD t1;
    // cout << t1.ht << endl; // error! value not initialized

    vector<ThreeD> V8(3); // vector will initialize for you
    cout << endl;
    cout << V8[1].ht << endl;



    cin.get();
    cin.get();
    return 0;
}