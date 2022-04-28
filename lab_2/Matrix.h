#ifndef MATRIX_H
#define MATRIX_H

#include "MatrixBase.h"
#include "MatrixBaseException.h"
 
#include "Iterator.h"
#include "IteratorConst.h"

#include <iostream>
#include <stdio.h> 
#include <typeinfo>
#include <time.h>

template<typename Type>
class Matrix : public MatrixBase
{
public:
	class MatrixRow;
	friend IteratorConst<Type>;
	friend Iterator<Type>;
	// Constructors
	Matrix();
	Matrix(size_t n, size_t m);
	explicit Matrix(const Matrix<Type>& mtrx);
	Matrix(Matrix<Type>&& mtrx);
	Matrix(std::initializer_list<std::initializer_list<Type>> list);
	
	// Destructor
	~Matrix() = default;  

	// Operators equal
	Matrix<Type>& operator =(const Matrix<Type>& mtr);
	Matrix<Type>& operator =(Matrix<Type>&& mtr);
	Matrix<Type>& operator =(std::initializer_list<std::initializer_list<Type>> list);

	// Addition
	Matrix<Type> operator +(const Matrix<Type>& mtrx1) const;
	template <typename U>
	decltype(auto) operator +(const U& value) const;
	Matrix<Type>& operator +=(const Matrix<Type>& mtrx);
	void add(const Matrix<Type>& mtrx);
	void add(const Type& value);

	// Substraction
	Matrix<Type> operator -(const Matrix<Type>& mtrx1) const;
	Matrix<Type> operator -(const Type& value) const;
	Matrix<Type>& operator -=(const Matrix<Type>& mtrx);
	void sub(const Matrix<Type>& mtrx);
	void sub(const Type& value);

	// Multiplication
	Matrix<Type> operator *(const Matrix<Type>& mtrx1) const;
	Matrix<Type> operator *(const Type& value) const;
	Matrix<Type>& operator *=(const Matrix<Type>& mtrx);
	void mult(const Type& value);

	// Division
	Matrix<Type> operator /(const Type& value) const;
	void divide(const Type& value);

	Type& operator ()(size_t i, size_t j);
	const Type& operator ()(size_t i, size_t j) const;

	template<typename _Type>
	friend std::ostream& operator <<(std::ostream& os, const Matrix<_Type>& mtrx);
	
	// Iterators
	Iterator<Type> begin();
	Iterator<Type> end();

	IteratorConst<Type> begin() const;
	IteratorConst<Type> end() const;

	// Other methods
	size_t get_n() const;
	size_t get_m() const;

	const Type& get_value(size_t i, size_t j) const;
	void set_value(size_t i, size_t j, const Type& value);

	void fill_zero();
	void identity_matrix(); 

	class MatrixRow {
		friend Iterator<Type>;
		friend IteratorConst<Type>;
	private:
		std::shared_ptr<Type[]> _data = nullptr;
		size_t _size = 0;
	public:
		MatrixRow(Type* data, const size_t size) : _data(data), _size(size) {}
		MatrixRow() : _data(nullptr), _size(0) {}
		Type& operator[](size_t index);
		const Type& operator[](size_t index) const;
		void reset(Type* data, const size_t size);
		void reset();
	};

	const MatrixRow operator [](size_t row) const;
	MatrixRow operator [](size_t row);

private:
	std::shared_ptr<MatrixRow[]> data;
	std::shared_ptr<MatrixRow[]> allocateMemory(size_t n, size_t m);

	void addition(const Matrix<Type>& mtrx);
	void addition(const Type& value);

	void subtraction(const Matrix<Type>& mtrx);
	void subtraction(const Type& value);

	void multiplicate(const Type& value);
	void multiplicate(const Matrix<Type>& matr);

	void division(const Type& value); 
};

#endif // !MATRIX_H

