#include <iostream>
#include <cassert>
#include "task3_std.hpp"

int main() {
    std::cout << "Running Hard Debugging Task...\n";

    // Test 1: Static Instance Tracking
    {
        EncryptedBuffer b1(10);
        EncryptedBuffer b2(20);
        assert(EncryptedBuffer::get_total() == 2);
    }
    assert(EncryptedBuffer::get_total() == 0);

    // Test 2: Rule of 5 (Move & Self-Assign)
    EncryptedBuffer b3(5);
    b3 = b3; // Should not crash (Bug 3)
    
    EncryptedBuffer b4 = std::move(b3);
    // b3 is destroyed here. If Bug 4 isn't fixed, b4's data is now deleted. (Double free)
    b4.print(); 

    // Test 3: Const Correctness & Mutable (Bugs 2, 5, 6)
    const EncryptedBuffer b_const(10);
    b_const.print(); // Should increment access_count via 'mutable'
    assert(b_const.get_access_count() == 1); 

    // Test 4: Vault & Smart Pointers (Bug 8)
    Vault v;
    auto eb = std::make_unique<EncryptedBuffer>(100);
    v.add_data(std::move(eb));
    v.show_all();

    // Test 5: Polymorphic Deletion (Bug 1)
    SensitiveData* poly = new EncryptedBuffer(10);
    delete poly; // Should print "Data wiped" AND "Buffer destroyed" logic.
    // If Bug 1 is present, EncryptedBuffer's destructor never runs, and global_instances != 0.
    assert(EncryptedBuffer::get_total() == 0);

    std::cout << "ALL BUGS FIXED! You are an OOP Master.\n";
    return 0;
}