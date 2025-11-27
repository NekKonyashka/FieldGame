#include <iostream>
#include "functions.h"

bool is_end = false;
char Field[HEIGHT][WIDTH];
Point Walls[WALL_COUNT];
const char _symbol = '@';
const char _hammer = '!';
const char _wall = '#';
Point symbol_pos;
Point hammer_pos;

void fill();
void reset();
void show();
void spawnSymbol(Point &pos,const char c);
void changePosition(Point pos,const char c);
bool checkHammer();
bool checkPositionX(int pos_x);
bool checkPositionY(int pos_y);
void throwHammer(Point &pos,Point main_pos);
void play(char move);
void spawnWalls();

int main()
{
    fill();
    spawnWalls();
    spawnSymbol(symbol_pos, _symbol);
    spawnSymbol(hammer_pos, _hammer);
    reset();

    char movement;
    while (!is_end) {
        scanf_s("%c", &movement);
        play(movement);
        system("cls");
        reset();
    }

}