#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>

int main() {
    std::cout << "=== Basic MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(37);
    mstack.push(97);
    mstack.push(23);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.pop();
    std::cout << "After pop, top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    std::cout << "\n=== Iterating through MutantStack ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n=== Reverse Iteration ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }
    
    std::cout << "\n=== Const Iterators Test ===" << std::endl;
    const MutantStack<int>& constRef = mstack;
    MutantStack<int>::const_iterator cit = constRef.begin();
    MutantStack<int>::const_iterator cite = constRef.end();
    
    std::cout << "Const iteration: ";
    while (cit != cite) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Compare with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(37);
    lst.push_back(97);
    lst.push_back(23);
    lst.pop_back();
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "MutantStack contents: ";
    for (MutantStack<int>::iterator it2 = mstack.begin(); it2 != mstack.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Test with different types ===" << std::endl;
    MutantStack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.718);
    doubleStack.push(1.618);
    
    std::cout << "Double stack: ";
    for (MutantStack<double>::iterator dit = doubleStack.begin(); 
         dit != doubleStack.end(); ++dit) {
        std::cout << *dit << " ";
    }
    std::cout << std::endl;
    
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("42");
    
    std::cout << "String stack: ";
    for (MutantStack<std::string>::iterator sit = stringStack.begin(); 
         sit != stringStack.end(); ++sit) {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Test with different underlying containers ===" << std::endl;
    MutantStack<int, std::vector<int> > vecStack;
    vecStack.push(10);
    vecStack.push(20);
    vecStack.push(30);
    
    std::cout << "Vector-based stack: ";
    for (MutantStack<int, std::vector<int> >::iterator vit = vecStack.begin(); 
         vit != vecStack.end(); ++vit) {
        std::cout << *vit << " ";
    }
    std::cout << std::endl;
    
    MutantStack<int, std::list<int> > listStack;
    listStack.push(100);
    listStack.push(200);
    listStack.push(300);
    
    std::cout << "List-based stack: ";
    for (MutantStack<int, std::list<int> >::iterator lit = listStack.begin(); 
         lit != listStack.end(); ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    MutantStack<int> copyStack(mstack);
    copyStack.push(999);
    
    std::cout << "Original: ";
    for (MutantStack<int>::iterator it2 = mstack.begin(); it2 != mstack.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy: ";
    for (MutantStack<int>::iterator it2 = copyStack.begin(); it2 != copyStack.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    assignedStack.push(777);
    
    std::cout << "Assigned: ";
    for (MutantStack<int>::iterator it2 = assignedStack.begin(); it2 != assignedStack.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    return 0;
}