#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>

// 1. Compile-Time Type Trait (Template Metaprogramming) [cite: 1879, 1881]
// TODO: Implement 'IsPointer' trait. The base template should have a static const bool value = false;
template <typename T>
struct IsPointer {
    /* YOUR CODE HERE */
};

// TODO: Implement the partial specialization of 'IsPointer' for pointer types (T*).
// It should have a static const bool value = true; [cite: 1886]
/* YOUR CODE HERE */


// 2. Abstract Base Class for Runtime Polymorphism [cite: 734]
class INode {
public:
    virtual ~INode() = default;
    virtual std::string serialize() const = 0;
};

// 3. General Class Template [cite: 1765]
template <typename T>
class DataNode : public INode {
private:
    T data;
public:
    DataNode(T val) : data(val) {
        // Compile-time check: Prevent raw pointers from using the general template [cite: 1889, 1906]
        static_assert(!IsPointer<T>::value, "Pointers must use the specialized template!");
    }
    
    std::string serialize() const override {
        std::ostringstream oss;
        oss << data;
        return oss.str();
    }
};

// 4. Full Template Specialization (for bool) [cite: 1822]
// TODO: Implement a full specialization of DataNode for the 'bool' type.
// serialize() should return "TRUE" if true, and "FALSE" if false.
template <>
class DataNode<bool> : public INode {
    /* YOUR CODE HERE */
};

// 5. Partial Template Specialization (for pointers) [cite: 1829, 1838]
// TODO: Implement a partial specialization of DataNode for pointer types (T*).
// serialize() should dereference the pointer and return its value as a string.
// (Assume the pointer is never null for this exercise).
template <typename T>
class DataNode<T*> : public INode {
    /* YOUR CODE HERE */
};


// 6. The Pipeline Manager
class Pipeline {
private:
    // Store nodes polymorphically using smart pointers [cite: 894, 1055]
    std::vector<std::unique_ptr<INode>> nodes;

public:
    // Standard template push
    template <typename T>
    void push(T value) {
        nodes.push_back(std::make_unique<DataNode<T>>(value));
    }

    // 7. Variadic Templates (Recursive Base Case) [cite: 1856]
    // TODO: Implement the base case for push_all (takes a single argument of type T).
    template <typename T>
    void push_all(T first) {
        /* YOUR CODE HERE */
    }

    // 8. Variadic Templates (Recursive Step) [cite: 1860]
    // TODO: Implement the variadic push_all. It should take 'first' and a parameter pack 'rest'.
    // It should push 'first', then recursively call push_all with 'rest...'.
    template <typename T, typename... Args>
    void push_all(T first, Args... rest) {
        /* YOUR CODE HERE */
    }

    // Returns a combined string of all serialized nodes
    std::string process() const {
        std::string result = "";
        for (const auto& node : nodes) {
            result += node->serialize() + " | ";
        }
        return result;
    }
    
    size_t size() const { return nodes.size(); }
};

#endif