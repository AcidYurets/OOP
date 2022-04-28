#include "Iterator.h"


// Equals
template<typename Type>
bool Iterator<Type>::operator !=(Iterator const& other) const { return _index != other._index; }

template<typename Type>
bool Iterator<Type>::operator ==(Iterator const& other) const { return _index == other._index; }

template<typename Type>
Iterator<Type>& Iterator<Type>::operator =(const Iterator<Type>& iter)
{
	_data = iter._data;
	_index = iter._index;

	_rows = iter._rows;
	_cols = iter._cols;

	return *this;
}

// Addition
template<typename Type>
Iterator<Type>& Iterator<Type>::operator ++()
{
	if (_index < _cols * _rows)
	{
		++_index;
	}

	return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator ++(int)
{
	Iterator<Type> iter(*this);
	++(*this);
	return iter;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator +(const int value) const
{
	Iterator<Type> iter(*this);

	if (value < 0 && iter._index < static_cast<size_t>(-value))
	{
		iter._index = 0;
	}
	else
	{
		iter._index += value;
	}

	if (iter._index > _rows * _cols)
	{
		iter._index = _rows * _cols;
	}

	return iter;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator +=(const size_t value) const
{
	_index += value;
	return *this;
}

// Substraction
template<typename Type>
Iterator<Type>& Iterator<Type>::operator --()
{
	if (_index < _cols * _rows)
	{
		--_index;
	}

	return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator --(int)
{
	Iterator<Type> iter(*this);
	--(*this);
	return iter;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator -(const int value) const
{
	return operator +(-value);
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator -=(const size_t value) const
{
	_index -= value;
	return *this;
}

// Pointers
template<typename Type>
Type& Iterator<Type>::operator *()
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols][_index % _cols];
}

template<typename Type>
const Type& Iterator<Type>::operator *() const
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols][_index % _cols];
}

template<typename Type>
Type& Iterator<Type>::operator ->()
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols].get() + (_index % _cols);
}

template<typename Type>
const Type& Iterator<Type>::operator ->() const
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols].get() + (_index % _cols);
}

// Other methods
template<typename Type>
Iterator<Type>::operator bool() const { return _data.expired(); }

template<typename Type>
bool Iterator<Type>::is_end() const { return _index == _rows * _cols; }

template<typename Type>
bool Iterator<Type>::is_valid() const { return !_data.expired(); }

template<typename Type>
Iterator<Type>& next() { return Iterator<Type>::operator ++(); }

