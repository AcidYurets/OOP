#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <iostream>

class MatrixBase
{
public:
	explicit MatrixBase() : element_numb(0), n(0), m(0) { }
	virtual ~MatrixBase() = default;

	bool is_empty() const { return element_numb == 0; }
	size_t get_n(void) const { return n; }
	size_t get_m(void) const { return m; }
	size_t size() const { return element_numb; }

protected:
	size_t n;
	size_t m;
	size_t element_numb; 
};

#endif // !MATRIX_BASE_H

