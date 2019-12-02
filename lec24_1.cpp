/*
up casting is ok
down casting is not.
for this,
raw casting and static casting will not give you error,
dynamic cast will. and give you a nullptr

down casting is not allowed because the pointer is also pointed to more memory space not for that object.

only one case dynamic casting will not give you error when you did down casting.
you just do a up casting earlier, and you do a down casting again

you will always replace static casting with dynamic casting,
and you will find a lot of error, because static casting won't give you error


dynamic casting only can change a pointer to a pointer or a reference to a reference
(when it's not allowed, if it is pointer it will give a nullptr, but
there is no same thing in reference, so if it is reference, the program will just crash.)
static casting is not that strict


*/

//Dynamic cast
//dynamic_cast<type1*>(type2*) or dynamic_cast<type1&>(type2&)
//upcasting is safe, but downcasting is not and should be avoided
#include <iostream>
using namespace std;

class ThreeD {
public:
	int ht;
	int wid;
	int dep;
};

class A {
//public:
	int A1;
protected:
	int A2;
public:
	int A3;
	A() {}
	A(int i, int j, int k): A1(i),A2(j), A3(k){}
	void f1() { cout << "A::f1" << endl; }
	virtual void f2() { cout << "A::f2" << endl; }

};
class B : public A {
	int B1;
protected:
	int B2;
public:
	int B3 = 1;
	B() {}
	B(int i1, int i2, int i3, int i4, int i5, int i6): A(i1, i2, i3), B1(i4), B2(i5), B3(i6){}
	void f3() { cout << "B::f3" << endl; }
	void f2() { cout << "B::f2" << endl; }
};

class C {
public:
	virtual void f4() {
		cout << "C::f4" << endl;
	}
};
class D : public C {
public:
	void f4() { cout << " D::f4" << endl; }
};

int main() {
	ThreeD t1{ 3,4,5 };
	A a { 1, 2, 3};
	B* p1 = dynamic_cast<B*>(&a);
	cout << "end" << endl;
	cout << p1<< endl;
	if (p1) cout << p1->B3<< endl;//exception occurs
	cout << " ******************" << endl;

	D d1;
	C* p2 = &d1;
	D* p3 = dynamic_cast<D*>(p2);//will return nullptr if p3 does not point to an object of derived class
	p3->f4();

	D& rd = d1;
	//C c2;
	C& rc = rd;
	D& rd1 = dynamic_cast<D&>(rc);//will cause exception if rc is not a ref of an object of derive class
	rd1.f4();


	cin.get();
	return 0;
}