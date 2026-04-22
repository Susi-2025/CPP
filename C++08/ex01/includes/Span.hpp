#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

class Span{
    private:
        unsigned int _size;
        std::vector<int> _store;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int value);

        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

        int shortestSpan() const;
        int longestSpan() const;

        unsigned int getSize() const;
};