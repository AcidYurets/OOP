#ifndef CONST_ITERATOR_BASE_H
#define CONST_ITERATOR_BASE_H

#include <memory>
#include <string>

#include "MatrixBaseException.h"

template <typename Type>
class Matrix;

template <typename Type>
class ConstIterator : public std::iterator<std::input_iterator_tag, Type>
{
public:
	ConstIterator(const Matrix<Type>& mtrx, const size_t index = 0)
		: _data(mtrx.data), _index(index), _rows(mtrx.get_n()), _cols(mtrx.get_m()) {  }

	ConstIterator(const ConstIterator& iter) = default;

	// Equals
	bool operator !=(ConstIterator const& other) const;
	bool operator ==(ConstIterator const& other) const;

	// Addition
	ConstIterator<Type>& operator ++() const;
	ConstIterator<Type> operator ++(int) const;
	ConstIterator<Type> operator +(const int value) const;
	ConstIterator<Type>& operator +=(const size_t value) const;

	// Substraction
	ConstIterator<Type>& operator --() const;
	ConstIterator<Type>& operator --(int) const;
	ConstIterator<Type> operator -(const int value) const;
	ConstIterator<Type>& operator -=(const size_t value) const;

	// Pointers
	const Type& operator *() const;
	const Type& operator ->() const;

	// Other methods
	operator bool() const;
	bool is_end() const;
	bool is_valid() const;
	ConstIterator<Type>& next() const;

private:
	std::weak_ptr<typename Matrix<Type>::MatrixRow[]> _data = nullptr;
	size_t _index = 0;
	size_t _rows = 0;
	size_t _cols = 0;

	void check_valid(int line)
	{
		time_t err_time = time(nullptr);

		if (!is_valid())
		{
			throw IsEmptyIterException(__FILE__, typeid(*this).name(), line - 4, err_time, "Pointer is null");
		}
	}
	void check_index(int line)
	{
		time_t err_time = time(nullptr);

		if (_index > _rows * _cols)
		{
			throw IndexIterException(__FILE__, typeid(*this).name(), line - 4, err_time, "Index error");
		}
	}
};

#endif //!CONST_ITERATOR_BASE_H