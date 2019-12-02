#include <iostream>
using namespace std;

class ThreeD {
public:
	int ht;
	int wid;
	int dep;
	ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
	ThreeD() {}
};

void f1() { cout << "in Header1" << endl; }

int global_v{ 100 };
// int global_v = 100;

// some notes about struct
// struct and class is all the same, struct is public by default
// in the past, struct isn't allow data functions, now it all allow.