#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(){

    std::vector<int> a ={5,10,9,2,20};
    int b  = 2;
    try{
        std::vector<int>::iterator res = easyfind(a, b);
        (void) res;
        std::cout << "Found in the container: " << b << std::endl;
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    
}