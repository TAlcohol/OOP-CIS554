// Destructor and return by value
#include <iostream>
#include <vector>

using namespace std;

class BigData {
public:
    bool is_Hundred;
    vector<int> *pBigVector;
    BigData() { pBigVector = new vector<int>; is_Hundred = false; }
    // pBigVector = new vector<int>; this means the current size is 0
    BigData(int i) { pBigVector = new vector<int>(i);
    if (i >= 100) is_Hundred = true;
    else is_Hundred = false;
    }
    ~BigData() { delete pBigVector; cout << "Leaving Destructor" << endl; }
    // only in these 2 cases you will evoke destructor
    // when object goes out of scope; or when a object is pointed by p, and you delete using delete p;
    BigData(const BigData &B);
    // copy constructor

    BigData operator=(BigData B); // L-value operator=

    void print();
    BigData getThreeTimes();

};

BigData BigData::operator=(BigData B) { //L-value operator=
	//pBigVector->clear() ;
	is_Hundred = B.is_Hundred;
	*pBigVector = *(B.pBigVector);
	cout << "Leaving L-value operator=" << endl;
	return *this;
}

// BigData::BigData(const BigData &b): BigData {
BigData::BigData(const BigData &B) { //copy constructor
    is_Hundred = B.is_Hundred;
    pBigVector = new vector<int>;
    *pBigVector = *(B.pBigVector);
    cout << "Leaving copy constructor!" << endl;
    // for (size_t i = 0; i < b.pBigVector->size(); i++) {
    //     (*pBigVector)[i] = (*b.pBigVector)[i];
    // }
}


void BigData::print() {
    for (int i: *pBigVector) { cout << i << " "; }
}

BigData BigData::getThreeTimes() {
    BigData temp(pBigVector->size());
    temp.is_Hundred = is_Hundred;
    *temp.pBigVector = *pBigVector;
    for (int &i: *temp.pBigVector) { i *= 3; }
    return temp;
    // & sign, means you are not read only, you can also write
}
// if you don't delete your self, or use destructor, when the scope is end, this will cause memory leak

int main() {
    BigData t1(10), t2, t3, t4, t5;
    for (size_t i = 0; i < t1.pBigVector->size(); i++) {
        (*t1.pBigVector)[i] = i*10;
    }
    t1.print();
	cout << endl;
	t2 = t1;
	t2.print();
	cout << endl;
    t3 = t1.getThreeTimes(); //Compiler will convert it to: t3.operator=(t1.getThreeTimes());
	t3.print();
	cout << endl;
    t4 = t5 = t1;//Compiler will convert it to: t4.operator=(t5.operator=(t1))
	cout << endl;
	t4.print();
	cout << endl;
	t5.print();

    cin.get();
    return 0;
}

/*
0 10 20 30 40 50 60 70 80 90
Leaving copy constructor!
Leaving L-value operator=
Leaving copy constructor!
Leaving Destructor
Leaving Destructor
0 10 20 30 40 50 60 70 80 90
Leaving copy constructor!
Leaving Destructor
Leaving L-value operator=
Leaving copy constructor!
Leaving Destructor
Leaving Destructor
0 30 60 90 120 150 180 210 240 270
Leaving copy constructor!
Leaving L-value operator=
Leaving copy constructor!
Leaving Destructor
Leaving L-value operator=
Leaving copy constructor!
Leaving Destructor
Leaving Destructor

0 10 20 30 40 50 60 70 80 90
0 10 20 30 40 50 60 70 80 90


*/