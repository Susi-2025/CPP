#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

struct DatabaseEntry{
    std::string date;
    double rate;
};

class BitcoinExchange{
    private:
        std::map<std::string, double> _database;

        bool isValidDateFormat(const std::string& date) const;
        bool isValidDateValue(const std::string& date) const;
        bool isValidRate(const std::string& rateStr) const;
        std::string trim(const std::string& str) const;
       
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        bool validDatabaseFile(const std::string& filename);
        void loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename) const;

        size_t getDatabaseSize() const;
    
        class DatabaseErrorException : public std::exception{
            public: virtual const char* what() const throw();
        };

};