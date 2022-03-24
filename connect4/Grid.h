#pragma once
#include <vector>

enum Coins : char16_t {X = 'X', O = 'O', empty = ' '};

struct Grid
{
public:
	const size_t WIDTH;
	const size_t HEIGHT;
	std::vector<char16_t> places;

	//not allowed to make a default board, must specify size
	Grid() = delete;

	//main constructor
	//requires grid height and width;
	//standard Connect4 grid: 6 tall 7 wide
	Grid(const size_t WIDTH,  const size_t HEIGHT);

	//copy constructor
	//performs a deep copy when copying
	Grid(const Grid& obj);


	bool checkWin(Coins& winner);
	Coins* at(int x, int y);
};
