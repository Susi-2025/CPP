#include "Span.hpp"
#include <algorithm>

Span::Span(): _size(0), _store() {}

Span::Span(unsigned int N): _size(N), _store(){
    _store.reserve(N);
}

Span::Span(const Span& other): _size(other._size), _store(other._store) {}

Span& Span::operator=(const Span& other){
    if (this != &other){
        _size = other._size;
        _store = other._store;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int value){
    if(_store.size() >= _size)
        throw std::runtime_error("Span is already full!!!");
    else
        _store.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
  for (std::vector<int>::iterator it = begin; it != end; ++it)
        addNumber(*it);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    for (std::vector<int>::const_iterator it = begin; it != end; ++it)
        addNumber(*it);
}

int Span::shortestSpan() const{
    if(_store.size() < 2){
        throw std::runtime_error("Not enough elements to find a span");
    }

    std::vector<int> sorted = _store;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];

    for(size_t i = 2; i < sorted.size(); i++){
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan){
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const{
    if (_store.size() < 2){
        throw std::runtime_error("Not enough elements to find a span");
    }

    int min = *std::min_element(_store.begin(), _store.end());
    int max = *std::max_element(_store.begin(), _store.end());

    return (max - min);
}

unsigned int Span::getSize() const {
    return _size;
}
