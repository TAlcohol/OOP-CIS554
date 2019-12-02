// type casting

#include <iostream>
#include <string>
using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
    operator int() {return ht+wid+dep;}
    operator string() {return "THis is funny!";}
};

int main() {
    short s = 21;
    int i = s;
    // int i = （int) s; // you can also do this, convert short to int
    int j = static_cast<int>(s); // it's more safer. it will check some problem
    // the original one won't check.

    short *p1 = new short(11);
    short *p2 = new short(12);

    int *p3 = (int *)p1; // it won't give you error
    // int *p4 = static_cast<int*>(p1); // it will give you error
    // static_cast is similar to raw type casting
    // that C++ inherits from C
    // However, it is safer
    //static_cast is only performed during compile time

    ThreeD t1{ 3, 4, 5 };
    int m = t1;
    cout << m << endl; // output 12
    cout << static_cast<string>(t1) << endl; // output THis is funny!

    //type casting during run time
	//dynamic_cast


    cin.get();
    return 0;
}