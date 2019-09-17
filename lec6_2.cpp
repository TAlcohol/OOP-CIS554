// my notes for erase
// example copied from http://www.cplusplus.com/reference/list/list/erase/

/*
iterator erase (const_iterator position);
iterator erase (const_iterator first, const_iterator last);

Removes from the list container either a single element (position) or a range of elements ([first,last)).

This effectively reduces the container size by the number of elements removed, which are destroyed.

An iterator pointing to the element that followed the last element erased by the function call.
This is the container end if the operation erased the last element in the sequence.
*/




// erasing from list
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}

/*
Output:
mylist contains: 10 30 60 80 90
*/