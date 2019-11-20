// hash & priority_queue -- heap

/*
most system, it don't use sort, it use hash to distribute data

the search time always constant time O(1)

in C++, it's unordered map ( unordered multi map ), its a map, but it isn't sorted internally
for map and multimap, it's sorted

hashing is used for 3 purpose
1. sorting
2. storage
3. security (whether modified)


*/


/*

my_hash<int>, my_equal<int>
we build in type level, so it should be a class


hash<X> h;
hash<X> is c++ provided for you, you can use hash<int>
you don't need write your hash function


% 73
for no reason

the way to use unordered_map, it's like the way you use map

*/



/*
priority_queue

by default, it returns the max, but you can implemented in different way

when you include <queue> , priority_queue is there
but when you include <map>, unordered_map will not. you need to include <unordered_map>

default is less<int>, when you want reverse, you change it to greater<int>

priority_queue<int, vector<int>, greater<int> > pq2;
if you want to specify how to compare, you also need to include this part(vector<int>)


*/