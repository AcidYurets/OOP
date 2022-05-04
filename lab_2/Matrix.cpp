#ifndef MATRIX_REALIZATION_H
#define MATRIX_REALIZATION_H

#include "Matrix.h"
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#pragma region Constructor/Destructor

template <typename T>
std::shared_ptr <typename Matrix<T>::MatrixRow[]> Matrix<T>::allocateMemory(size_t rows, size_t cols) 
{
	time_t err_time = time(nullptr);

	std::shared_ptr <MatrixRow[]> data = nullptr; 
	try {
		//T* matrix(new T[rows * cols]);

		data.reset(new MatrixRow[rows]);
		for (size_t i = 0; i < rows; i++)
		{
			//printf("%p\n", (void*)((char*)matrix + i * cols * sizeof(T)));
			//data[i].reset((T*)((char*)matrix + i * cols * sizeof(T)), cols);
			data[i].reset(new T[cols], cols);
		}
			
	}
	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	return data;
}

// Constructors

template<typename Type>
Matrix<Type>::Matrix() noexcept
{
	this->data = nullptr;

	this->element_numb = 0;
	this->n = 0;
	this->m = 0;
}

template<typename Type>
Matrix<Type>::Matrix(size_t n, size_t m)
{
	time_t err_time = time(nullptr);

	if ((n == 0) || (m == 0))
	{
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect matrix size");
	}

	this->element_numb = n * m;
	this->n = n;
	this->m = m;

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}
}

template<typename Type>
Matrix<Type>::Matrix(size_t n, size_t m, const Type& filler)
{
	time_t err_time = time(nullptr);

	if ((n == 0) || (m == 0))
	{
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect matrix size");
	}

	this->element_numb = n * m;
	this->n = n;
	this->m = m;

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			data[i][j] = filler;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, T** matrix)
{
	time_t err_time = time(nullptr);
	if ((n == 0) || (m == 0))
	{
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect matrix size");
	}
	if (!matrix)
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect ptr");
	}

	this->element_numb = n * m;
	this->n = n;
	this->m = m;

	data = allocateMemory(rows, columns);
	for (size_t i = 0; i < rows; ++i)
	{
		if (!matrix[i])
		{
			throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect ptr");
		}
		for (size_t j = 0; j < columns; ++j)
			data[i][j] = matrix[i][j];
	}
}

template<typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& mtrx) : MatrixBase()
{
	time_t err_time = time(nullptr);

	this->n = mtrx.get_n();
	this->m = mtrx.get_m();
	this->element_numb = mtrx.size();

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			this->data[i][j] = mtrx.data[i][j];
		}
	}
}

template<typename Type>
Matrix<Type>::Matrix(Matrix<Type>&& mtrx) noexcept : MatrixBase()
{
	time_t err_time = time(nullptr);

	this->n = mtrx.get_n();
	this->m = mtrx.get_m();
	this->element_numb = mtrx.size();

	this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));


	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			this->data[i][j] = mtrx.data[i][j];
		}
	}
}

template<typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<Type>> list)
{
	time_t err_time = time(nullptr);

	this->n = list.size();
	this->m = list.begin()->size();
	this->element_numb = n * m;

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	auto iter_i = list.begin();

	for (size_t i = 0; iter_i != list.end(); i++, iter_i++)
	{
		if (this->m != iter_i->size())
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
		}
		else
		{
			auto iter_j = iter_i->begin();

			for (size_t j = 0; iter_j != iter_i->end(); j++, iter_j++)
			{
				this->data[i][j] = *iter_j;
			}
		}
	}
}

#pragma endregion


#pragma region Equals

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(const Matrix<Type>& mtrx)
{
	time_t err_time = time(nullptr);

	size_t n_mtrx = mtrx.get_n();
	size_t m_mtrx = mtrx.get_m();

	this->n = n_mtrx;
	this->m = m_mtrx;
	this->element_numb = mtrx.element_numb;

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch(std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	if ((this->m == m_mtrx) && (this->n == n_mtrx))
	{
		for (size_t i = 0; i < n_mtrx; i++)
		{
			for (size_t j = 0; j < m_mtrx; j++)
			{
				this->data[i][j] = mtrx.data[i][j];
			}
		}
	}
	else
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(Matrix<Type>&& mtrx) noexcept
{
	time_t err_time = time(nullptr);

	size_t n_mtrx = mtrx.get_n();
	size_t m_mtrx = mtrx.get_m();

	this->n = n_mtrx;
	this->m = m_mtrx;
	this->element_numb = mtrx.element_numb;

	this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));

	for (size_t i = 0; i < n_mtrx; i++)
	{
		for (size_t j = 0; j < m_mtrx; j++)
		{
			this->data[i][j] = mtrx.data[i][j];
		}
	}

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(std::initializer_list<std::initializer_list<Type>> list)
{
	time_t err_time = time(nullptr);

	this->n = list.size();
	this->m = list.begin()->size();
	this->element_numb = n * m;

	try
	{
		this->data = std::shared_ptr<MatrixRow[]>(allocateMemory(n, m));
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	auto iter_i = list.begin();

	for (size_t i = 0; iter_i != list.end(); i++, iter_i++)
	{
		if (this->m != iter_i->size())
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
		}
		else
		{
			auto iter_j = iter_i->begin();

			for (size_t j = 0; iter_j != iter_i->end(); j++, iter_j++)
			{
				this->data[i][j] = *iter_j;
			}
		}
	}

	return *this;
}

#pragma endregion


#pragma region Addition

// Public methods
template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator +(const Matrix<U>& mtrx) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx.is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrices is empty.");
	}

	if ((mtrx.get_n() != this->n) || (mtrx.get_m() != this->m))
	{
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	Matrix<decltype((*this)[0][0] + mtrx[0][0])> tmp(n, m);

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[i][j] = data[i][j] + mtrx[i][j];

	return tmp;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator +(const U& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrices is empty.");
	}

	Matrix<decltype(this->data[0][0] + value)> result(n, m);

	for (size_t i = 0; i < result.get_n(); i++)
	{
		for (size_t j = 0; j < result.get_m(); j++)
		{
			result[i][j] = data[i][j] + value;
		}
	}
	return result;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator +=(const Matrix<Type>& mtrx)
{
	*this = *this + mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator +=(const Type& value)
{
	*this = *this + value;

	return *this;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::add(const Matrix<U>& mtrx)
{
	return *this + mtrx;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::add(const U& value)
{
	return *this + value;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::addEq(const Matrix<Type>& mtrx)
{
	*this = *this + mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::addEq(const Type& value)
{
	*this = *this + value;

	return *this;
}

#pragma endregion


#pragma region Substraction

// Public methods
template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator -(const Matrix<U>& mtrx) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx.is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrices is empty.");
	}

	if ((mtrx.get_n() != this->n) && (mtrx.get_m() != this->m))
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	Matrix<decltype((*this)[0][0] + mtrx[0][0])> tmp(n, m);

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[i][j] = data[i][j] - mtrx[i][j];

	return tmp;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator -(const U& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrices is empty.");
	}

	Matrix<decltype(this->data[0][0] + value)> result(n, m);

	for (size_t i = 0; i < result.get_n(); i++)
	{
		for (size_t j = 0; j < result.get_m(); j++)
		{
			result[i][j] = data[i][j] - value;
		}
	}
	return result;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator -=(const Matrix<Type>& mtrx)
{
	*this = *this - mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator -=(const Type& value)
{
	*this = *this - value;

	return *this;
}


template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::sub(const Matrix<U>& mtrx)
{
	return *this - mtrx;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::sub(const U& value)
{
	return *this - value;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::subEq(const Matrix<Type>& mtrx)
{
	*this = *this - mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::subEq(const Type& value)
{
	*this = *this - value;

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() noexcept
{
	Matrix<T> tmp(n, m);

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[i][j] = -data[i][j];

	return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::neg() 
{
	return operator-();
}

#pragma endregion


#pragma region Multiplication

// Public methods
template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator *(const Matrix<U>& mtrx) const
{
	time_t err_time = time(nullptr);

	if (this->n != mtrx.get_m())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	Matrix<decltype((*this)[0][0] * mtrx[0][0])> tmp(n, mtrx.get_m());
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < mtrx.get_m(); ++j)
			for (size_t k = 0; k < m; ++k)
				tmp[i][j] = data[i][k] * mtrx[k][j];

	return tmp;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator *(const U& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is empty.");
	}
	
	Matrix<decltype((*this)[0][0] * value)> tmp(n, m);
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[i][j] = data[i][j] * value;

	return tmp;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator *=(const Matrix<Type>& mtrx)
{
	*this = *this * mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator *=(const Type& value)
{
	*this = *this * value;

	return *this;
}


template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::mult(const Matrix<U>& mtrx)
{
	return *this * mtrx;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::mult(const U& value)
{
	return *this * value;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::multEq(const Matrix<Type>& mtrx)
{
	*this = *this * mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::multEq(const Type& value)
{
	*this = *this * value;

	return *this;
}

#pragma endregion


#pragma region Division

// Public methods
template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::operator /(const U& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is empty.");
	}

	Matrix<decltype((*this)[0][0] / value)> tmp(n, m);
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[i][j] = data[i][j] / value;

	return tmp;
}

template <typename Type>
template <typename U>
decltype(auto) Matrix<Type>::operator /(const Matrix<U>& matrix) const
{
	Matrix<decltype(data[0][0] / matrix[0][0])> tmp(matrix);
	tmp.inverse();
	return operator *(tmp);
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator /=(const Matrix<Type>& mtrx)
{
	*this = *this / mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator /=(const Type& value)
{
	*this = *this / value;

	return *this;
}


template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::divide(const Matrix<U>& mtrx)
{
	return *this / mtrx;
}

template<typename Type>
template<typename U>
decltype(auto) Matrix<Type>::divide(const U& value)
{
	return *this / value;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::divideEq(const Matrix<Type>& mtrx)
{
	*this = *this / mtrx;

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::divideEq(const Type& value)
{
	*this = *this / value;

	return *this;
}

#pragma endregion


#pragma region Round brackets
template<typename Type>
Type& Matrix<Type>::operator ()(size_t i, size_t j)
{
	time_t err_time = time(nullptr);

	if ((this->n <= i) || (this->m <= j))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return this->data[i][j];
}

template<typename Type>
const Type& Matrix<Type>::operator ()(size_t i, size_t j) const
{
	time_t err_time = time(nullptr);

	if ((this->n <= i) || (this->m <= j))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return this->data[i][j];
}

#pragma endregion

template<typename Type>
Matrix<Type>::operator bool()
{
	bool r = data.get();
	return r;
}


// Output matrix <<
template<typename Type>
std::ostream& operator <<(std::ostream& ostream, const Matrix<Type>& mtrx) noexcept
{
	for (size_t i = 0; i < mtrx.get_n(); i++)
	{
		for (size_t j = 0; j < mtrx.get_m(); j++)
		{
			ostream << mtrx.data[i][j] << "\t";
		}
		ostream << std::endl;
	}

	ostream << std::endl;
	return ostream;
}

#pragma region Math

template <typename T>
bool Matrix<T>::isSquare() const noexcept { return n == m; }

template <typename T>
Matrix<T> Matrix<T>::transpose() const noexcept
{
	Matrix<T> tmp(m, n);

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			tmp[j][i] = data[i][j];

	return tmp;
}


template <typename T>
// метод исключающий строку или столбец
void _excludeCopy(Matrix<T>& target, const Matrix<T>& source, size_t ex_row, size_t ex_col)
{
	size_t row_index, col_index;
	for (size_t i = 0; i < source.get_n() - 1; ++i)
		for (size_t j = 0; j < source.get_m() - 1; ++j)
		{
			row_index = i >= ex_row ? i + 1 : i;
			col_index = j >= ex_col ? j + 1 : j;
			target[i][j] = source[row_index][col_index];
		}
}

template <typename T>
T _determinant(const Matrix<T>& matrix)
{
	if (matrix.get_n() == 2)
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	if (matrix.get_n() == 1)
		return matrix[0][0];

	Matrix<T> tmp(matrix.get_n() - 1, matrix.get_m() - 1);
	T res = {};
	for (size_t i = 0; i < matrix.get_n(); ++i)
	{
		_excludeCopy(tmp, matrix, 0, i);
		T minor = _determinant(tmp);
		if (i & 1)
			minor = -minor;
		res += minor * matrix[0][i];
	}

	return res;
}

template <typename T>
T Matrix<T>::determinant() const
{
	if (!isSquare()) {
		time_t err_time = time(nullptr);
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix should be square to get determinant");
	}

	return _determinant(*this);
}

template <typename T>
Matrix<T> Matrix<T>::inverse()
{
	T det = determinant();
	if (!isSquare() || !det)
	{
		time_t err_time = time(nullptr);
		throw SizeException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix should be square and determinant should be > 0");
	}

	Matrix<T> res(n, m);
	Matrix<T> tmp(n - 1, m - 1);
	T value = {};

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
		{
			_excludeCopy(tmp, *this, i, j);
			value = tmp.determinant() / det;
			if ((i + j) & 1)
				value = -value;
			res[j][i] = value;
		}

	return res;
}

#pragma endregion

#pragma region Iterators

template<typename Type> 
Iterator<Type> Matrix<Type>::begin() noexcept
{ 
	Iterator<Type> iter(*this, 0);
	return iter;
}

template<typename Type>
Iterator<Type> Matrix<Type>::end() noexcept
{
	Iterator<Type> iter(*this, n * m);
	return iter;
}

template<typename Type>
ConstIterator<Type> Matrix<Type>::begin() const noexcept
{
	ConstIterator<Type> iter(*this->data, 0);
	return iter;
}

template<typename Type>
ConstIterator<Type> Matrix<Type>::end() const noexcept
{
	ConstIterator<Type> iter(*this->data, this->n * this->m);
	return iter;
}

#pragma endregion

#pragma region Matrix Row

template <typename T>
T& Matrix<T>::MatrixRow::operator[](size_t index) {
	time_t err_time = time(nullptr);

	if (index >= _size) {
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return _data[index];
}

template <typename T>
const T& Matrix<T>::MatrixRow::operator[](size_t index) const {
	time_t err_time = time(nullptr);

	if (index >= _size) {
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return _data[index];
}

template <typename T>
void Matrix<T>::MatrixRow::reset(T* data, const size_t size) {
	_size = size;
	_data.reset(data);
}

template <typename T>
void Matrix<T>::MatrixRow::reset() {
	_size = 0;
	_data.reset();
}

#pragma endregion

#pragma region Other methods

template<typename Type>
size_t Matrix<Type>::get_n() const noexcept
{
	return this->n;
}

template<typename Type>
size_t Matrix<Type>::get_m() const noexcept
{
	return this->m;
}

template<typename Type>
const Type& Matrix<Type>::get_value(size_t i, size_t j) const
{
	time_t err_time = time(nullptr);

	if ((i >= this->n) || (j >= this->m))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}
	else
	{
		if (this->data)
		{
			return data[i][j];
		}
		else
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
		}
	}
}

template<typename Type>
void Matrix<Type>::set_value(size_t i, size_t j, const Type& value)
{
	time_t err_time = time(nullptr);

	if ((i >= this->n) || (j >= this->m))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}
	else
	{
		if (this->data)
		{
			this->data[i][j] = value;
		}
		else
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
		}
	}
}

template <typename Type>
void Matrix<Type>::resize(size_t rows, size_t cols, const Type& filler) 
{
	if ((rows == 0 && cols != 0) || (rows != 0 && cols == 0))
		rows = 0, cols = 0;

	auto tmp = allocateMemory(rows, cols);

	for (size_t i = 0; i < std::min(n, rows); ++i)
	{
		for (size_t j = 0; j < std::min(m, cols); ++j)
			tmp[i][j] = data[i][j];
		for (size_t j = m; j < cols; ++j)
			tmp[i][j] = filler;
	}

	for (size_t i = n; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			tmp[i][j] = filler;

	data = tmp;
	n = rows;
	m = cols;
}

template<typename Type>
void Matrix<Type>::fill_zero() noexcept
{
	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			this->data[i][j] = 0;
		}
	}
}

template<typename Type>
void Matrix<Type>::identity_matrix() noexcept
{
	for (size_t i = 0; i < this->n; i++) 
	{
		for (size_t j = 0; j < this->m; j++)
		{
			if (i != j)
			{
				this->data[i][j] = 0;
			}
			else
			{
				this->data[i][j] = 1;
			}
		}
	}
}

template<typename Type>
const typename Matrix<Type>::MatrixRow Matrix<Type>::operator [](size_t row) const
{
	time_t err_time = time(nullptr);

	if (row >= this->get_n())
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return data[row];
}

template<typename Type>
typename Matrix<Type>::MatrixRow Matrix<Type>::operator [](size_t row)
{
	time_t err_time = time(nullptr);

	if (row >= this->get_n())
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return data[row];
}

#pragma endregion


template <typename T>
Matrix<T> operator+(const T& elem, const Matrix<T>& matrix) 
{
	return matrix + elem;
}

template <typename T>
Matrix<T> operator-(const T& elem, const Matrix<T>& matrix) 
{
	return matrix - elem;
}

template <typename T>
Matrix<T> operator*(const T& elem, const Matrix<T>& matrix) 
{
	return matrix * elem;
}

template <typename T>
Matrix<T> operator/(const T& elem, const Matrix<T>& matrix) 
{
	Matrix tmp(matrix);
	tmp.inverse();
	return tmp * elem;
}



#endif // !MATRIX_REALIZATION_H