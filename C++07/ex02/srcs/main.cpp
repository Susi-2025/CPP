#include "Array.hpp"
#include <iostream>

int main(){
    std::cout << "=== Test 1: Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "Size of empty:" << empty.size() << std::endl;

    std::cout << "\n=== Test 2: Array with 8 elements ===" << std::endl;
    Array<int> arr(8);
    std::cout << "Size of arr[8]:" << arr.size() << std::endl;
    std::cout << "Default value:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Modify values ===" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

     // Test 4: Copy constructor (deep copy)
    std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "Original[0]: " << arr[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    
    // Test 5: Assignment operator
    std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = arr;
    assigned[1] = 888;
    std::cout << "Original[1]: " << arr[1] << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;
    
    // Test 6: Out of bounds
    std::cout << "\n=== Test 6: Out of bounds exception ===" << std::endl;
    try {
        arr[10] = 42;
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    
    // Test 7: String array
    std::cout << "\n=== Test 7: String array ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "42";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;
    
    // Test 8: Const array
    std::cout << "\n=== Test 8: Const array ===" << std::endl;
    const Array<int> constArr(3);
    std::cout << "Const array size: " << constArr.size() << std::endl;
    std::cout << "constArr[0]: " << constArr[0] << std::endl;
    // constArr[0] = 10; // Would cause compilation error
    
    std::cout << "\n=== All tests passed! ===" << std::endl;
}