#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other): _store(other._store) {}

RPN& RPN::operator=(const RPN& other){
    if (this != &other)
        this->_store = other._store;
    return *this;
}
        
RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const{
    if (token == "+" || token == "-" || token == "*" || token == "/" )
        return true;
    return false;
}

bool RPN::isNumber(const std::string& token) const{
    if(token.empty())
        return false;
        
    size_t i = 0;
    if (token[i] == '-')
        i++;

    if (i>= token.length())
        return false;

    for(; i < token.length(); i++){
        if(!std::isdigit(token[i]))
            return false;
    }
    return true;
}

void RPN::doOperation(const std::string& op){
    if(_store.size() < 2)
        throw RPNException();
    
    double b = _store.top();
    _store.pop();
    double a = _store.top();
    _store.pop();

    double res;
    if (op == "+")
        res = a + b;
    else if (op == "-")
        res = a - b;
    else if (op == "*")
        res = a * b;
    else if (op == "/"){
        if (b == 0)
            throw RPNException();
        else
            res = a / b;
    }
    else
        throw RPNException();
    std::cout << "DEBUG: Result = " << res << std::endl;
    
    _store.push(res);
}

double RPN::evaluate(const std::string& expression){
    while (!_store.empty())
        _store.pop();
    
    std::istringstream iss(expression);
    std::string token;

    while(iss >> token)
    {
        std::cout << "DEBUG: Token = '" << token << "'" << std::endl;
        if (isNumber(token))
        {
            double num = std::strtod(token.c_str(), NULL);
            _store.push(num);
            std::cout << "DEBUG: Pushed " << num << std::endl;
        }
        else if (isOperator(token))
        {
            doOperation(token);
        }
        else
        {
            std::cout << "DEBUG: Invalid token!" << std::endl;
            throw RPNException();
        }
    }

    std::cout << "DEBUG: Final stack size = " << _store.size() << std::endl;

    if (_store.size() != 1)
        throw RPNException();

    return _store.top();
}

const char* RPN::RPNException::what() const throw() {
    return "Error";
}