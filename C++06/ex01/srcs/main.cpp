#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data* original = new Data(42, "Hello World!", 3.14159);
    
    // Print original pointer and data
    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Data: id=" << original->id 
              << ", name='" << original->name 
              << "', value=" << original->value << std::endl;
    
    // Serialize
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "\nSerialized value: " << raw << " (0x" << std::hex << raw << ")" 
              << std::dec << std::endl;
    
    // Deserialize
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "\nDeserialized pointer: " << deserialized << std::endl;
    
    // Verify it's the same object
    if (original == deserialized) {
        std::cout << "✓ SUCCESS: Pointers match!" << std::endl;
        std::cout << "Data: id=" << deserialized->id 
                  << ", name='" << deserialized->name 
                  << "', value=" << deserialized->value << std::endl;
    } else {
        std::cout << "✗ FAILURE: Pointers don't match!" << std::endl;
    }
    
    delete original;
    return 0;
}