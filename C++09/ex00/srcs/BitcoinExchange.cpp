#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _database(other._database){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::trim(const std::string& str) const{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos|| end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

bool BitcoinExchange::isValidDateValue(const std::string& date) const{
    int year, month, day;
    char dash1, dash2;

    std::istringstream iss(date);
    iss >> year >> dash1 >> month >> dash2 >> day;

    if (year < 2009 || year > 2026)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    int days_arr[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap)
            days_arr[1] = 29;
    }
    return day <= days_arr[month - 1];
}

bool BitcoinExchange::isValidRate(const std::string& rateStr) const{
    if (rateStr.empty())
        return false;
    
    char* endptr;
    double rate = strtod(rateStr.c_str(), &endptr);

    if(*endptr != '\0' || rate < 0)
        return false;
    return true;
}
        
bool BitcoinExchange::validDatabaseFile(const std::string& filename){
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    int lineNum = 0;
    while(std::getline(file, line)){
        lineNum++;
        if(line.empty())
            continue;
        if (lineNum == 1 && line == "date,exchange_rate")
            continue;

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            std::cout << "Error: database line " << lineNum
            << " missing comma: " << line << std::endl;
            file.close();
            return false;
        }
        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));
        if (!isValidDateFormat(date))
        {
            std::cout << "Error: database line " << lineNum
            << " invalid date format: " << date << std::endl;
            file.close();
            return false;
        }
         if (!isValidDateValue(date))
        {
            std::cout << "Error: database line " << lineNum
            << " invalid date value: " << date << std::endl;
            file.close();
            return false;
        }
         if (!isValidRate(rateStr))
        {
            std::cout << "Error: database line " << lineNum
            << " invalid rate: " << rateStr << std::endl;
            file.close();
            return false;
        }
    }
    file.close();

    if (lineNum <= 1){
        std::cout << "Error: file has no data" << std::endl;
        return false;
    }
    std::cout << "Database validation passed" << std::endl;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    _database.clear();

    std::ifstream file(filename.c_str());

    std::string line;
    int lineNum = 0;
    while(std::getline(file, line)){
        lineNum++;
        if(line.empty())
            continue;
        if (lineNum == 1 && line == "date,exchange_rate")
            continue;

        size_t commaPos = line.find(',');
        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));
        char* endptr;
        double rate = strtod(rateStr.c_str(), &endptr);
        _database[date] = rate;
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
    if (_database.empty())
    {
        std::cout << "Error: database is empty." << std::endl;
        return;
    }

    std::ifstream infile(filename.c_str());
    if(!infile.is_open())
    {
        std::cout << "Error: could not open input file." << std::endl;
        return ;
    }

    std::string line;
    int lineNum = 0;
    while(std::getline(infile, line))
    {
        lineNum++;

        if (line.empty())
            continue;

        if (lineNum == 1)
        {
            if (line != "date | value")
                std::cout << "Error: bad input => "  << line << std::endl;
            continue;
        }
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;;
        }
        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDateFormat(date) || !isValidDateValue(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;;
        }

        char* endptr;
        double value = strtod(valueStr.c_str(), &endptr);

        if(*endptr != '\0')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large number." << std::endl;
            continue;;
        }

        std::map<std::string, double>::const_iterator it = _database.find(date);
        if (it == _database.end())
        {
            it = _database.lower_bound(date);
            if (it == _database.begin())
            {
                std::cout << "Error: no exchange rate available for " << date << std::endl;
                continue;;
            }
                --it;
        }

        double rate = it->second;
        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    infile.close();
}  

size_t BitcoinExchange::getDatabaseSize() const {
        return _database.size();
}

const char* BitcoinExchange::DatabaseErrorException::what() const throw()
{
    return "Error: database error";
}