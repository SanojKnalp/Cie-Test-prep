#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <algorithm>
#include <cmath>

class Polynomial {
private:
    size_t degree_;
    double* coeffs_; // Array of size (degree_ + 1). coeffs_[i] is the coefficient for x^i.

    static int poly_count; // For memory leak tracking

public:
    // 1. Constructor
    // Initializes a polynomial of given degree with all coefficients set to 0.0
    Polynomial(size_t degree);

    // --- TODO: RULE OF 5 & COPY-AND-SWAP [cite: 2276, 2315] ---
    ~Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial(Polynomial&& other) noexcept;
    friend void swap(Polynomial& first, Polynomial& second) noexcept;
    Polynomial& operator=(Polynomial other); // Unified assignment


    // --- TODO: OPERATOR OVERLOADING ---

    // 2. Array Subscript [cite: 1470]
    // Overload [] to get/set the coefficient for x^i. 
    // Example: p[2] = 5.0 sets the x^2 coefficient to 5.0.
    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    // 3. Function Evaluation [cite: 1476]
    // Overload () to evaluate the polynomial at a given x.
    // Example: double y = p(2.0);
    double operator()(double x) const;

    // 4. Compound Addition [cite: 2421, 2425]
    // HARD CHALLENGE: 'rhs' might have a LARGER degree than 'this'. 
    // If so, you must allocate a NEW array, copy your existing coefficients, 
    // add the rhs coefficients, delete your old array, and update degree_ and coeffs_.
    Polynomial& operator+=(const Polynomial& rhs);

    // 5. Binary Addition
    // Implemented cleanly using a copy and += [cite: 2444]
    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs);

    // 6. Stream Insertion [cite: 2458]
    // Print the polynomial. (e.g., "5x^2 + 2x^1 + 1x^0")
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    static int getPolyCount() { return poly_count; }
};

#endif