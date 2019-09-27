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
    ~BigData() { delete pBigVector; }
    // only in these 2 cases you will evoke destructor
    // when object goes out of scope; or when a object is pointed by p, and you delete using delete p;
    BigData(const BigData &b);
    // copy constructor

    void print();
    BigData getThreeTimes();

};

// BigData::BigData(const BigData &b): BigData {
BigData::BigData(const BigData &b) {
    is_Hundred = b.is_Hundred;
    pBigVector = new vector<int> (b.pBigVector->size());
    // pBigVector->assign(10);
    for (size_t i = 0; i < b.pBigVector->size(); i++) {
        (*pBigVector)[i] = (*b.pBigVector)[i];
    }
}


void BigData::print() {
    for (int i: *pBigVector) { cout << i << " "; }
}

BigData BigData::getThreeTimes() {
    BigData temp;
    temp.is_Hundred = is_Hundred;
    *temp.pBigVector = *pBigVector;
    for (int &i: *temp.pBigVector) { i * = 3; }
    return temp;
    // & sign, means you are not read only, you can also write
}
// if you don't delete your self, or use destructor, when the scope is end, this will cause memory leak

int main() {
    BigData b1(10), b2;
    for (size_t i = 0; i < b1.pBigVector->size(); i++) {
        (*b1.pBigVector)[i] = i*10;
    }
    b1.print();
    b2 = b1.getThreeTimes();
    // complier will convert it to b2.operator=(b1.getThreeTimes());
    b2.print();


    cin.get();
    return 0;
}