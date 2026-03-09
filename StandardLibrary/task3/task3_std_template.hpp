#ifndef SECUREVAULT_HPP
#define SECUREVAULT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// BUG 1: Missing something critical for a base class used polymorphically
class SensitiveData {
public:
    ~SensitiveData() { std::cout << "Data wiped\n"; }
    virtual void print() const = 0;
};

class EncryptedBuffer : public SensitiveData {
private:
    size_t size;
    int* raw_data;
    // BUG 2: This needs to be modified in a const function. 
    int access_count; 
    
    static int global_instances;

public:
    EncryptedBuffer(size_t s) : size(s), access_count(0) {
        raw_data = new int[size];
        for(size_t i=0; i<size; ++i) raw_data[i] = 0;
        global_instances++;
    }

    // --- RULE OF FIVE ---
    
    ~EncryptedBuffer() {
        delete[] raw_data;
        global_instances--;
    }

    // Copy Constructor
    EncryptedBuffer(const EncryptedBuffer& other) : size(other.size), access_count(0) {
        raw_data = new int[size];
        std::copy(other.raw_data, other.raw_data + size, raw_data);
        global_instances++;
    }

    // BUG 3: Assignment operator is missing a check that prevents 
    // disaster during self-assignment (e.g., a = a)
    EncryptedBuffer& operator=(const EncryptedBuffer& other) {
        delete[] raw_data; 
        size = other.size;
        raw_data = new int[size];
        std::copy(other.raw_data, other.raw_data + size, raw_data);
        return *this;
    }

    // BUG 4: Move Constructor is missing a step that prevents double-free crashes
    EncryptedBuffer(EncryptedBuffer&& other) noexcept 
        : size(other.size), raw_data(other.raw_data), access_count(other.access_count) {
        global_instances++;
    }

    // --- LOGIC & OPERATORS ---

    // BUG 5: Const-correctness issue. This is a getter, but it's missing a keyword.
    int get_access_count() { return access_count; }

    void print() const override {
        // BUG 6: Related to BUG 2. This should work in a const function.
        access_count++; 
        std::cout << "Buffer of size " << size << std::endl;
    }

    // BUG 7: Operator Overloading. Returns reference to local memory.
    EncryptedBuffer& operator+(const EncryptedBuffer& other) {
        EncryptedBuffer result(this->size + other.size);
        return result;
    }

    static int get_total() { return global_instances; }
};

// Static initialization
int EncryptedBuffer::global_instances = 0;

class Vault {
private:
    std::vector<std::unique_ptr<SensitiveData>> storage;

public:
    void add_data(std::unique_ptr<SensitiveData> d) {
        // BUG 8: Ownership transfer issue. Unique_ptr cannot be copied.
        storage.push_back(d); 
    }

    void show_all() const {
        // Manual Iterator Loop
        for (auto it = storage.begin(); it != storage.end(); ++it) {
            // it is an iterator to a unique_ptr
            (*it)->print();
        }
    }
};

#endif