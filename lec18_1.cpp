map<ThreeD*, int, my_compare_class> M{ {p1, 4}, {p2, 2} };
// map needs a type.like ThreeD*, int
// so what is type?
// class name is type.
// like my_compare_class (it's a functor)

// while find_if, for_each, they need a function, so we could use
// function, lambda expression, funtor to do this.



// homework 5 help
cout << count(L0, odd) << endl;
// first part is a list, second part is a function
// you could use function, lambda expression, funtor to do this.


// for map, it will sort the first element, you need a funtor to sort



// mutable lambda
// for lambda,
// when it captured value, it only capture once
// you can put a keyword "mutable" to make you could modify what have been captured
// lambda allows you to capture a state, while function don't