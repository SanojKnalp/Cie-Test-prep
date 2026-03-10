#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <algorithm> // for std::swap, std::copy

class Matrix {
private:
    size_t rows_;
    size_t cols_;
    double* data_;

    // Static tracker for the test file to ensure you don't leak memory
    static int active_allocations;

public:
    // 1. Constructor
    Matrix(size_t r, size_t c);

    // --- TODO: RULE OF 5 & COPY-AND-SWAP ---
    
    // 2. Destructor
    ~Matrix();

    // 3. Copy Constructor (Deep Copy)
    Matrix(const Matrix& other);

    // 4. Move Constructor
    Matrix(Matrix&& other) noexcept;

    // 5. Friend Swap Function (for Copy-and-Swap idiom)
    friend void swap(Matrix& first, Matrix& second) noexcept;

    // 6. Copy/Move Assignment Operator (Unified using Copy-and-Swap)
    Matrix& operator=(Matrix other);


    // --- TODO: OPERATOR OVERLOADING ---

    // 7. Function Call Operator for 2D access (e.g., m(1, 2) = 5.0)
    // Hint: Map (row, col) to a 1D index using (row * cols_ + col)
    double& operator()(size_t r, size_t c);
    const double& operator()(size_t r, size_t c) const;

    // 8. Compound Assignment: Addition
    // Assume both matrices are the same size. Add 'rhs' to this matrix.
    Matrix& operator+=(const Matrix& rhs);

    // 9. Binary Addition (implemented using +=)
    Matrix operator+(const Matrix& rhs) const;

    // 10. Symmetric Scalar Multiplication (requires friend functions!)
    // We want both (matrix * 2.0) and (2.0 * matrix) to work.
    friend Matrix operator*(const Matrix& m, double scalar);
    friend Matrix operator*(double scalar, const Matrix& m);

    // 11. Stream Insertion
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    // Getters for testing
    size_t getRows() const { return rows_; }
    size_t getCols() const { return cols_; }
    static int getActiveAllocations() { return active_allocations; }
};

#endif