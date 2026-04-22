#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

int main() {
    std::cout << "=== Basic Test from Subject ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should be 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Should be 14
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "=== Test Exceptions ===" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);  // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
    
    try {
        Span sp(1);
        sp.addNumber(42);
        sp.shortestSpan();  // Should throw (only 1 element)
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "=== Test with Range of Iterators ===" << std::endl;
    try {
        Span sp(10);
        std::vector<int> nums;
        nums.push_back(10);
        nums.push_back(20);
        nums.push_back(30);
        nums.push_back(40);
        nums.push_back(50);
        
        sp.addNumbers(nums.begin(), nums.end());
        std::cout << "Added 5 numbers, current size: " << sp.getSize() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "=== Test with 10,000 Numbers ===" << std::endl;
    try {
        Span sp(10000);
        
        // Add 10,000 random numbers
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(std::rand() % 100000);
        }
        
        std::cout << "Added 10,000 numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "=== Test Fill Limit with Range ===" << std::endl;
    try {
        Span sp(3);
        std::vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);  // Too many!
        
        sp.addNumbers(nums.begin(), nums.end());  // Should throw when trying to add 4th
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
    
    return 0;
}