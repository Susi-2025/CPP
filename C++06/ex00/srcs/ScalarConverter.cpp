
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&){
       return *this;
}
ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isPseudoLiterals(const std::string& s){
       if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" ||
       s == "+inff" || s == "-inff" || s == "inf" || s == "inff")
              return true;
       return false;
}

bool ScalarConverter::isChar(const std::string& s){
       if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
              return true;
       return false;
}

bool ScalarConverter::isInteger(const std::string& s){
       if (s.empty()) return false;

       size_t i = 0;
       if (s[i] == '-' || s[i] == '+')
              i++;

       if (i >= s.length()) return false;

       for (; i< s.length(); i++){
              if(!isdigit(s[i]))
                     return false;
       }

       return true;
}

bool ScalarConverter::isFloat(const std::string& s){
       if (s.empty()) return false;

       if (isPseudoLiterals(s)) return false;

       if (s[s.length() -1] != 'f' && s[s.length() - 1] != 'F') return false;

       std::string num = s.substr(0, s.length() - 1);
       if (num.empty()) return false;
       
       char* end;
       std::strtod(num.c_str(), &end);
       if (*end == '\0')
              return true;
       return false;
}

bool ScalarConverter::isDouble(const std::string& s){
       if (s.empty()) return false;

       if (isPseudoLiterals(s)) return false;

       char* end;
       std::strtod(s.c_str(), &end);
       if (*end == '\0')
              return true;
       return false;
}

void ScalarConverter::printChar(double value){
       std::cout << "char: ";

       if(value < 0 || value > 127 || std::isnan(value) || std::isinf(value)){
              std::cout << "impossible" << std::endl;
              return;
       }

       char c = static_cast<char>(value);
       if(std::isprint(c))
              std::cout << "'" << c << "'" << std::endl;
       else
              std::cout << "Non displayable" << std::endl;

}

void ScalarConverter::printInt(double value){
       std::cout << "int: ";

       if(value < INT_MIN || value > INT_MAX || std::isnan(value) || std::isinf(value)){
              std::cout << "impossible" << std::endl;
              return;
       }
       std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value){
       std::cout << "float: ";
       if(std::isnan(value)){
              std::cout << "nanf" << std::endl;
              return;
       }
       if(std::isinf(value)){
              std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
              return;
       }

       float f = static_cast<float>(value);
       if ((value > 0 && f == std::numeric_limits<float>::infinity()) ||
       (value < 0 && f== std::numeric_limits<float>::infinity())) {
              std::cout << "impossible" << std::endl;
              return;
       }

       std::cout << f;
       if (f == static_cast<int>(f))
              std::cout << ".0f";
       else
              std::cout << "f";
       std::cout << std::endl;
}

void ScalarConverter::printDouble(double value){
       std::cout << "double: ";
       if(std::isnan(value)){
              std::cout << "nan" << std::endl;
              return;
       }
       if(std::isinf(value)){
              std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
              return;
       }
       std::cout << value;
       if (value == static_cast<int>(value))
              std::cout << ".0";
       std::cout << std::endl;
}


void ScalarConverter::convertFromChar(char c){
       double value = static_cast<double>(c);
       printChar(value);
       printInt(value);
       printFloat(value);
       printDouble(value);
}

void ScalarConverter::convertFromInt(int i){
       double value = static_cast<double>(i);
       printChar(value);
       printInt(value);
       printFloat(value);
       printDouble(value);
}

void ScalarConverter::convertFromFloat(float f){
       double value = static_cast<double>(f);
       printChar(value);
       printInt(value);
       printFloat(value);
       printDouble(value);
}

void ScalarConverter::convertFromDouble(double d){
       printChar(d);
       printInt(d);
       printFloat(d);
       printDouble(d);
}

void ScalarConverter::convertFromPseudo(const std::string& s){
       std::cout << "char: impossible" << std::endl;
       std::cout << "int: impossible" << std::endl;

       if(s == "nan" || s == "nanf"){
              std::cout << "float: nanf" << std::endl;
              std::cout << "double: nan" << std::endl;
       } else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff"){
              std::cout << "float: +inff" << std::endl;
              std::cout << "double: +inf" << std::endl;
       } else if (s == "-inf" || s == "-inff"){
              std::cout << "float: -inff" << std::endl;
              std::cout << "double: -inf" << std::endl;
       }
}


void ScalarConverter::convert(const std::string& s){
       if (isPseudoLiterals(s)){
              convertFromPseudo(s);
              return;
       }

       if (isChar(s)){
              convertFromChar(s[1]);
              return;
       }

       if (isInteger(s)){
              long long value = strtol(s.c_str(), NULL, 10);
              if (value >= INT_MIN && value <= INT_MAX)
                     convertFromInt(static_cast<int>(value));
              else
                     convertFromDouble(strtod(s.c_str(), NULL));
              return;
       }

       if (isFloat(s)){
              std::string num = s.substr(0, s.length() -1);
              convertFromFloat(static_cast<float>(strtod(num.c_str(), NULL)));
              return ;
       }

       if (isDouble(s)){
              convertFromDouble(strtod(s.c_str(), NULL));
              return;
       }
       std::cout << "Error: Invalid literal" << std::endl;
}
