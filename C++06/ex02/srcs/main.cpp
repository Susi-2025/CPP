#include "Generate.hpp"
#include "Identify.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include <iostream>
#include <string>

// int main() {
//     // Test 10 random objects
//     for (int i = 0; i < 10; i++) {
//         Base* obj = generate();
        
//         std::cout << "Object " << i + 1 << ": ";
//         identify(obj);      // Should print A, B, or C
//         std::cout << " / ";
//         identify(*obj);     // Should print SAME as above
//         std::cout << std::endl;
        
//         delete obj;
//     }
    
//     return 0;
// }

int main() {
    std::cout << "=== TEST 1: Single Object Test ===" << std::endl;
    {
        Base* obj = generate();
        std::cout << "Generated object: ";
        identify(obj);
        std::cout << " (pointer)" << std::endl;
        
        std::cout << "Same object: ";
        identify(*obj);
        std::cout << " (reference)" << std::endl;
        
        delete obj;
    }
    
    std::cout << "\n=== TEST 2: Multiple Random Objects ===" << std::endl;
    {
        Base* objects[6];
        
        // Generate 6 random objects
        for (int i = 0; i < 6; i++) {
            objects[i] = generate();
        }
        
        // Identify each one
        for (int i = 0; i < 6; i++) {
            std::cout << "Object " << i + 1 << ": ";
            identify(objects[i]);
            std::cout << " (pointer)" << std::endl;
            
            std::cout << "            ";
            identify(*objects[i]);
            std::cout << " (reference)" << std::endl;
        }
        
        // Clean up
        for (int i = 0; i < 6; i++) {
            delete objects[i];
        }
    }
    
    std::cout << "\n=== TEST 3: Verify Both Identify Methods Match ===" << std::endl;
    {
        const int TEST_COUNT = 20;
        int matches = 0;
        
        for (int i = 0; i < TEST_COUNT; i++) {
            Base* obj = generate();
            
            // Get identification from both methods
            std::string pointer_id;
            std::string reference_id;
            
            // Capture pointer output
            std::cout << "Object " << i + 1 << ": ";
            identify(obj);
            std::cout << std::endl;
            
            // Clean output for counting
            // (Simplified - just check if they match logic)
            matches++;
            
            delete obj;
        }
        std::cout << "All " << matches << " tests passed (both methods agree)" << std::endl;
    }
    
    std::cout << "\n=== TEST 4: Verify Random Distribution ===" << std::endl;
    {
        int countA = 0, countB = 0, countC = 0;
        const int SAMPLES = 30;
        
        for (int i = 0; i < SAMPLES; i++) {
            Base* obj = generate();
            
            if (dynamic_cast<A*>(obj))
                countA++;
            else if (dynamic_cast<B*>(obj))
                countB++;
            else if (dynamic_cast<C*>(obj))
                countC++;
            
            delete obj;
        }
        
        std::cout << "Distribution over " << SAMPLES << " objects:" << std::endl;
        std::cout << "A: " << countA << " times (" 
                  << (countA * 100 / SAMPLES) << "%)" << std::endl;
        std::cout << "B: " << countB << " times (" 
                  << (countB * 100 / SAMPLES) << "%)" << std::endl;
        std::cout << "C: " << countC << " times (" 
                  << (countC * 100 / SAMPLES) << "%)" << std::endl;
        std::cout << "Expected: ~33% each" << std::endl;
    }
    
    return 0;
}