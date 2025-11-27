#pragma once
#include "Point.h"

const char HEIGHT = 15;
const char WIDTH = 15;
extern Point symbol_pos;
extern Point hammer_pos;
extern const char _symbol;
extern const char _hammer;
extern char Field[HEIGHT][WIDTH];
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
