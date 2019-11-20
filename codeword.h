// A Codeword container for storing ordered lists of symbols making up a codeword.

template <typename T> 
class Codeword {
    private:
        T *symbol;
        int length;
    public:
        // Codeword constructor
        Codeword(T *_symbol, int _length) {
            length = _length;
            symbol = new T [length];

            for (int i=0; i<length; i++) {
                symbol[i] = _symbol[i];
            }
        }

        //Codeword destructor
        ~Codeword() {
            // Commented out to prevent a bug
            
            // if (symbol != NULL) {
            //     delete [] symbol;
            // }
        }

        // Empty codeword constructor needed for initializing empty array
        Codeword() {}

        // Calculate the weight of this codeword (number of non-zero elements)
        int weight() {
            int weight = 0;
            for (int i=0; i<length; i++) {
                if (!isZero(symbol[i])) {
                    weight++;
                }
            }
            return weight;
        }

        // Calculate distance between self and codeword argument
        int distance(Codeword<T> _codeword) {

            int distance = 0;

            for (int i=0; i<length; i++) {
                distance += (*this).getSymbol(i) - _codeword.getSymbol(i);
            }

            return distance;
        }

        // Print codeword contents and weight to display
        void display() {
            for(int i=0; i<length; i++) {
                cout << symbol[i].getValue() << " ";
            }
            cout << "Weight: " << weight();
            cout << endl;
        }

        // Calcualte if zero in case of melt
        bool isZero(Melt _symbol) {
            if (_symbol.getValue() == 'a') {
                return true;
            } else {
                return false;
            }
        }

        // Calculate if zero in case of mint
        bool isZero(Mint _symbol) {
            if (_symbol.getValue() == 0) {
                return true;
            } else {
                return false;
            }
        }

        T getSymbol(int i) {
            return symbol[i];
        }
};
