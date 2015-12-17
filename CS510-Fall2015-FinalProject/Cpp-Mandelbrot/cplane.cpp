// Pre-processor directives to prevent redundant library loading
#ifndef __MATRIX_CPP
#define __MATRIX_CPP

// include the header declarations
#include "cplane.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

#include <complex>
#include <cstdio>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>

//*************
//
// CONSTRUCTORS
//
//*************

// Default constructor
template<typename T> 
CPlane<T>::CPlane(long double xmin, long double xmax,
		long double ymin, long double ymax, 
		unsigned int _rows, unsigned int _cols, const T& _initial) {
  
  // use vector method to resize outer vector of rows to length _rows
  mat.resize(_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    // for each row, resize to length _cols of columns
    // and initialize elements to value _initial
    mat[i].resize(_cols, _initial);
  }


  // set private fields rows and cols properly
  rows = _rows;
  cols = _cols;


			
	}
	// Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
		std::complex<long double> ab;
		ab.x = xmin+(double)i*(xmax-xmin)/(double)(_cols-1);
		ab.y = ymin+(double)j*(ymax-ymin)/(double)(_rows-1);
		mat[i][j] = ab;
    }
  }
}

// Copy-constructor
template<typename T> CPlane<T>::CPlane(const CPlane<T>& rhs) {
  // Simply set private fields according to fields
  // of existing CPlane<T> object
  mat = rhs.mat;
  rows = rhs.get_rows();
  cols = rhs.get_cols();
}

// Destructor
// No memory is dynamically allocated in the class,
// so just use default compiler cleanup of memory 
template<typename T> CPlane<T>::~CPlane() {}



//*************
//
// ACCESSORS
//
//*************


// Access individual elements
template<typename T>
T& CPlane<T>::operator() (const unsigned int &row, const unsigned int &col) {
  return this->mat[row][col];
}

// Access individual elements (const)
template<typename T>
const T& CPlane<T>::operator() (const unsigned int &row, const unsigned int &col) 
const {
  return this->mat[row][col];
}

// Get number of rows
template<typename T>
unsigned int CPlane<T>::get_rows() const {
  return this->rows;
}

// Get number of cols
template<typename T>
unsigned int CPlane<T>::get_cols() const {
  return this->cols;
}





//*********************
//
// OPERATOR OVERLOADING
//
//*********************




// Assignment operator
template<typename T>
CPlane<T>& CPlane<T>::operator=(const CPlane<T>& rhs) {
  // If assigning to itself, just return itself
  if (&rhs == this)
    return *this;

  // Store new rows and cols
  unsigned int new_rows = rhs.get_rows();
  unsigned int new_cols = rhs.get_cols();

  // resize to new number of rows
  mat.resize(new_rows);
  // resize each row to new number of cols
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(new_cols);
  }

  // assign each element
  for (unsigned int i=0; i<new_rows; i++) {
    for (unsigned int j=0; j<new_cols; j++) {
      mat[i][j] = rhs(i, j);
    }
  }

  // store new number of rows and columns
  rows = new_rows;
  cols = new_cols;

  // return newly modified object
  return *this;
}

// Addition of two matrices
template<typename T>
CPlane<T> CPlane<T>::operator+(const CPlane<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  CPlane result(rows, cols, 0.0);

  // Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + rhs(i,j);
    }
  }
  return result;
}

// Multiplication of two matrices
template<typename T>
CPlane<T> CPlane<T>::operator*(const CPlane<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  CPlane result(rows, cols, 0.0);

  // Multiply each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] * rhs(i,j);
    }
  }
  return result;
}

// Multiplication a matrix by a scalar
template<typename T>
CPlane<T> CPlane<T>::operator*(unsigned long rhs) {
  // Create new matrix to store result, initialize to zero
  CPlane result(rows, cols, 0.0);

  // Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] * rhs;
    }
  }
  return result;
}

// Subtraction of two matrices
template<typename T>
CPlane<T> CPlane<T>::operator-(const CPlane<T>& rhs) {
  	return this->mat+(rhs*-1.);
}

#endif
