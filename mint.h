// The first symbol class Mint allows us to store a single integer value in the range 0 to p−1, where p is
// a positive integer, the modulus. In this class you should overload the subtraction operator overloaded
// to produce the typical integer result modulo p.

class Mint {
    private: 
        int value;
        int modulus;
    public:
        Mint(int, int);
        Mint();
        int operator-(Mint);
        int getValue();
};
