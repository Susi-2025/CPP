#include "PMergeMe.hpp"


int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Error: need at least 2 numbers to sort" << std::endl;
        return 1;
    }
    
    PMergeMe sorter;
    
    try
    {
        sorter.process(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}