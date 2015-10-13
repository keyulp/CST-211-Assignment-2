/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/09/15
* Last Modification Date:	10/12/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.h
*
*
*			Overview: The header for a templated 2D array
*
*			Input: A number of rows and columns
*
*			Output: none
****************************************************************/


#include "exception.h"
#include "Row.h"

using  namespace  std;


#ifndef Array2D_h
#define Array2D_h



template <class T>
class Array2D
{
public:
	Array2D(); // Default constructor
	Array2D(int row, int col);  // Constructor for the 2D Array
	Array2D(const Array2D &copy); // Copy constructor
	~Array2D(); // Destructor

	Array2D &operator=(const Array2D &rhs); //Assignment operator
	Row<T> operator[](int index); //Subscript operator
	Row<T> operator[](int index) const; //Subscript operator const

	int getRow() const; //Returns the number of rows
	void setRow(int rows); //Changes the number of rows
	int getColumn() const; //Returns the number of columns
	void setColumn(int columns); //Changes the number of columns
	
	T &Select(int row, int column) const; //Used to select an element of the 2D Array

private:

	T **m_array; // pointer to an array of the data type that will be allocated
	int m_rows;  // Number of rows in the array
	int m_cols; // Number of columns in the array

	void m_dataAllocation(T **&new_array, int rows, int cols); //Used to allocated data for new arrays
	void m_dataTransfer(T **new_array, int rows, int cols, bool conserve); //Used to conserve and transfer data between 2D arrays
};

#include "Array2D.inc"

#endif