#include "task3_std_template.hpp"
#include <iostream>
#include <vector>
#include <memory> 
#include <string>
#include <cassert>

int main() {
    std::cout << "Running Hard Debugging Task...\n";

    // Test 1: Static Instance Tracking
    {
        EncryptedBuffer b1(10);
        EncryptedBuffer b2(20);
        assert(EncryptedBuffer::get_total() == 2);
    } // b1, b2 destroyed here
    assert(EncryptedBuffer::get_total() == 0);

    // Wrap Tests 2-4 in a scope so they clean up
    {
        // Test 2: Rule of 5
        EncryptedBuffer b3(5);
        b3 = b3; 
        EncryptedBuffer b4 = std::move(b3);
        b4.print(); 

        // Test 3: Const Correctness
        const EncryptedBuffer b_const(10);
        b_const.print(); 
        assert(b_const.get_access_count() == 1); 

        // Test 4: Vault
        Vault v;
        auto eb = std::make_unique<EncryptedBuffer>(100);
        v.add_data(std::move(eb));
        v.show_all();
    } // b3, b4, b_const, and Vault (with its data) are destroyed HERE
    
    assert(EncryptedBuffer::get_total() == 0);

    // Test 5: Polymorphic Deletion
    {
        SensitiveData* poly = new EncryptedBuffer(10);
        assert(EncryptedBuffer::get_total() == 1);
        delete poly; // Now it triggers the virtual destructor
    }
    
    assert(EncryptedBuffer::get_total() == 0); // THIS WILL NOW PASS

    std::cout << "ALL BUGS FIXED! You are an OOP Master.\n";
    return 0;
}