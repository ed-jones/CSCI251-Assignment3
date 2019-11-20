// A Codebook container containing a collection of codewords.

template <typename T> 
class Codebook {
    private:
        T *codewords; // Array of codewords
        int size; // Number of codewords
        int **distances; // 2D Array of distances
    public:
        // Codebook constructor
        Codebook(T *_codewords, int _size) {
            size = _size;
            codewords = new T [size];

            for (int i=0; i<size; i++) {
                codewords[i] = _codewords[i];
            }
        }

        // Codebook destructor
        ~Codebook() {
            if (codewords != NULL) {
                delete [] codewords;
            }

            if (distances != NULL) {
                for(int i = 0; i < size; ++i) {
                    delete [] distances[i];
                }
                
                delete [] distances;
            }
        }

        // Calculate minimum weight
        int minimumWeight() {
            int minWeight;

            for (int i=0; i<size; i++) {
                if (codewords[i].weight() != 0) {
                    minWeight = codewords[i].weight();
                    break;
                }
            }
            
            for (int i=0; i<size; i++) {
                if (codewords[i].weight() != 0 && codewords[i].weight() < minWeight) {
                    minWeight = codewords[i].weight();
                }
            }

            return minWeight;
        }

        // Calculate distance and update variable
        void calcDistance() {            
            distances = new int*[size];
            for(int i=0; i<size; ++i) {
                distances[i] = new int[size];
            }

            for (int x=0; x<size; ++x) {
                for (int y=0; y<size; ++y) {
                    distances[x][y] = codewords[x].distance(codewords[y]);
                }
            }
        }

        // Calculate the minimum distance
        int minimumDistance() {
            calcDistance();
            int minDistance;

            // Look for the first non-zero distance
            for (int x=0; x<size; x++) {
                for (int y=0; y<size; y++) {
                    if (distances[x][y] != 0) {
                        minDistance = distances[x][y];
                        break;
                    }
                }
            }

            // Find the shortest distance
            for (int x=0; x<size; x++) {
                for (int y=0; y<size; y++) {
                    if (distances[x][y] < minDistance && distances[x][y] != 0) {
                        minDistance = distances[x][y];
                    }
                }
            }

            return minDistance;
        }

        // Print the codebook contents to the display
        // as well as min weight, distance matrix and max distance
        void display() {
            for (int i=0; i<size; i++) {
                codewords[i].display();
            }

            cout << "Minimum Weight: " << minimumWeight() << endl;

            cout << "Distance Matrix: " << endl;

            calcDistance();
            for (int x=0; x<size; x++) {
                for (int y=0; y<size; y++) {
                    cout << to_string(distances[x][y]) << " ";
                }
                cout << endl;
            }

            cout << "Minimum Distance: " << minimumDistance() << endl;
        }
};
