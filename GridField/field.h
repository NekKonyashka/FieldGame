#pragma once
#include "Point.h"

#define HEIGHT 15
#define WIDTH 15

const char WALL_COUNT = 10;
extern Point Walls[WALL_COUNT];

extern const char _symbol;
extern const char _hammer;
extern const char _wall;
extern char Field[HEIGHT][WIDTH];