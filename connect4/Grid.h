#pragma once

enum Coins : char16_t {X = 'X', O = 'O', empty = ' '};

struct Grid
{
public:
    const unsigned int WIDTH;
    const unsigned int HEIGHT;
    Coins* places;
    
    Grid() = delete;
    Grid(const unsigned int WIDTH,  const unsigned int HEIGHT);

    bool checkWin(Coins& winner);
    Coins* at(int x, int y);
};
