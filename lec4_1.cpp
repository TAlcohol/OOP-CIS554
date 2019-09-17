// Operator Overloading
#include <iostream>
using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
    int getArea() { return ht * wid * dep; }
    ThreeD operator+(const ThreeD &t) const;
    // the last "const", used to protect the first element, the one in the
    // parentheses, is protecting the second element
    // ThreeD operator*(const ThreeD &); // you can do it in a similar way
    ThreeD operator++(); // pre_fix
    ThreeD operator++(int neverUsed); // post_fix, this variable is just for Compiler to tell post
    int& operator[](int k); // return by reference


    // our case, all members are public, if not, we want external function could
    // access these members, we add these func here and add "friend"
    // like:
    // friend istream& operator>>(istream &str, ThreeD &t);
    // friend ostream& operator<<(ostream &str, const ThreeD &t);
};

int& ThreeD::operator[](int k) { // return by reference will allow a
    // function to appear on the left hand side of a statement
    // which is necessary for []. See the main function
    switch (k)
    {
    case 0: return ht;
    case 1: return wid;
    case 2: return dep;
    }
}


ThreeD ThreeD::operator++() { // pre_fix
    ++ht;
    ++wid;
    ++dep;
    return *this; // this is a pointer pointing to the current object (p1)
}

ThreeD ThreeD::operator++(int neverUsed) { // post_fix
    ThreeD temp = *this;
    ht++;
    wid++;
    dep++;
    return temp;
} // you can define, each time increment 2 times, anything you like


ThreeD ThreeD::operator+(const ThreeD &t) const{
    ThreeD temp;
    temp.ht = ht + t.ht;
    temp.wid = wid + t.wid;
    temp.dep = dep + t.dep;
    return temp;
}

istream& operator>>(istream &str, ThreeD &t) {
// return value
// return reference is return object, you can put it on the left hand side
// like f1(85) = 125
// but 85 = 125 is wrong

    str >> t.ht >> t.wid >> t.dep;
    return str;
}

ostream& operator<<(ostream &str, const ThreeD &t) {
    // we have a const here, because for output, we don't want to modify it
    // return by reference and call by reference, so we use the same buffer
    str << "(" << t.ht << "," << t.wid << "," << t.dep << ")";
    return str;
}



int main() {

    ThreeD t1(3,4,5), t2(10,20,30), t3, t4;
    t3 = t1 + t2;
    // Compiler will convert this into
    // t3 = t1.operator+(t2);
    // This explains why only one argument for the function

    // increment
    t1++; // post_fix
    t3 = ++t1; // pre_fix

    // cout << t3[1] << endl;

    // overload input and output
    cin >> t4;
    cout << t4 << endl;

    t4[1] = 100; // Note that return by reference allows t4[1] to appear
    // on the left hand side of a statement
    // return by reference is returning a object/variable, not a value
    cout << t4[2] << endl;
    cout << t4 << endl;

    getchar();
    getchar();
    return 0;
}