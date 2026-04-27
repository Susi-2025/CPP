#pragma once

#include <vector>
#include <deque>
#include <exception>
#include <string>
#include <iostream>

class PMergeMe{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        void fordJohnSort(std::vector<int>& arr);
        void insertIntoMain(std::vector<int>& main, int value, int end);

        void fordJohnSort(std::deque<int>& arr);
        void insertIntoMain(std::deque<int>& main, int value, int end);

        bool isValidNumber(const std::string& s) const;
    public:
        PMergeMe();
        PMergeMe(const PMergeMe& other);
        PMergeMe& operator=(const PMergeMe& other);
        ~PMergeMe();

        void process(int ac, char** av);
        // void displayRes(double vecTime, double deqTime) const;

        class InvalidArgumentExceptiion: public std::exception{
            public: virtual const char* what() const throw ();
        };
};