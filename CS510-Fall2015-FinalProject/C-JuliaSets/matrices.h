// Define types as abstraction layer to protect against implementation changes
typedef unsigned int INDEX;
typedef long double VALUE;

// Use abstract types inside matrix definition for robustness
typedef struct matrix {
  INDEX rows;
  INDEX cols;
  VALUE *mat;
} MATRIX;

// Constructor that initializes type in sensible way
MATRIX new_matrix(const INDEX, const INDEX);
// Destructor for allocated memory
void delete_matrix(MATRIX);
// Setter for individual elements
void set(MATRIX *, const INDEX, const INDEX, const VALUE);
// Getter for individual elements
VALUE get(const MATRIX *, const INDEX, const INDEX);
// Abstraction layer for printing values
void print_value(const VALUE);
// Abstraction layer for printing matrices
void print_matrix(const MATRIX *);
