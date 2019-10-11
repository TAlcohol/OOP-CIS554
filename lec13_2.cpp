// stack and queue
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int main() {
    stack<int> S;
    // stack<int> S = {1, 2, 3}; // it won't work, you have to add one by one
    S.push(5);
    S.push(6);
    S.push(7);
    cout << S.top() << endl;
    S.pop(); // remove the top one
    cout << S.top() << endl;
    if (!S.empty()) cout << "It is not empty!" << endl;
    cout << S.size() << endl;

    queue<int> Q;
    Q.push(19);
    Q.push(5);
    cout << Q.size() << " " << Q.front() << " " << Q.back() << endl;
    Q.pop(); // the front one will be removed
    cout << Q.size() << " " << Q.front() << " " << Q.back() << endl;

    cin.get();
    return 0;
}