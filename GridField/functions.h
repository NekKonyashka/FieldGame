#pragma once
#include "Point.h"
#include "field.h"
#include <conio.h>

extern Point symbol_pos;
extern Point hammer_pos;
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
