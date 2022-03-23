#pragma once

enum coins : char16_t {X = 'X', O = 'O', empty = ' '};

struct Grid
{
public:
    const unsigned int WIDTH;
    const unsigned int HEIGHT;
    
    Grid() = delete;
    Grid(const unsigned int WIDTH,  const unsigned int HEIGHT);
};
