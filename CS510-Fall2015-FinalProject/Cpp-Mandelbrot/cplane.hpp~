#ifndef __MATRIX_H
#define __MATRIX_H

// Most useful standard library implementation of a vector
#include <vector>

// A template allows a type T to be passed into a class as a
// parameter, so a single class definition can use different types 
template <typename T> class Matrix {
  private:
    // Implementation section
    //
    // A matrix is a vector of vectors, each storing type T
    std::vector<std::vector<T> > mat;

    // Also store the number of rows and columns 
    unsigned int rows;
    unsigned int cols;

  public:
    // Interface section
    //
    // Default constructor, make matrix entries all one value of type T
    Matrix(unsigned int _rows, unsigned int _cols, const T& _initial);

    // Alternate copy-constructor
    Matrix(const Matrix<T> &rhs);

    // Destructor - deallocates memory
    virtual ~Matrix();

    // Defines the assignment = operator
    Matrix<T>& operator=(const Matrix<T>& rhs);

    // Defines the + operator between matrices
    Matrix<T> operator+(const Matrix<T>& rhs);

    // Defines the * operator between matrices
    Matrix<T> operator*(const Matrix<T>& rhs);

    // Defines the * operator between a matrix and a scalar
    Matrix<T> operator*(unsigned long rhs);

    // Defines the - operator between matrices
    Matrix<T> operator-(const Matrix<T>& rhs);

    // Defines the selection operator (i,j) to access elements
    T& operator()(const unsigned int &row, const unsigned int &col);
    const T& operator()(const unsigned int &row, const unsigned int &col) const;

    // Accessors for row and column sizes
    unsigned int get_rows() const;
    unsigned int get_cols() const;

};


// C++ requires seeing both the source code and declarations simultaneously
// when dealing with templates (arbitrary types T)
#include "matrix.cpp"

#endif
