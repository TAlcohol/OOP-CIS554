class ThreeD {
public:
    int ht;
    int wid;
    int dep;
};

void f1() { cout << "in Header1" << endl; }

int global{ 100 };

// struct and class is all the same, struct is public by default
// in the past, struct isn't allow data functions, now it all allow.
struct