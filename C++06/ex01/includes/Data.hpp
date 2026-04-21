#pragma once
#include <string>

struct Data{
    int id;
    std::string name;
    double value;

    Data() : id(0), name(""), value(0.0) {}
    Data(int i, const std::string& n, double v) : id(i), name(n), value(v) {}
};