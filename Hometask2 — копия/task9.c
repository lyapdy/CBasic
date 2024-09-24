#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>


int main(){
#define DIR_RIGHT 1
#define DIR_LEFT -1
#define DIR_UP 2
#define DIR_DOWN -2

int direction = 1;
char input;
int temp_dir = direction;

if (kbhit())
    input = getch(); // Проверка нажатия клавиши
else
    input = 0; // Откладываем значение нажатой клавиши

switch (input) // Определение значения направления и игнор противоположного
{
case 'P':
    if (direction == DIR_UP) //  Если даём движение наверх
        break;               // ничего не происходит
    temp_dir = DIR_DOWN;     // двигаемся вниз
    break;
case 'H':
    if (direction == DIR_DOWN)
        break;
    temp_dir = DIR_UP;
    break;
case 'K':
    if (direction == DIR_RIGHT)
        break;
    temp_dir = DIR_LEFT;
    break;
case 'M':
    if (direction == DIR_LEFT)
        break;
    temp_dir = DIR_RIGHT;
    break;
default:
    break;
}
return 0;
}