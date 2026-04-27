#pragma once

#include <stack>
#include <string>
#include <exception>

class RPN{
    private:
        std::stack<double> _store;
        
        bool isOperator(const std::string& token) const;
        bool isNumber(const std::string& token) const;
        void doOperation(const std::string& op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        double evaluate(const std::string& expression);

        class RPNException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};