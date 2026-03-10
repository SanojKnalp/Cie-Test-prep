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
    Matrix(size_t r, size_t c) : rows_(r), cols_(c){
        data_ = new double[r*c];
        active_allocations++;
    }

    // --- TODO: RULE OF 5 & COPY-AND-SWAP ---
    
    // 2. Destructor
    ~Matrix()
    {
        delete[] data_;
        rows_ = 0;
        cols_=0;
        active_allocations--;
    }

    // 3. Copy Constructor (Deep Copy)
    Matrix(const Matrix& other)
    {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = new double[rows_*cols_];
        for(int i=0; i<rows_*cols_; i++)
        {
            data_[i] = other.data_[i];
        }
        active_allocations++;
    }

    // 4. Move Constructor
    Matrix(Matrix&& other) noexcept
    {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.cols_ = 0;
        other.data_ = 0;
    }

    // 5. Friend Swap Function (for Copy-and-Swap idiom)
    friend void swap(Matrix& first, Matrix& second) noexcept
    {
        using std::swap;
        swap(first.data_, second.data_);
    }

    // 6. Copy/Move Assignment Operator (Unified using Copy-and-Swap)
    Matrix& operator=(Matrix other)
    {
        swap(*this, other);
        active_allocations++;
        return *this;
    }


    // --- TODO: OPERATOR OVERLOADING ---

    // 7. Function Call Operator for 2D access (e.g., m(1, 2) = 5.0)
    // Hint: Map (row, col) to a 1D index using (row * cols_ + col)
    double& operator()(size_t r, size_t c)
    {
        return data_[r*cols_+c];
    }
    const double& operator()(size_t r, size_t c) const
    {
        return data_[r*cols_+c];
    }

    // 8. Compound Assignment: Addition
    // Assume both matrices are the same size. Add 'rhs' to this matrix.
    Matrix& operator+=(const Matrix& rhs)
    {
        for(int i=0; i<rows_*cols_; i++)
        {
            data_[i]+=rhs.data_[i];
        }
        return *this;
    }

    // 9. Binary Addition (implemented using +=)
    Matrix operator+(const Matrix& rhs) const
    {
        Matrix c(rhs.rows_, rhs.cols_); 
        for(int i=0; i<rows_*cols_; i++)
        {
            c.data_[i]+=rhs.data_[i]+data_[i];
        }

        return c;

    }

    // 10. Symmetric Scalar Multiplication (requires friend functions!)
    // We want both (matrix * 2.0) and (2.0 * matrix) to work.
    friend Matrix operator*(const Matrix& m, double scalar)
    {
        Matrix c(m.rows_, m.cols_); 
        for(int i=0; i<m.cols_*m.rows_; i++)
        {
            c.data_[i] = scalar*m.data_[i];
        }
        return c;
    }
    friend Matrix operator*(double scalar, const Matrix& m)
    {
        Matrix c(m.rows_, m.cols_); 
        for(int i=0; i<m.cols_*m.rows_; i++)
        {
            c.data_[i] = scalar*m.data_[i];
        }
        return c;
    }

    // 11. Stream Insertion
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    // Getters for testing
    size_t getRows() const { return rows_; }
    size_t getCols() const { return cols_; }
    static int getActiveAllocations() { return active_allocations; }
};

#endif