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
    std::vector<std::shared_ptr<Animal>> animals;

public:
    // TODO 2: Use std::make_shared to create a Dog and 
    // add it to your vector.
    void addDog() {
        animals.emplace_back(std::make_shared<Dog>());
    }

    // TODO 3: Use std::make_shared to create a Cat and 
    // add it to your vector.
    void addCat() {
       animals.emplace_back(std::make_shared<Cat>());
    }

    // TODO 4: Use an iterator
    // to loop through the vector and concatenate all animal sounds.
    std::string performConcert() const {
        std::string concert = "";
        
        for(const auto& ansound : animals)
        {
            concert.append(ansound->speak());
        }
        
        return concert;
    }
    
    // Returns number of animals in the zoo
    size_t count() const { 
        /* YOUR CODE HERE */ 
        return animals.size(); 
    }
};

#endif