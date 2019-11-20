#include "header.h"
using namespace std;

int main(int argc, char* argv[]) {

    testArguments(argc, argv); // Function that tests argument validity

    // Set variables for all the arguments
    bool isMelt = stoi(argv[1]); 
    bool isMint = !stoi(argv[1]); 
    unsigned int seed = stoi(argv[2]);
    unsigned int length = stoi(argv[3]);
    unsigned int size = stoi(argv[4]);

    // The rest of the program is split into 2 sections, Mint and Melt
    if (argc == 6 && isMint) { // If mint
        unsigned int modulus = stoi(argv[5]); // Create a modulus variable from the 5th argument
        Codeword<Mint> *codewords = new Codeword<Mint>[size]; // Create a codewords array

        for (int i=0; i<size; i++) {
            Mint* mints = new Mint[length]; // Create an array of mints

            for (int j=0; j<length; j++) {
                if (i==0) {
                    mints[j] = Mint(0, modulus); // First row of mints must be all zero
                } else {
                    mints[j] = Mint(generateMint(seed, modulus), modulus); // Randomly generate all other rows
                }
            }
            
            codewords[i] = Codeword<Mint>(mints, length); // Add this codeword to the array of codewords
            delete[] mints; // Delete mints now we are done using them
        }

        Codebook<Codeword<Mint>> codebook(codewords, size); // Add codewords array to codebook object

        codebook.display(); // Display codebook

        delete[] codewords; // Delete array of codewords now we are done with them

    } else if (argc == 5 && isMelt) { // If melt

        Codeword<Melt> *codewords = new Codeword<Melt>[size]; // Create an array of codewords

        for (int i=0; i<size; i++) {
            Melt* melts = new Melt[length]; // Create an array of melts

            for (int j=0; j<length; j++) {
                if (i==0) {
                    melts[j] = Melt('a'); // First row must be zero
                } else {
                    melts[j] = Melt(generateMelt(seed)); // Randomly generate all other rows
                }
            }

            codewords[i] = Codeword<Melt>(melts, length); // Add codeword to codewords array

            delete[] melts; // Delete melts as we are done with them
        }

        Codebook<Codeword<Melt>> codebook(codewords, size); // Create a codebook using the codewords array

        codebook.display(); // Display the codebook

        delete[] codewords; // Delete codewords array as we are done with it
    }
    
}

void testArguments(int argc, char* argv[]) {
    // Check that all arguments are positive numbers
    for (int arg = 1; arg<argc; arg++) {
        bool isNumber = true;
        for (int i = 0; i < ((string)argv[arg]).length(); i++) {
            if (isdigit(argv[arg][i]) == false) {
                isNumber = false; 
            }
        }
        if (!isNumber) {
            cerr << "Argument " << arg << " is not an integer" << endl;
            exit(EXIT_FAILURE);
        } else {
            if (stoi(argv[arg]) < 0) {
                cerr << "Argument " << arg << " must be a positive integer" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    // Check that the number of arguments is correct
    if (argc < 5) {
        cerr << "Too few arguments" << endl;
        exit(EXIT_FAILURE);
    } else if (argc == 5) {
        // Check that argument 1 is valid
        if (stoi(argv[1]) == 0) {
            cerr << "Mint code requires a modulus" << endl;
            exit(EXIT_FAILURE);
        } else if (stoi(argv[1]) != 1) {
            cerr << "Argument 1 must be 1 or 0" << endl;
            exit(EXIT_FAILURE);
        }
    } else if (argc == 6) {
        // Check that argument 1 is valid
        if (stoi(argv[1]) == 1) {
            cerr << "Modulus is only relevant for mint code" << endl;
            exit(EXIT_FAILURE);
        } else if (stoi(argv[1]) != 0) {
            cerr << "Argument 1 must be 1 or 0" << endl;
            exit(EXIT_FAILURE);
        }
    } else if (argc > 6) {
        cerr << "Too many arguments" << endl;
        exit(EXIT_FAILURE);
    }
}