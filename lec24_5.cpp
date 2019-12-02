//Another Cross Delegation
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;
class A {
public:
	virtual void f1() = 0;// { cout << "A" << endl; }
	virtual void f2() = 0;
};

class B : public virtual A {
public:
	void f1() { cout << " B" << endl; f2(); }
};
class C : public virtual A{
public:
	void f2() {  cout << " C" << endl; }
};

class D : public B, public C {
};

int main() {
	typedef map<vector<int>, list<vector<int>>> Map;
	using Map1 = map<vector<int>, vector<vector<int>>>;
    // two method to use typedef

	D d;
	d.f1();
	d.f2();
	cin.get();
	return 0;


}

// output:
// B
// C
// C
// because in class B::f1(), it also call function f2()

/*
cross-delegation

can f1() call f2() ?
yes but with restrictions.
you have to make sure f1() and f2() in the class base, should be pure virtual function

*/