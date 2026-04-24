#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;
    
    // STEP 1: First validate the entire database
    std::cout << "Validating database..." << std::endl;
    if (!exchange.validDatabaseFile("data.csv"))
    {
        std::cout << "Database validation failed. Exiting." << std::endl;
        return 1;
    }
    
    // STEP 2: Only if validation passed, load it into the class
    std::cout << "Loading database into class..." << std::endl;
    try
    {
        exchange.loadDatabase("data.csv");
        std::cout << "Loaded " << exchange.getDatabaseSize() << " entries." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    // STEP 3: Process the input file
    std::cout << "\nProcessing input file..." << std::endl;
    exchange.processInputFile(argv[1]);
    
    return 0;
}