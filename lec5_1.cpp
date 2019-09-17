// standard template library (STL)
// There are many containers in STL such as vector, list, map, queue, stack, set, etc.
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    ThreeD() { ht = wid = dep = 0; }
    ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }
    int getVol() const { return ht * wid * dep; }

    bool operator< (const ThreeD &t) { return (getVol() < t.getVol()); }
    // why we put a "const", it protect the current object
    // inside it evoke a function "t.getVol()"
    // we put a const at the end of "int getVol() const { return ht * wid * dep; }"

    bool operator==(const ThreeD &t) { return (getVol() == t.getVol()); }
};

ostream& operator<<(ostream &str, const ThreeD &t) {
    str << "(" << t.ht << ", " << t.wid << ", " << t.dep << ")";
    return str;
}

int main() {
    vector<int> V1 = { 0,1,2,3,4 };
    cout << V1.size() << " " << V1.front() << " " << V1.back() << endl;
    //size() returns number of elements of V1.
	//front() and back() returns first and last element of V1, respectively.
    V1.push_back(5); //add a new element 5 to the back.
    V1.pop_back(); //remove the last element
    //vector only support push or pop at the end

	//Since each element of vector or listed has been wrapped with many new functions,
	//its exact data type is no longer clear to programmers.  If we want to use pointers to
	//point to elements of vector or list, we need to know their exact data type.
	//Thus, we can't use regular pointers.
	//To solve this problem, STL comes with a special type of pointers, called iterator.
	//Iterators behavior like regular pointers, and are required when pointing to elements of
	//STL containers such as vector, list, map, etc.

	//In conclusion, iterators are special pointers that programmers are required to use within STL
	//to point to elements within STL.

    vector<int>::iterator it1 = V1.begin();
    // auto it1 = V1.begin(); // is equivalent to the above statement.
    // because in right hand side system will know what data type to assigned

    while (it1 != V1.end()) {
        cout << *it1 << " ";
        it1++;
    }
    cout << endl;
    // you could also do like this
    for (int i = 0; i < V1.size(); i++) {
        cout << V1[i] << " ";
    }
    // you will have a warning, so change "int" to "size_t"
    // size_t is a type of non-negative integer
    // V1.size() will return a non-negative value
    // so there would be a miss match if you use int
    for (size_t i = 0; i < V1.size(); i++) {
        cout << V1[i] << " ";
    }
    //vector supports random access, i.e., the array index function

    cout << endl;
    for (int i : V1) { cout << i << " "; }
    //This is new syntax of for loop

    cout << endl;
    it1 = find(V1.begin(), V1.end(), 3); // search for value 3
    // find return address, it has to be assigned to iterator
    // if there is no match, it return V1.end()
    if (it1 != V1.end()) {
        V1.erase(it1);
    }
    // if (it1==V1.end()) the erase function will crash the program.
	// Note that the erase function will take address (or iterator) as augument.

    list<int> L1 = { 5,2,11,1,6 };
    cout << L1.size() << endl;
    // list allow you to add and delete at both ends
    L1.push_back(1);
    L1.push_front(100);
    L1.pop_back();
    L1.pop_front();
    cout << L1.size() << " " << L1.front() << " " << L1.back() << endl;
    // Similar to vector, list supports size(), front(), and back().

    cout << endl;
    list<int>::iterator it2 = L1.begin();
    while (it2 != L1.end()) {
        cout << *it2 << " ";
        it2++;
    }
    // however list don't support array index, [] index is not allowed
    // list iterator only allows 4 operations: it++, ++it, it--, --it
    // even "it = it + 1;" will give you a syntax error
    // you can't jump in a list, it doesn't support random access

    // Only list support sort function
    L1.sort();
    cout << endl;

    it2 = find(L1.begin(), L1.end(), 3); // search for value 3
    if (it2 != L1.end()) {
        L1.erase(it2);
    }

    L1.remove(2);
    // if 2 is there, it delete 2,
    // it does nothing if 2 does not exist
    cout << endl;

    it2 = L1.begin();
    while (it2 != L1.end()) {
        cout << *it2 << " ";
        it2++;
    }
    cout << endl;

    //We can use the new for loop syntax on list too.
    for (int i : L1) { cout << i << " "; }
    cout << endl;

    ThreeD t1(3,4,5), t2(1,8,7), t3(2,3,9);
    list<ThreeD> L2 = { t1, t2, t3 };

    for (ThreeD i : L2) { cout << i << endl; }
    L2.sort(); // it will you an error if you don't overloading something
    // because it don't know how to compare
    // we need overloading in ThreeD class
    for (ThreeD i : L2) { cout << i << endl; }

    auto it3 = L2.begin();
    it3 = find(L2.begin(), L2.end(), t2);


    getchar();
    getchar();
    return 0;
}