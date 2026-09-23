#pragma once

class Equipment
{
public:
    Equipment(int h)
        : Hp_ { };

protected:
    int Hp_;
};

class Conehead : public Equipment
{
    Conehead(int h)
        : Equipment(h) { };
};
