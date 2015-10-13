/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/09/15
* Last Modification Date:	10/12/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.inc
*
*
*			Overview: Functionality for the functions declared in the header
*
*			Input: Array2D.h
*
*			Output: A 2D Array
****************************************************************/
template <class T>
Array2D<T>::Array2D()
{
}

template <class T>
Array2D<T>::Array2D(int row, int col)
	: m_cols(col), m_rows(row)
{
	m_dataAllocation(m_array, m_rows, m_cols);

}

template <class T> 
Array2D<T>::Array2D(const Array2D &arrayC)
{
	m_rows = arrayC.m_rows;
	m_cols = arrayC.m_cols;
	m_dataAllocation(m_array, m_rows, m_cols);
	m_dataTransfer(arrayC.m_array, m_rows, true, false);
}

template <class T>
Array2D<T>::~Array2D()
{
	delete[]m_array;
}

template <class T>
Array2D<T> &Array2D<T>::operator=(const Array2D<T> &rhs)
{
	if (this != &rhs)
	{ 
		delete[]m_array;
		m_dataAllocation(m_array, rhs.m_rows, rhs.m_cols);
		m_dataTransfer(rhs.m_array, rhs.m_rows, rhs.cols, false);
	}

	return this;
}

template <class T>
Row<T> Array2D<T>::operator[](int index)
{
	if (0 <= index && index < getRow()){
		Row<T> rowObj(*this, index);
		return rowObj;
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

template <class T>
Row<T> Array2D<T>::operator[](int index) const
{
	if (0 <= index && index < getRow()){
		Row<T> rowObj(*this, index);
		return rowObj;
	}
	Exception fail("Out of Bounds");
	throw(fail);
}

template <class T>
int Array2D<T>::getRow() const
{
	return m_rows;
}

template <class T>
void Array2D<T>::setRow(int rows) 
{
	T **temp_array;

	m_dataAllocation(temp_array, rows, m_cols);
	m_dataTransfer(temp_array, rows, m_cols, true);

	delete[]m_array;

	m_dataAllocation(m_array, rows, m_cols);
	m_dataTransfer(temp_array, rows, m_cols, false);

	delete[]temp_array;
}

template <class T>
int Array2D<T>::getColumn() const
{
	return m_cols;
}

template <class T>
void Array2D<T>::setColumn(int columns)
{
	T **temp_array;

	m_dataAllocation(temp_array, m_rows, columns);
	m_dataTransfer(temp_array, m_rows, columns, true);
	
	delete []m_array;

	m_dataAllocation(m_array, m_rows, columns);
	m_dataTransfer(temp_array, m_rows, columns, false);

	delete[]temp_array;
	
}

template <class T>
T &Array2D<T>::Select(int row, int col) const
{
	T *element = m_array[row];
	return element[col];
}

template <class T>
void Array2D<T>::m_dataAllocation(T **&new_array, int rows, int cols)
{
	new_array = new T*[rows];
	if (!m_array)
	{
		Exception fail("Failed Memory Allocation");
		throw(fail);
	}
	for (int i = 0; i < rows; i++)
	{
		m_array[i] = new T[cols];
		if (!m_array[i])
		{
			Exception fail("Failed Memory Allocation");
			throw(fail);
		}

	}
}

template <class T>
void Array2D<T>::m_dataTransfer(T **new_array, int rows, int cols, bool conserve)
{

	for (int idx = 0; idx < rows; idx++)
	{
		T *memberElement = m_array[idx];
		T *tempElement = new_array[idx];
		for (int id = 0; id < cols; id++)
		{
			if (conserve)
			{
				tempElement[id] = memberElement[id];
			}
			else
			{
				memberElement[id] = tempElement[id];
			}
		}
	}

}