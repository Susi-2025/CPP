#include "iter.hpp"

template<typename T>
void print_out(const T& value){
    std::cout << value << std::endl;
}

template<typename T>
void modify_print(T& value){
    value += 1;
    std::cout << "new value: " << value << std::endl;
}

void modify_print(std::string&& value){
    value += "!";
    std::cout << "new value: " << value << std::endl;
}

int main(){
    std::cout << "TEST WITH INT ARR" << std::endl;
    int arr[] = {0,2,4,6,10};
    iter(arr, 5, print_out<int>);
    std::cout << "Modify" << std::endl;
    iter(arr, 5, modify_print<int>);

    std::cout << "TEST WITH STR ARR" << std::endl;
    std::string s[] = {"hello", "hive"};
    iter(s, 2, print_out<std::string>);
    std::cout << "Modify" << std::endl;
    iter(s, 2, modify_print<std::string>);
    return 0;
}