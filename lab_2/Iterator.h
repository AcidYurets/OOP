#ifndef ITERATOR_BASE_H
#define ITERATOR_BASE_H

#include <memory>
#include <string>

#include "MatrixBaseException.h"

template <typename Type>
class Matrix;

template <typename Type>
class Iterator : public std::iterator<std::bidirectional_iterator_tag, Type> 
{
public:
	Iterator(const Matrix<Type>& mtrx, const size_t index = 0)
		: _data(mtrx.data), _index(index), _rows(mtrx.get_n()), _cols(mtrx.get_m()) {  }

	Iterator(const Iterator& iter) = default;

	// Equals
	bool operator !=(Iterator const& other) const;
	bool operator ==(Iterator const& other) const;
	Iterator<Type>& operator =(const Iterator<Type>& iter);

	// Addition
	Iterator<Type>& operator ++();
	Iterator<Type> operator ++(int);
	Iterator<Type> operator +(const int value) const;
	Iterator<Type>& operator +=(const size_t value) const;

	// Substraction
	Iterator<Type>& operator --();
	Iterator<Type>& operator --(int);
	Iterator<Type> operator -(const int value) const;
	Iterator<Type>& operator -=(const size_t value) const;

	// Pointers
	Type& operator *();
	const Type& operator *() const;

	Type& operator ->();
	const Type& operator ->() const;

	// Other methods
	operator bool() const;
	bool is_end() const;
	bool is_valid() const;
	Iterator<Type>& next();

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

#endif //!ITERATOR_BASE_H