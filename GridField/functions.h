#pragma once
#include "Point.h"

const char HEIGHT = 15;
const char WIDTH = 15;
const char WALL_COUNT = 10;
extern Point symbol_pos;
extern Point hammer_pos;
extern const char _symbol;
extern const char _hammer;
extern const char _wall;
extern char Field[HEIGHT][WIDTH];
extern Point Walls[WALL_COUNT];
extern bool is_end;

void fill();
void reset();
void show();
void spawnSymbol(Point& pos, const char c);
void changePosition(Point pos, const char c);
bool checkHammer();
bool checkPositionX(int pos_x);
bool checkPositionY(int pos_y);
void throwHammer(Point& pos, Point main_pos);
void play(char move);
void spawnWalls();
void setWalls();
bool isCollider(Point pos);
void deleteWall();
void findWall();
