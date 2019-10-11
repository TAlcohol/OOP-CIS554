// my notes for const functions in C++
// reference to https://www.geeksforgeeks.org/const-member-functions-c/

/*
Const member functions in C++
Like member functions and member function arguments, the objects of a class can also be declared as const. an object declared as const cannot be modified and hence, can invoke only const member functions as these functions ensure not to modify the object.
A const object can be created by prefixing the const keyword to the object declaration. Any attempt to change the data member of const objects results in a compile-time error.
Syntax:

const Class_Name Object_name;
When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
Whenever an object is declared as const, it needs to be initialized at the time of declaration. however, the object initialization while declaring is possible only with the help of constructors.
A function becomes const when the const keyword is used in the function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called. It is recommended the practice to make as many functions const as possible so that accidental changes to objects are avoided.

Following is a simple example of a const function.
*/

#include<iostream>
using namespace std;

class Test {
	int value;
public:
	Test(int v = 0) {value = v;}

	// We get compiler error if we add a line like "value = 100;"
	// in this function.
	int getValue() const {return value;}
};

int main() {
	Test t(20);
	cout<<t.getValue();
	return 0;
}

/*
Output:

20
When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.

For example the following program has compiler errors.
*/

#include<iostream>
using namespace std;

class Test {
	int value;
public:
	Test(int v = 0) {value = v;}
	int getValue() {return value;}
};

int main() {
	const Test t;
	cout << t.getValue();
	return 0;
}

/*
Output:

 passing 'const Test' as 'this' argument of 'int
Test::getValue()' discards qualifiers
Let’s look at another example:
*/


// Demonstration of constant object,
// show that constant object can only
// call const member function
#include<iostream>
using namespace std;
class Demo
{
	public:
	void showMessage()
	{
		cout<<"Hello World We are Tushar, "
		"Ramswarup, Nilesh and Subhash Inside"
		" showMessage() Function"<<endl;
	}
	void display()const
	{
		cout<<"Hello world I'm Rancho "
		"Baba Inside display() Function"<<endl;
	}
};
int main()
{
	const Demo d1;
	//d1.showMessage();Error occurred if uncomment.
	d1.display();
	return(0);
}

/*
OUTPUT : Hello world I'm Rancho Baba Inside display() Function
*/