#include "iter.hpp"

template<typename T>
void print_out(const T& value){
    std::cout << value << std::endl;
}

int main(){
    int arr[] = {0,2,4,6,10};
    iter(arr, 5, print_out<int>);

    std::string s[] = {"hello", "hive"};
    iter(s, 2, print_out<std::string>);
    return 0;
}