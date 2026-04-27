
#include "PMergeMe.hpp"
#include <climits>

PMergeMe::PMergeMe(){}

PMergeMe::PMergeMe(const PMergeMe& other): _vec(other._vec), _deq(other._deq){}

PMergeMe& PMergeMe::operator=(const PMergeMe& other){
    if (this != &other){
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PMergeMe:: ~PMergeMe() {}

void PMergeMe::fordJohnSort(std::vector<int>& arr){
    if (arr.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for(size_t i = 0; i + 1 < arr.size(); i += 2){
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    int odd = -1;
    if (arr.size() % 2 != 0)
        odd = arr.back();
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = i + 1; j < pairs.size(); j++){
            if (pairs[i].second > pairs[j].second)
            {
                std::pair<int, int> temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    std::vector<int> main;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); i++){
        main.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }

    fordJohnSort(main);

    if (pend.size() > 0)
        insertIntoMain(main, pend[0], 0);
    
    for(size_t i = 1; i < pend.size(); i++)
        insertIntoMain(main, pend[i], main.size() -1);

    if (odd != -1)
        insertIntoMain(main, odd, main.size() - 1);

    arr = main;
}

void PMergeMe::insertIntoMain(std::vector<int>& main, int value, int end){
    int left = 0;
    int right = end;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (main[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, value);
}

void PMergeMe::fordJohnSort(std::deque<int>& arr){
       if (arr.size() <= 1)
        return;
    
    std::deque<std::pair<int, int> > pairs;
    for(size_t i = 0; i + 1 < arr.size(); i += 2){
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    int odd = -1;
    if (arr.size() % 2 != 0)
        odd = arr.back();
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = i + 1; j < pairs.size(); j++){
            if (pairs[i].second > pairs[j].second)
            {
                std::pair<int, int> temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    std::deque<int> main;
    std::deque<int> pend;

    for (size_t i = 0; i < pairs.size(); i++){
        main.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }

    fordJohnSort(main);

    if (pend.size() > 0)
        insertIntoMain(main, pend[0], 0);
    
    for(size_t i = 1; i < pend.size(); i++)
        insertIntoMain(main, pend[i], main.size() -1);

    if (odd != -1)
        insertIntoMain(main, odd, main.size() - 1);

    arr = main;
}

void PMergeMe::insertIntoMain(std::deque<int>& main, int value, int end){
    int left = 0;
    int right = end;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (main[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, value);
}

bool PMergeMe::isValidNumber(const std::string& s) const{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++){
        if (!std::isdigit(s[i]))
            return false;
    }

    long num = std::strtol(s.c_str(), NULL, 10);
    if (num > INT_MAX || num < 0)
        return false;
        
    return true;
}


void PMergeMe::process(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        if (!isValidNumber(av[i]))
            throw InvalidArgumentExceptiion();
        int num = std::atoi(av[i]);

        for(int j = 1; j < i; j++)
        {
            if (std::atoi(av[j]) == num)
                throw InvalidArgumentExceptiion();
        }
        _vec.push_back(num);
        _deq.push_back(num);
    }

    if (_vec.size() <= 1)
        throw InvalidArgumentExceptiion();
    
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    fordJohnSort(_vec);
    clock_t endVec = clock();
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    fordJohnSort(_deq);
    clock_t endDeq = clock();
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() 
    << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
    << " elements with std::deque  : " << deqTime << " us" << std::endl;
}

const char* PMergeMe::InvalidArgumentExceptiion::what() const throw(){
    return "Error: invalid Argument";
}