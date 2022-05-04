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
	friend ConstIterator<Type>;
	friend Iterator<Type>;
	// Constructors
	Matrix() noexcept;
	Matrix(size_t n, size_t m);
	Matrix(size_t n, size_t m, const Type& filler);
	Matrix(size_t rows, size_t columns, Type** matrix);

	explicit Matrix(const Matrix<Type>& mtrx);
	Matrix(Matrix<Type>&& mtrx) noexcept;
	Matrix(std::initializer_list<std::initializer_list<Type>> list);

	// Operators equal
	Matrix<Type>& operator =(const Matrix<Type>& mtr);
	Matrix<Type>& operator =(Matrix<Type>&& mtr) noexcept;
	Matrix<Type>& operator =(std::initializer_list<std::initializer_list<Type>> list);

	virtual ~Matrix() = default; 

	void resize(size_t rows, size_t cols, const Type& filler);
	void fill_zero() noexcept;
	void identity_matrix() noexcept;

	// Addition
	template<typename U>
	decltype(auto) operator +(const Matrix<U>& mtrx) const;
	template <typename U>
	decltype(auto) operator +(const U& value) const;
	Matrix<Type>& operator +=(const Matrix<Type>& mtrx);
	Matrix<Type>& operator +=(const Type& value);
	template<typename U>
	decltype(auto) add(const Matrix<U>& mtrx);
	template<typename U>
	decltype(auto) add(const U& value);
	Matrix<Type>& addEq(const Matrix<Type>& mtrx);
	Matrix<Type>& addEq(const Type& value);

	// Substraction
	template<typename U>
	decltype(auto) operator -(const Matrix<U>& mtrx) const;
	template <typename U>
	decltype(auto) operator -(const U& value) const;
	Matrix<Type>& operator -=(const Matrix<Type>& mtrx);
	Matrix<Type>& operator -=(const Type& value);
	template<typename U>
	decltype(auto) sub(const Matrix<U>& mtrx);
	template<typename U>
	decltype(auto) sub(const U& value);
	Matrix<Type>& subEq(const Matrix<Type>& mtrx);
	Matrix<Type>& subEq(const Type& value);

	Matrix<Type> operator-() noexcept;
	Matrix<Type> neg();

	// Multiplication
	template<typename U>
	decltype(auto) operator *(const Matrix<U>& mtrx) const;
	template<typename U>
	decltype(auto) operator *(const U& value) const;
	Matrix<Type>& operator *=(const Matrix<Type>& mtrx);
	Matrix<Type>& operator *=(const Type& value);
	template<typename U>
	decltype(auto) mult(const Matrix<U>& mtrx);
	template<typename U>
	decltype(auto) mult(const U& value);
	Matrix<Type>& multEq(const Matrix<Type>& mtrx);
	Matrix<Type>& multEq(const Type& value);

	// Division
	template<typename U>
	decltype(auto) operator /(const Matrix<U>& mtrx) const;
	template<typename U>
	decltype(auto) operator /(const U& value) const;
	Matrix<Type>& operator /=(const Matrix<Type>& mtrx);
	Matrix<Type>& operator /=(const Type& value);
	template<typename U>
	decltype(auto) divide(const Matrix<U>& mtrx);
	template<typename U>
	decltype(auto) divide(const U& value);
	Matrix<Type>& divideEq(const Matrix<Type>& mtrx);
	Matrix<Type>& divideEq(const Type& value);

	Type& operator ()(size_t i, size_t j);
	const Type& operator ()(size_t i, size_t j) const;
	const MatrixRow operator [](size_t row) const;
	MatrixRow operator [](size_t row);
	const Type& get_value(size_t i, size_t j) const;
	void set_value(size_t i, size_t j, const Type& value);
	operator bool();
	size_t get_n() const noexcept;
	size_t get_m() const noexcept;

	template<typename U>
	friend std::ostream& operator <<(std::ostream& os, const Matrix<U>& mtrx) noexcept;

	// Math methods
	bool isSquare() const noexcept;
	Matrix<Type> transpose() const noexcept;
	Type determinant() const;
	// inverse method
	Matrix<Type> inverse();
	
	// Iterators
	Iterator<Type> begin() noexcept;
	Iterator<Type> end() noexcept;
	ConstIterator<Type> begin() const noexcept;
	ConstIterator<Type> end() const noexcept;

	class MatrixRow {
		friend Iterator<Type>;
		friend ConstIterator<Type>;
	private:
		std::shared_ptr<Type[]> _data = nullptr;
		size_t _size = 0;
	public:
		MatrixRow() : _data(nullptr), _size(0) {}
		Type& operator[](size_t index);
		const Type& operator[](size_t index) const;
		void reset(Type* data, const size_t size);
		void reset();
	};

private:
	std::shared_ptr<MatrixRow[]> data;
	std::shared_ptr<MatrixRow[]> allocateMemory(size_t n, size_t m);
};

#endif // !MATRIX_H

