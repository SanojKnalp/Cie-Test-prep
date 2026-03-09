#ifndef ZOOMANAGER_HPP
#define ZOOMANAGER_HPP

#include <iostream>
#include <vector>
#include <memory> 
#include <string>

// Abstract Base Class
class Animal {
public:
    virtual ~Animal() = default; 
    virtual std::string speak() const = 0;
};

class Dog : public Animal {
public:
    std::string speak() const override { return "Woof"; }
};

class Cat : public Animal {
public:
    std::string speak() const override { return "Meow"; }
};

class Zoo {
private:
    // TODO 1: Declare a private std::vector that stores 
    // shared_ptr objects of type Animal.
    /* YOUR CODE HERE */

public:
    // TODO 2: Use std::make_shared to create a Dog and 
    // add it to your vector.
    void addDog() {
        /* YOUR CODE HERE */
    }

    // TODO 3: Use std::make_shared to create a Cat and 
    // add it to your vector.
    void addCat() {
        /* YOUR CODE HERE */
    }

    // TODO 4: Use an iterator
    // to loop through the vector and concatenate all animal sounds.
    std::string performConcert() const {
        std::string concert = "";
        
        /* YOUR CODE HERE: 
           1. Get the begin iterator
           2. Loop until the end iterator
           3. Access the animal's speak() method via the iterator
        */
        
        return concert;
    }
    
    // Returns number of animals in the zoo
    size_t count() const { 
        /* YOUR CODE HERE */ 
        return 0; 
    }
};

#endif