// mutable lambda
// for lambda,
// when it captured value, it only capture once
// you can put a keyword "mutable" to make you could modify what have been captured
// lambda allows you to capture a state, while function don't

// Typically, a lambda's function call operator is const-by-value,
// but use of the mutable keyword cancels this out.

#include <iostream>
using namespace std;

int main() {
	int int_value = 1;
	for (int i = 0; i < 5; i++) {
		cout << [int_value]() {return int_value; }() << " ";
		//int_value is read-only.  Any attemp to modify it inside the lambda will cause error.
		int_value++;
	}
	//The above loop will print 1 2 3 4 5
	cout << "int_value: " << int_value;
	// int_value: 6
	// one lambda expression capture int_value once
	// every time, cout << [int_value]() {return int_value; }() << " ";
	// is a new/different function, means every time, there is a capture action happened


	cout << endl;
	int_value = 1;
	auto my_lambda = [int_value]() {return int_value; };
	for (int i = 0; i < 5; i++) {
		cout << my_lambda() << " ";
		int_value++;
	}
	//The above loop will print 1 1 1 1 1
	cout << "int_value: " << int_value;
	// int_value: 6
	// one lambda expression capture int_value once
	// because we give our lambda expression a name,
	// we only have one lambda expression function,
	// means, we only capture int_value once, which happened before the for loop

	cout << endl;
	int_value = 1;
	//auto my_lambda_ = [int_value]() mutable {int_value++;  return int_value; };
	for (int i = 0; i < 5; i++) {
		cout << [int_value]() mutable {int_value++;  return int_value; }() << " ";
		//int_value++;
	}
	//The above loop will print 2 2 2 2 2
	cout << "int_value: " << int_value;
	// int_value: 1
	// mutable keyword is making the int_value inside could be changed
	// every loop, there is a new lambda, so every time we capture the int_value
	// from outside int_value
	// lambda expression is a function, if the parameter is passing by value,
	// it creates a copy inside the function
	// so every loop, the return value of lambda is 2, but it won't affect
	// the outside int_value

	cout << endl;
	int_value = 1;
	auto my_lambda_ = [int_value]() mutable {int_value++;  return int_value; };
	for (int i = 0; i < 5; i++) {
		cout << my_lambda_() << " ";
	}
	//The above loop will print 2 3 4 5 6
	cout << "int_value: " << int_value;
	// int_value: 1
	// int_value captured once, while my_lambda_ is not changed
	// the value captured is changed by every for loop
	// why the value in function is not destruct
	// I guess,
	// only the value in the argument list could be destruct
	// int_value is not argument, is a value has been captured


	cout << endl;
	int_value = 1;
	for (int i = 0; i < 5; i++) {
		cout << [&int_value]()  {int_value++;  return int_value; }() << " ";
		int_value++;
	}
	//The above loop will print 2 4 6 8 10
	cout << "int_value: " << int_value;
	// int_value: 11


	cout << endl;
	int_value = 1;
	auto my_lambda_1 = [&int_value]()  {int_value++;  return int_value; };
	for (int i = 0; i < 5; i++) {
		cout << my_lambda_1() << " ";
	}
	//The above loop will print 2 3 4 5 6
	cout << "int_value: " << int_value;
	// int_value: 6


	cin.get();
	return 0;
}

/*

// homework 5 help
cout << count(L0, odd) << endl;
// first part is a list, second part is a function
// you could use function, lambda expression, funtor to do this.


// for map, it will sort the first element, you need a funtor to sort
*/