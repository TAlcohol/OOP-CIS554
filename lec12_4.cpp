// my notes for move()

/*
what move() doing is simply change a L-value to a R-value


Here are 2 examples:

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    string st = "I love xing";
    vector<string> vc ;
    vc.push_back(move(st));
    cout<<vc[0]<<endl;
    if(!st.empty())
        cout<<st<<endl;

    return 0;
}

// output:
// I love xing

// -------------------------------------------

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    string st = "I love xing";
    vector<string> vc ;
    vc.push_back(st);
    cout<<vc[0]<<endl;
    if(!st.empty())
        cout<<st<<endl;

    return 0;
}

// output:
// I love xing
// I love xing

// -------------------------------------------

the second example has no move() outside variable st

Probably there are 2 function named push_back() inside vector, dealing with L-value and R-value argument respectively

when the argument is R-value, the copy of st is push_back into vector, and delete the st itself (like move constructor)

So, cout << st, the result is nothing.

*/