#include "header.h"
using namespace std;

// The first symbol class Mint allows us to store a single integer value in the range 0 to p−1, where p is
// a positive integer, the modulus. In this class you should overload the subtraction operator overloaded
// to produce the typical integer result modulo p.

// Mint constructor
Mint::Mint(int _value, int _modulus) {
    if (_value < _modulus) {
        value = _value;
        modulus = _modulus;
    } else {
        cerr << "Mint must be less than modulus" << endl;
        exit(EXIT_FAILURE);
    }
}

// Empty mint constructor used for initializing empty array
Mint::Mint() {}

// Overloaded subtraction operator
int Mint::operator-(Mint m) {
    int typicalIntegerResult = value - m.getValue();
    int finalProduct;
    // If typical integer results is negative keep adding modulus until it is positive,
    // otherwise the modulus algorithm won't work correctly
    while (typicalIntegerResult < 0) {
        typicalIntegerResult += modulus;
    }
    return typicalIntegerResult%modulus;
}

// Returns the value of this mint object
int Mint::getValue() {
    return value;
}
