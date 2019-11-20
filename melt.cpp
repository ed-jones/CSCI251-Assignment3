#include "header.h"
using namespace std;

// The second symbol class Melt allows us to store a single lowercase letter from the English alphabet,
// with the subtraction operator overloaded to give 1 if the symbols are different and 0 if they are the
// same. There are p = 26 distinct possible symbols.

// Melt constructor
Melt::Melt(char _value) {
    if (islower(_value)) {
        value = _value;
    } else {
        cerr << "Melt must be a lowercase letter" << endl;
        exit(EXIT_FAILURE);
    }
}

// Empty melt constructor used for initializing empty array
Melt::Melt() {}

// Overloaded subtraction operator
int Melt::operator-(Melt m) {
    if (value == m.getValue()) {
        return 0;
    } else {
        return 1;
    }
}

// Returns the value of this melt object
char Melt::getValue() {
    return value;
}