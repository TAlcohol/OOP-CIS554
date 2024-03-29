// lambda or lambda expression
// [capture clause](argument list) {function body}

// function pointer, functor, lambda has the same effect
// they all represent function address
// so we can create a pointer to function

// what is lambda's type?
// each lambda has its globally unique type
// we don't know the type.
// lambda is created for use, they don't want to you know the type ( it is very complicated )
// but we could use "auto" now.
// auto p = [](int a, int b) { return a % 3 < b % 3; }
// now lambda becomes to reusable, because it has a name.
// but it's not recommended, it's not lambda designed for



#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main() {
	/*
A lambda (or lambda expression) consists of three parts:
[capture clause](argument list){function body}
Capture list allows you to specify which objects (variables) in
the scope of calling function can be accessed in the lambda.
Two types of access: Access (or Capture) by value or
Access (capture) by reference.  See examples below.
Argument list is the same as argument list of regular function.

Lambda is primarily used for in-place function definition and/or
invocation.  Although it can have a "name" and be re-used, it is
primarily used as an un-named function definition.
	*/
	list<int> L1{ 7,4,3,9,5 };
	L1.sort([](int a, int b) {return a % 3 < b % 3; });
	//The lambda here does not capture any local objects.

	for (int i :L1) { cout << i << " "; };
	cout << endl;
	int j{ 10 }, s{ 100 };
    // j = 10, j(10), j{10} are all the same
	list<int> L2{ 1,2,3,4};
	for_each(L2.begin(), L2.end(), [j, &s](int i) {s += i + j; });
/*
	The lambda here captures two local objects j and s.
	j is captured by value and is thus read-only.  Any attempt
	to modify the value of j will lead to compilation error.
	s is capture by reference.  It permits both read and write.
	Similar to call by reference in a function, there will be a single
	object s.  Thus, any modification on s in lambda will actually
	modify the s in the scope of calling function.

More on capture clause:
	[&] : access all variables with both read and write
	[=] : access all variables with read only
	[&, i]: i read only and all others both read and write
	[=, &i, &j] :  i and j both read and write, all others read only
	[=, i] : error
*/
	cout << s << endl;
	for (int i : L2) { [j, &s](int i) {s += i + j; }(i); }
    // what is (i) mean?
    // because lambda is equal to a function name, like
    // f
    // so, this one is equal to
    // for (int i : L2) { f(i); }
	cout << s << endl;

	auto p = [](int a, int b) {return sqrt(abs(a * a - b * b)); };
	cout << p(3, 9) << endl;
	cout << p(7, 15) << endl;

	list<int *> L3{ new int{4}, new int{7}, new int {9}, new int{3}, new int{1} };
	auto it = find_if(L3.begin(), L3.end(), [](int* i) {return *i == 9;});
	if (it != L3.end()) L3.erase(it);
	for (int* i : L3) { cout << *i << " "; }
	cin.get();
	return 0;
}


// lambda allows you to access local variables from the enclosing scope,
// from this point of view, lambda is more powerful than ordinary functions
// because functions are created to be reused, lambda is created to use one time,
// include all the local variables are not a big deal.
