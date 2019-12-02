//Priority Queue -- default is max-heap


/*
priority_queue

by default, it returns the max, but you can implemented in different way

when you include <queue> , priority_queue is there
but when you include <map>, unordered_map will not. you need to include <unordered_map>

default is less<int>, when you want reverse, you change it to greater<int>

priority_queue<int, vector<int>, greater<int> > pq2;
if you want to specify how to compare, you also need to include this part(vector<int>)

*/


#include <iostream>
#include <queue> //for prioirity
#include <vector>
using namespace std;

template <class T> class ThreeD{
public:
	T ht;
	T wid;
	T dep;
	ThreeD() { ht = wid = dep = 0; }
	ThreeD(T i, T j, T k) { ht = i; wid = j; dep = k; }
	T getVol() const { return ht * wid * dep; }
};

template <class X> class my_comparator {
public:
	bool operator()(const ThreeD<X> & t1, const ThreeD<X> & t2) const { //this const is optional
		return (t1.getVol() < t2.getVol());

	}
};

template <class X> ostream& operator<<(ostream& str, const ThreeD<X>& t) {
	str << "(" << t.ht << ", " << t.wid << ", " << t.dep << ")";
	return str;
}

int main() {


	priority_queue<int> pq1;
	pq1.push(11);
	pq1.push(4);
	pq1.push(3);
	pq1.push(8);
	pq1.push(5);
	while (!pq1.empty()) {
		cout << pq1.top() << " ";   //will print 11 8 5 4 3
		pq1.pop();
	}
	cout << endl;

	priority_queue<int, vector<int>, greater<int>> pq2;//default is less<int>
	pq2.push(11);
	pq2.push(4);
	pq2.push(3);
	pq2.push(8);
	pq2.push(5);
	while (!pq2.empty()) {
		cout << pq2.top() << " ";  //will print 3 4 5 8 11
		pq2.pop();
	}
	cout << endl;
	ThreeD<int> t1(3, 4, 5), t2(1, 7, 8), t3(2, 3, 9), t4(10, 10, 10);
	priority_queue<ThreeD<int>, vector<ThreeD<int>>, my_comparator<int>> pq3;
	pq3.push(t1);
	pq3.push(t2);
	pq3.push(t3);
	pq3.push(t4);
	while (!pq3.empty())
	{
		cout << pq3.top();
		pq3.pop();
	}

	cin.get();
	return 0;
}
