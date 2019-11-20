// The second symbol class Melt allows us to store a single lowercase letter from the English alphabet,
// with the subtraction operator overloaded to give 1 if the symbols are different and 0 if they are the
// same. There are p = 26 distinct possible symbols.

class Melt {
    private: 
        char value;
    public:
        Melt(char);
        Melt();
        int operator-(Melt);
        char getValue();
};
