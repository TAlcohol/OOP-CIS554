// template

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

/*

This won't work if we want float numbers

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
    int getVol() { return ht * wid * dep; }
};
*/

// data type can view as a parameter

template <class T> class ThreeD {
public:
    T ht;
    T wid;
    T dep;
    ThreeD() { ht = wid = dep = (T) 0; }
    ThreeD(T i, T j, T k) { ht = i; wid = j; dep = k; }
    T getVol() { return ht * wid * dep; }
    T getArea();
};

template <class T> T ThreeD<T>::getArea() {
    return 2*(ht*wid + wid*dep + dep*ht);
}

// overload
// Use T instead of X is OK.
// This is just for showing another name is OK
template <class X> ostream& operator<<(ostream& str, const ThreeD<X>& t) {
    str << "(" << t.ht << ", " << t.wid << ", " << t.dep << ") ";
    return str;
}

template <class X> ostream& operator<<(ostream& str, const list<X>& L) {
    str << "<";
    for (auto i: L) { str << i << " "; }
    str << ">";
    return str;
}

template <class X> ostream& operator<<(ostream& str, const vector<X>& V) {
    str << "[";
    for (auto i: V) { str << i << " "; }
    str << "]";
    return str;
}

template <class X> ostream& operator<<(ostream& str, const vector<X *>& V) {
    str << "[";
    for (auto * i: V) { str << * i << " "; }
    str << "]";
    return str;
}

template <class X1, class X2> ostream& operator<<(ostream& str, const map<X1, X2>& M) {
    str << "{";
    for (auto i: M) { str << i.first << " " << i.second << " "; }
    str << "}";
    return str;
}



int main() {

    ThreeD<int> t1(3, 4, 5), t2(3, 9, 2), t3(1, 5, 6);
    cout << t1 << endl;
    ThreeD<double> t6(3.1, 3.5, 8.8);
    cout << t6 << endl;

    list<ThreeD<int>> L = { t1, t2, t3 };
    cout << L << endl;

    vector<ThreeD<int>> V = {t3, t2, t1};
    cout << V << endl;

    map<int, string> M1 = { {1, "Mary"}, {2, "Vijay"} };
    cout << M1 << endl;

    // you could do this:
    // map<ThreeD<int>, list<vector<int> > >

/*
    vector<list<ThreeD<int>>> V1 = {
        {{t1, t2, t3},{t2, t1}}, {{t1, t2}, {t1, t3}}, {{t1, t2, t3}, {t2, t3}}
    };
    cout << V1 << endl;
*/

    // we even could do this:
    // list<vector<list<ThreeD<float>>>> L3;
    // cout << L3 << endl;

    // you can put parameter when you initializing
    // vector size is 5, all the number is 2
    vector<int> V3(5, 2);

    // address inside
    vector<int *> V2 = { new int(25), new int(34), new int(24) };
    for (int *p: V2) { cout << *p << " "; }
    // ****************************************************************
    // the one place you do not need to worried about deleting is main function
    // because when main function ends, it will delete
    // but if it use too much, you could delete

    // you could do
    // vector<double *> V4 = {..../};
    // cout << V4 << endl;

    // you could do
    // map<int, map<int, list<vector<int> *>* >>


    char c1;
    c1 = getchar();
    c1 = getchar();
    return 0;
}