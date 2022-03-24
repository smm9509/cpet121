#include "Grid.h"

Grid::Grid(const size_t WIDTH,  const size_t HEIGHT) 
: WIDTH(WIDTH), HEIGHT(HEIGHT) 
{
	places = std::vector<char16_t>(WIDTH*HEIGHT);
};

Grid::Grid(const Grid& obj)
: WIDTH(obj.WIDTH), HEIGHT(obj.HEIGHT)
{
	places = std::vector<char16_t>(obj.places);
}