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
    Polynomial(size_t degree)
    {
        poly_count++;
        degree_ = degree;
        coeffs_ = new double[degree+1];
        for(int i=0; i<degree+1; i++)
        {
            coeffs_[i] = 0.0;
        }
    }

    // --- TODO: RULE OF 5 & COPY-AND-SWAP [cite: 2276, 2315] ---
    ~Polynomial()
    {
        coeffs_ = nullptr;
        poly_count--;
    }
    Polynomial(const Polynomial& other)
    {
        degree_ = other.degree_;
        coeffs_ = other.coeffs_;
        poly_count++;

    }
    Polynomial(Polynomial&& other) noexcept
    {
        degree_ = other.degree_;
        coeffs_ = other.coeffs_;
        other.degree_ = 0;
        other.coeffs_ = nullptr;

    }
    friend void swap(Polynomial& first, Polynomial& second) noexcept
    {
        using std::swap;
        swap(first.coeffs_, second.coeffs_);
    }
    Polynomial& operator=(Polynomial other) 
    {
        swap(*this, other);
        poly_count++;
        return *this;
    }


    // --- TODO: OPERATOR OVERLOADING ---

    // 2. Array Subscript [cite: 1470]
    // Overload [] to get/set the coefficient for x^i. 
    // Example: p[2] = 5.0 sets the x^2 coefficient to 5.0.
    double& operator[](size_t index)
    {
        return coeffs_[index];
    }
    const double& operator[](size_t index) const
    {
        return coeffs_[index];
    }

    // 3. Function Evaluation [cite: 1476]
    // Overload () to evaluate the polynomial at a given x.
    // Example: double y = p(2.0);
    double operator()(double x) const
    {
        double sum = 0.0;
        for(int i=0; i<degree_+1; i++)
        {
            sum+= coeffs_[i]*std::pow(x, i);
        }
        return sum;
    }

    // 4. Compound Addition [cite: 2421, 2425]
    // HARD CHALLENGE: 'rhs' might have a LARGER degree than 'this'. 
    // If so, you must allocate a NEW array, copy your existing coefficients, 
    // add the rhs coefficients, delete your old array, and update degree_ and coeffs_.
    Polynomial& operator+=(const Polynomial& rhs)
    {
        if( degree_ < rhs.degree_)
        {
            Polynomial newdeg(rhs.degree_);
            for(int i=0; i<degree_+1; i++)
            {
                newdeg.coeffs_[i] = coeffs_[i]+rhs.coeffs_[i];
            }
            coeffs_ = nullptr;
            for(int i=degree_+1; i<rhs.degree_+1; i++)
            {
                newdeg.coeffs_[i]+=rhs.coeffs_[i];
            }
            degree_ = rhs.degree_;
            coeffs_ = newdeg.coeffs_;
        }
        else
        {
            for(int i=0; i<rhs.degree_+1; i++)
            {
                coeffs_[i]+=rhs.coeffs_[i];
            }
        }
        return *this;
    }

    // 5. Binary Addition
    // Implemented cleanly using a copy and += [cite: 2444]
    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
    {
        size_t maxdegree = std::max(lhs.degree_, rhs.degree_);
        size_t mindegree = std::min(lhs.degree_, rhs.degree_);
        Polynomial last(maxdegree);
        for(int i=0; i<mindegree+1; i++)
        {
            last.coeffs_[i] = lhs.coeffs_[i]+rhs.coeffs_[i];
        }
        for(int i=mindegree+1; i<maxdegree+1; i++)
        {
            if(lhs.degree_>rhs.degree_)
            {
                last.coeffs_[i] = lhs.coeffs_[i];
            }
            else 
            {
                last.coeffs_[i] = rhs.coeffs_[i];
            }
        }
        return last;
    }

    // 6. Stream Insertion [cite: 2458]
    // Print the polynomial. (e.g., "5x^2 + 2x^1 + 1x^0")
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p)
    {
        for (int i = p.degree_; i >= 0; i--)
    {
        // Stream the data directly into 'os'
        os << p.coeffs_[i] << "x^" << i;
        
        // Add a " + " separator for all terms except the last one (i == 0)
        if (i > 0) 
        {
            os << " + ";
        }
    }
        
    }

    static int getPolyCount() { return poly_count; }
};

#endif