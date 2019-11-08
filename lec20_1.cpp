// SmartPointers: get, unique, swap, UseCount

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// use smart pointers you need to include <memory>

using namespace std;

int main() {

	// raw pointers doesn't contribute to ref count
    int * p1 = new int(10);
    shared_ptr<int> sp1(p1);//object 10 has a ref count = 1
    sp1.reset(new int(20));//object 10 will be deleted even though it was
    // pointed by p1; p1 in this case behaves like a weak_ptr

	shared_ptr<int> sp2(new int(100));
    shared_ptr<int> sp3 = make_shared<int>(100);//this is faster than the above
    int * p2 = new int(50);
    shared_ptr<int> sp4(p2);
    if (sp4.get() == p2) cout << "p2 and sp4 point to the same objet" << endl;
	// you can't compare smart pointers to raw pointers
	// only using get()
    // get() return the raw address
	// compare shared_ptr and weak_ptr, use cast
    cout << *p2 << " " << *sp4 << endl;
    shared_ptr<int> sp5 = sp4;
    cout << sp5.use_count() << endl;//use_count() return ref count

	cout << boolalpha << sp5.unique() << endl;
	sp4.reset();
	// you can also use sp4 = nullptr
	// but using smart pointers, you don't have to use nullptr, use reset() instead
	cout << noboolalpha << sp5.unique() << endl;
	//unique() return true if ref count is 1;otherwise, false
	//boolalpha and noboolalpha are flags which set printing mode
	//for boolean value.
	//boolalpha will have boolean values be printed as true or false
	//noboolalpha will have boolean values be printed as 1 or 0

	shared_ptr<int> sp6 = make_shared<int>(44);
	shared_ptr<int> sp7 = make_shared<int>(55);
	sp7.swap(sp6);
	cout << *sp6 << " " << *sp7 << endl;

	int * p10 = new int(25);
	int * p11 = new int(35);
	swap(p10, p11);
	swap(sp6, sp7);//slower than sp6.swap(sp7);
	// sp7.swap(sp6);
	// swap(sp6, sp7); // before above, system have this function for you
	// they have the same result, but the first one is faster
	// member function is always faster than independent function
	// because it is better optimized for specific senario


	cout << *p10 << " " << *p11 << " " << *sp6 << " " << *sp7 << endl;

	getchar();
	getchar();
	return 0;

}


// when you use smart pointer, do not mix with regular pointer, it will give you surprises
// when solving the circle problem, use regular pointer to subsitute weak_ptr
// sounds ok, but do not recommended

// when swap regular pointers, it's difficult
// but when swap smart pointers, it's more difficult
// some times, be aware of some objects are not pointed by any pointer, it will automtically
// deleted. your code will crash
// but regular pointers way will not happened this.




// HW6 help
// you cannot delete level one
// no keyword "delete" in this homework


// you do not need to do anything, when it going out of scope, all will destruct automtically
// you don't need to implemented destructor

head
  |
 node --> node --> node --> nullptr

// if there is a circle
// you need to cut the circle
// head->next.reset()

head
  |
-> node --> node --> node
|                      |
 ----------------------
