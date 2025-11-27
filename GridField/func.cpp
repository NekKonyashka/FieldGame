#include "functions.h"
#include <random>


void play(char c)
{
    switch (c) {
    case 'w':
        if (symbol_pos.y != 0) {
            --symbol_pos.y;
            if (checkHammer()) {
                if (hammer_pos.y != 0) {
                    --hammer_pos.y;
                }
                else
                {
                    ++symbol_pos.y;
                }
            }
        }
        break;
    case 'a':
        if (symbol_pos.x != 0) {
            --symbol_pos.x;
            if (checkHammer()) {
                if (hammer_pos.x != 0) {
                    --hammer_pos.x;
                }
                else
                {
                    ++symbol_pos.x;
                }
            }

        }
        break;
    case 's':
        if (symbol_pos.y != HEIGHT - 1) {
            ++symbol_pos.y;
            if (checkHammer()) {
                if (hammer_pos.y != HEIGHT - 1) {
                    ++hammer_pos.y;
                }
                else {
                    --symbol_pos.y;
                }
            }
        }
        break;
    case 'd':
        if (symbol_pos.x != WIDTH - 1) {
            ++symbol_pos.x;
            if (checkHammer()) {
                if (hammer_pos.x != WIDTH - 1) {
                    ++hammer_pos.x;
                }
                else {
                    --symbol_pos.x;
                }
            }
        }
        break;
    case '1':
        is_end = true;
    case 'r':
        fill();
        spawnSymbol(symbol_pos, _symbol);
        spawnSymbol(hammer_pos, _hammer);
        reset();
        break;
    case ' ':
        throwHammer(hammer_pos, symbol_pos);
    }
}
void fill() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Field[i][j] = '.';
        }
    }
}
void reset() {
    fill();
    changePosition(symbol_pos, _symbol);
    changePosition(hammer_pos, _hammer);
    show();
}
void show() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", Field[i][j]);
        }
        printf("\n");
    }
}
void spawnSymbol(Point& pos, const char symbol) {
    srand(time(NULL));
    int x, y;
    do {
        x = rand() % (WIDTH - 1);
        y = rand() % (HEIGHT - 1);
    } while (Field[y][x] != '.');
    pos.y = y;
    pos.x = x;
    changePosition(pos, symbol);
}
void changePosition(Point pos, const char symbol) {
    Field[pos.y][pos.x] = symbol;
}
bool checkHammer() {
    if (symbol_pos.x == hammer_pos.x && symbol_pos.y == hammer_pos.y) {
        return true;
    }
    return false;
}
bool checkPositionX(int pos_x) {
    if (pos_x != 0 && pos_x != WIDTH - 1) {
        return true;
    }
    return false;
}
bool checkPositionY(int pos_y) {
    if (pos_y != 0 && pos_y != HEIGHT - 1) {
        return true;
    }
    return false;
}
void throwHammer(Point& pos, Point main) {
    if (main.x == pos.x && checkPositionY(main.y)) {
        pos.y = abs(pos.y - main.y * 2);
    }
    else if (main.y == pos.y && checkPositionX(main.x)) {
        pos.x = abs(pos.x - main.x * 2);
    }
}