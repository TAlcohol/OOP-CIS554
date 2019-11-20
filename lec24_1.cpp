/*
up casting is ok
down casting is not.
for this,
raw casting and static casting will not give you error,
dynamic cast will. and give you a nullptr

down casting is not allowed because the pointer is also pointed to more memory space not for that object.

only one case dynamic casting will not give you error when you did down casting.
you just do a up casting earlier, and you do a down casting again

you will always replace static casting with dynamic casting,
and you will find a lot of error, because static casting won't give you error


dynamic casting only can change a pointer to a pointer or a reference to a reference
(when it's not allowed, if it is pointer it will give a nullptr, but
there is no same thing in reference, so if it is reference, the program will just crash.)
static casting is not that strict





cross-delegation

can f1() call f2() ?
yes but with restrictions.
you have to make sure f1() and f2() in the class base, should be pure virtual function


*/