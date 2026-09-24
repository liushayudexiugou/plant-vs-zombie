#pragma once
#include <string>
using namespace std;

class Equipment
{
public:
    Equipment(string n, int h)
        : Name_(n), Hp_(h) {};

protected:
    string Name_;
    int Hp_;
};

class Conehead : public Equipment
{
    Conehead(string n, int h)
        : Equipment(n, h) { };
};
