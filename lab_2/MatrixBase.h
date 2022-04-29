#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <iostream>

class MatrixBase
{
public:
	virtual ~MatrixBase() = default;

	bool is_empty() const noexcept { return element_numb == 0; }
	virtual size_t get_n(void) const noexcept { return n; }
	virtual size_t get_m(void) const noexcept { return m; }
	size_t size() const noexcept { return element_numb; }

protected:
	size_t n;
	size_t m;
	size_t element_numb; 

	explicit MatrixBase() : element_numb(0), n(0), m(0) { }
};

#endif // !MATRIX_BASE_H

