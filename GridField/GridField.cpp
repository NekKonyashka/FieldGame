#include <iostream>
#include <random>

const char HEIGHT = 15;
const char WIDTH = 15;
int position_y = 0;
int position_x = 0;
int pos_hammer_x = 0;
int pos_hammer_y = 0;
const char _symbol = '@';
const char _hammer = '!';
char Field[HEIGHT][WIDTH];
bool is_end = false;

void fill();
void reset();
void show();
void spawnSymbol(int *pos_x,int *pos_y,const char c);
void changePosition(int x,int y,const char c);
bool checkHammer();
bool checkPositionX(int pos_x);
bool checkPositionY(int pos_y);
void throwHammer();

int main()
{
    fill();
    spawnSymbol(&position_x,&position_y,_symbol);
    spawnSymbol(&pos_hammer_x, &pos_hammer_y,_hammer);
    reset();

    char movement;
    while (!is_end) {
        scanf_s("%c", &movement);
        switch (movement) {
        case 'w':
            if (position_y != 0) {
                --position_y;
                if (checkHammer()) {
                    if (pos_hammer_y != 0) {
                        --pos_hammer_y;
                    }
                    else
                    {
                        ++position_y;
                    }
                }
            }
            break;
        case 'a':
            if (position_x != 0) {
                --position_x;
                if (checkHammer()) {
                    if (pos_hammer_x != 0) {
                        --pos_hammer_x;
                    }
                    else
                    {
                        ++position_x;
                    }
                }

            }
            break;
        case 's':
            if (position_y != HEIGHT - 1) {
                ++position_y;
                if (checkHammer()) {
                    if (pos_hammer_y != HEIGHT - 1) {
                        ++pos_hammer_y;
                    }
                    else {
                        --position_y;
                    }
                }
            }
            break;
        case 'd':
            if (position_x != WIDTH - 1) {
                ++position_x;
                if (checkHammer()) {
                    if (pos_hammer_x != WIDTH - 1) {
                        ++pos_hammer_x;
                    }
                    else {
                        --position_x;
                    }
                }
            }
            break;
        case '1':
            is_end = true;
        case 'r':
            fill();
            spawnSymbol(&position_x, &position_y, _symbol);
            spawnSymbol(&pos_hammer_x, &pos_hammer_y, _hammer);
            reset();
            break;
        case ' ':
            throwHammer();
        }


        system("cls");
        reset();
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
    changePosition(position_x, position_y, _symbol);
    changePosition(pos_hammer_x, pos_hammer_y, _hammer);
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
void spawnSymbol(int *pos_x,int *pos_y,const char symbol) {
    srand(time(NULL));
    int x, y;
    do {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2 ) + 1;
    } while (Field[y][x] != '.');
    *pos_y = y;
    *pos_x = x;
    changePosition(x, y, symbol);
}
void changePosition(int pos_x,int pos_y,const char symbol) {
    Field[pos_y][pos_x] = symbol;
}
bool checkHammer() {
    if (position_x == pos_hammer_x && position_y == pos_hammer_y) {
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
void throwHammer() {
    if (position_x == pos_hammer_x && checkPositionY(position_y)) {
        pos_hammer_y = abs(pos_hammer_y - position_y * 2);
    }
    else if (position_y == pos_hammer_y && checkPositionX(position_x)) {
        pos_hammer_x = abs(pos_hammer_x - position_x * 2);
    }
}



