#pragma once
#include <iostream>

template<typename T>
void iter(T* addr, const size_t size, void (*func)(T&)){
    for (size_t i = 0; i < size; i++){
       func(addr[i]);
    }
};

template<typename T>
void iter(T* addr, const size_t size, void (*func)(const T&)){
    for (size_t i = 0; i < size; i++){
        func(addr[i]);
    }
}