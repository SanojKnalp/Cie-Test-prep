#ifndef DATAFILTER_HPP
#define DATAFILTER_HPP

#include <vector>
#include <iostream>

class DataFilter {
public:
    /**
     * TODO 1: Process the vector.
     * Iterate from the start to the end of the vector using a manual for-loop with iterators.
     * - If a value is EVEN, multiply it by 'factor'.
     * - If a value is ODD, leave it alone.
     */
    static void process(std::vector<int>& vec, int factor) {
        /* YOUR CODE HERE */
    }

    /**
     * TODO 2: Search the vector.
     * Find the first element strictly greater than 'threshold'.
     * Return an iterator to that element.
     * If no such element exists, return the end iterator of the vector.
     */
    static std::vector<int>::iterator findFirstAbove(std::vector<int>& vec, int threshold) {
        /* YOUR CODE HERE */
        return vec.end(); // Default return, change as needed
    }
};

#endif