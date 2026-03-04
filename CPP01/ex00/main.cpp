
#include <iostream>
#include "Zombie.hpp"

int main(){

    std::cout << "Heap---" << std::endl;
    Zombie* heap = newZombie("HeapZom");
    heap->announce();
    delete heap;
    std::cout << std::endl;

    std::cout << "Stack---" << std::endl;
    randomChump("StackZom");
    return 0;
}