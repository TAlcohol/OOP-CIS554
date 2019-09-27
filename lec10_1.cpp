// copy and move constructor
// Shallow copy and shallow assign
#include <iostream>
using namespace std;

class SimpleData {
public:
    int first;
    int *pSecond;
    int *pThird;
    SimpleData() {pSecond = pThird = nullptr;}
    SimpleData(int i1, int i2, int i3) { first = i1; pSecond = new int{i2}; pThird = new int{i3}; }
    void print() { cout << first << " " << *pSecond << " " << *pThird << endl; }
};

int main() {
    SimpleData s1(2, 3, 4);
    SimpleData s2{ s1 }, s3(5, 6, 7), s4;
    // SimpleData s2{ s1 } this is called copy(evoke copy constructor)
    // if you don't write copy constructor, every single bit is copied
    // include address in pointers
    // you can also write s2 = s1, this is assign
    // SimpleData s2 = s1, this is called copy
    s1.print();
    s2.print();
    *s1.pSecond = 30;
    *s2.pThird = 40;
    s1.print();
    s2.print();
    s4 = s3;
    // s4 = s3; this is called assign
    // assign is doing the same thing, copy every single bit
    s3.print();
    s4.print();
    *s3.pSecond = 30;
    *s4.pThird = 40;
    s3.print();
    s4.print();

    // above is called shallow copy and shallow assign


    // int i = 10, j = i; // ok

    cin.get();
    return 0;
}