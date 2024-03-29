#include <iostream>
#include <vector>

using namespace std;

class BigData {
public:
	bool is_Hundred;
	vector<int>* pBigVector;
	BigData() { pBigVector = new vector<int>; is_Hundred = false; }
	BigData(int i) {//destructor: will be called when an object goes out of scope;
		//or when delte p; //where p is pointer to object of this type
		pBigVector = new vector<int>(i); if (i >= 100) is_Hundred = true; else false;
	}
	~BigData() { delete pBigVector; cout << "Leaving Destructor" << endl; }

	BigData(const BigData& B) {//copy constructor
		is_Hundred = B.is_Hundred;
		pBigVector = new vector<int>;// ((B.pBigVector)->size());
		*pBigVector = *(B.pBigVector);
		cout << "Leaving copy constructor!" << endl;
	}

	BigData(BigData&& B) : BigData() {//move constructor
	//:BigData() is to call default constructor
	//Otherwise, need to initialize as in copy constructor
		is_Hundred = B.is_Hundred;
		pBigVector = B.pBigVector;
		B.pBigVector = nullptr;
		cout << "Leaving move constructor" << endl;
	}

	BigData& operator=(const BigData& B) { //Lvalue operator=
		is_Hundred = B.is_Hundred;
		*pBigVector = *(B.pBigVector);
		cout << "Leaving L-value operator=" << endl;
		return *this;
	}

	void operator=(BigData&& B) {//Rvalue operator=
		is_Hundred = B.is_Hundred;
		pBigVector = B.pBigVector;
		B.pBigVector = nullptr;
		cout << "Leaving R-value operator=" << endl;

	}

	BigData getThreeTimes();
	void print();
};
BigData BigData::getThreeTimes() {
	BigData temp;
	temp.is_Hundred = is_Hundred;
	*temp.pBigVector = *pBigVector;
	for (int& i : *temp.pBigVector) { i *= 3; }
    // & sign, means you are not read only, you can also write
	return temp;
/*hidden copy
temp is Lvalue.  However, if you have implemented move constructor
and perform a return by value, compiler will automtically
changes it to
return move(temp); (It assumes that is what you really want.
A reason for doing that is:
When move constructor is introduced, it was stated that other than adding function
to class definition, you don't need to change code at any other place.

Thus, it will call move constructor, rather than copy constructor.
*/
}
void BigData::print() { for (int i : *pBigVector) { cout << i << " "; } }

int main() {
	BigData t1(10), t2{ t1 }, t3, t4, t5;
	BigData t8{ t1 };
    /*
    same thing
    BigData t8(t1);
    BigData t8{t1}; // the new feature
    BigData t8 = {t1};
    */
	for (size_t i = 0; i < t1.pBigVector->size(); i++) { (*(t1.pBigVector))[i] = 10 * i; }
	t1.print();
	cout << endl;
	t2 = t1;//t2.operator=(t2);
	t2.print();
	cout << endl;
	t3 = t1.getThreeTimes(); //t3.operator=(t1.getThreeTimes()); temp->hidden copy
	t3.print();

    // BigData t6, t7;
    // t7 = t6 = t1.getThreeTimes();
    // this will not run successfully
    // because when we implemented R-value assignment, the return value is void.
    // we need return reference to make the assignment transfering
    // now, only t3 = t1.getThreeTimes(); is working
    // t7 = t6 = t1 is not working

    // but t4 = t5 = t1; is working
    // because when we implemented L-value assignment, the return value is BigData&

	cout << endl;
	t4 = t5 = t1;//t4.operator=(t5.operator=(t1))
	cout << endl;
	t4.print();
	cout << endl;
	t5.print();
	cin.get();
	return 0;
}
/*
Leaving copy constructor!//due to t2{t1}
Leaving copy constructor!//due to BigData t8{t1}
0 10 20 30 40 50 60 70 80 90
Leaving L-value operator= //due to t2=t1
0 10 20 30 40 50 60 70 80 90
Leaving move constructor//due to t3 = t1.getThreeTimes();  copy temp to hidden copy // temp changed to be R-value, so when returning, it called move constructor
Leaving Destructor //due to t3 = t1.getThreeTimes(); hidden copy out of scope and destructor is called
Leaving R-value operator=//due to t3 = t1.getThreeTimes(); // t1.getThreeTimes() is R-value, so when assigning, it call move assignment(R-value operator=)
Leaving Destructor//t3 = t1.getThreeTimes(); hidden copy out of scope and destructor is called
0 30 60 90 120 150 180 210 240 270
Leaving L-value operator= //due to t4=t5=t1
Leaving L-value operator= //due to t4=t5=t1

0 10 20 30 40 50 60 70 80 90
0 10 20 30 40 50 60 70 80 90

*/


/*

Besides the constructor,
there are 4 functions:

Name                    Purpose                         Argument                        Return
copy constructor        --> for initialization          const BigData& B                no return
move constructor        --> for initialization          BigData&& B                     no return
L-value operator=       --> for assignment              const BigData& B                BigData& / void
R-value operator=       --> for assignment              BigData&& B                     BigData& / void
"R-value operator=", another name is move assignment

The original difference between L-value and R-value: L-value has a address

int a = b
b is L-value, it is used like a R-value

R-value always are temporary things, which are going to be destroyed

*/