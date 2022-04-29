#include "IteratorConst.h"


// Equals
template<typename Type>
bool ConstIterator<Type>::operator !=(ConstIterator const& other) const { return _index != other._index; }

template<typename Type>
bool ConstIterator<Type>::operator ==(ConstIterator const& other) const { return _index == other._index; }

// Addition
template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator ++() const
{
	if (_index < _cols * _rows)
	{
		++_index;
	}

	return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator ++(int) const
{
	ConstIterator<Type> iter(*this);
	++(*this);
	return iter;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator +(const int value) const
{
	ConstIterator<Type> iter(*this);

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
ConstIterator<Type>& ConstIterator<Type>::operator +=(const size_t value) const
{
	_index += value;
	return *this;
}

// Substraction
template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator --() const
{
	if (_index < _cols * _rows)
	{
		--_index;
	}

	return *this;
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator --(int) const
{
	ConstIterator<Type> iter(*this);
	--(*this);
	return iter;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator -(const int value) const
{
	return operator +(-value);
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator -=(const size_t value) const
{
	_index -= value;
	return *this;
}

// Pointers
template<typename Type>
const Type& ConstIterator<Type>::operator *() const
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols][_index % _cols];
}

template<typename Type>
const Type& ConstIterator<Type>::operator ->() const
{
	check_valid(__LINE__);
	check_index(__LINE__);

	std::shared_ptr<typename Matrix<Type>::MatrixRow[]> ptr_cpy = _data.lock();
	return ptr_cpy[_index / _cols].get() + (_index % _cols);
}

// Other methods
template<typename Type>
ConstIterator<Type>::operator bool() const { return _data.expired(); }

template<typename Type>
bool ConstIterator<Type>::is_end() const { return _index == _rows * _cols; }

template<typename Type>
bool ConstIterator<Type>::is_valid() const { return !_data.expired(); }

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::next() const { return operator ++(); }

