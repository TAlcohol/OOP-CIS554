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
    SimpleData s2{ s1 }, s3(4, 5, 6), s4;
    // copy -- will call copy constructor
	// declare s2 and immediately copy values from s1 to s2
	// These three forms are also correct: SimpleData s2 = {s1}; SimpleData s2(s1);  SimpleData s2=s1;

    // SimpleData s2{ s1 } this is called copy(evoke copy constructor)
    // if you don't write copy constructor, every single bit is copied
    // include address in pointers
    // you can also write s2 = s1, this is assign
    // SimpleData s2 = s1, this is called copy
    s1.print(); // Will print 2 5 8
    s2.print(); // Will print 2 5 8
    *(s1.pSecond) = 50;
    *(s2.pThird) = 80;
    s1.print(); // Will print 2 50 80
    s2.print(); // Will print 2 50 80
    s4 = s3;
    // s4 = s3; this is called assign //assign -- will call operator=
    // assign is doing the same thing, copy every single bit
    s3.print(); // Will print 4 5 6
    s4.print(); // Will print 4 5 6
    *s3.pSecond = 50;
    *s4.pThird = 60;
    s3.print(); // Will print 4 50 60
    s4.print(); // Will print 4 50 60

    // above is called shallow copy and shallow assign


    // int i = 10, j = i; // ok

    cin.get();
    return 0;
}