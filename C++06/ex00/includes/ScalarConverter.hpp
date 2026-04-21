#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <climits>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& );
        ScalarConverter& operator=(const ScalarConverter& );
        ~ScalarConverter();

        static bool isPseudoLiterals(const std::string& s);
        static bool isChar(const std::string& s);
        static bool isInteger(const std::string& s);
        static bool isFloat(const std::string& s);
        static bool isDouble(const std::string& s);

        static void convertFromChar(char c);
        static void convertFromInt(int i);
        static void convertFromFloat(float f);
        static void convertFromDouble(double d);
        static void convertFromPseudo(const std::string& s);

        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);

    public:
        static void convert(const std::string& literal);

};