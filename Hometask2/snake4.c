#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#define MAX_X 15
#define MAX_Y 15


typedef struct tail_t
{
    int x;
    int y;
} tail_t;

typedef struct snake_t
{
    int x;
    int y;
    struct tail_t *tail;
    size_t tsize;
    char direction;
} snake_t;
//--> x
// || y
// \/

//@**

typedef struct food_t
{
    int x;
    int y;
    size_t tsize;
} food_t;


struct snake_t initSnake(int x, int y, size_t tsize)
{
    struct snake_t snake;
    snake.x = x;
    snake.y = y;
    snake.tsize = tsize;
    snake.tail = (tail_t *)malloc(sizeof(tail_t) * 100);
    for (int i = 0; i < tsize; ++i)
    {
        snake.tail[i].x = x + i + 1;
        snake.tail[i].y = y;
    }
    return snake;
}

void printSnakeFood(struct snake_t snake, struct food_t food)
{
    char matrix[MAX_X][MAX_Y];
    for (int i = 0; i < MAX_X; ++i)
    {
        for (int j = 0; j < MAX_Y; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
    matrix[snake.x][snake.y] = '@';
    matrix[food.x][food.y] = '#';
    for (int i = 0; i < snake.tsize; ++i)
    {
        matrix[snake.tail[i].x][snake.tail[i].y] = '*';
    }
    for (int j = 0; j < MAX_Y; ++j)
    {
        for (int i = 0; i < MAX_X; ++i)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

struct food_t initFood(int x, int y)
{
    struct food_t food;
    food.x = x;
    food.y = y;    
    return food;
}


snake_t moveLeft(snake_t snake)
{
    for (int i = snake.tsize - 1; i > 0; i--)
    {
        snake.tail[i] = snake.tail[i - 1];
    }
    snake.tail[0].x = snake.x;
    snake.tail[0].y = snake.y;

    snake.x = snake.x - 1;
    if (snake.x < 0)
    {
        snake.x = MAX_X - 1;
    }
    return snake;
}

snake_t moveRight(snake_t snake)
{
    for (int i = snake.tsize - 1; i > 0; i--)
    {
        snake.tail[i] = snake.tail[i - 1];
    }
    snake.tail[0].x = snake.x;
    snake.tail[0].y = snake.y;

    snake.x = snake.x + 1;
    if (snake.x > MAX_X)
    {
        snake.x = 0 + 1;
    }
    return snake;
}

snake_t moveUp(snake_t snake)
{
    for (int i = snake.tsize - 1; i > 0; i--)
    {
        snake.tail[i] = snake.tail[i - 1];
    }
    snake.tail[0].x = snake.x;
    snake.tail[0].y = snake.y;

    snake.y = snake.y - 1;
    if (snake.y < 0)
    {
        snake.y = MAX_Y - 1;
    }
    return snake;
}

snake_t moveDown(snake_t snake)
{
    for (int i = snake.tsize - 1; i > 0; i--)
    {
        snake.tail[i] = snake.tail[i - 1];
    }
    snake.tail[0].x = snake.x;
    snake.tail[0].y = snake.y;

    snake.y = snake.y + 1;
    if (snake.y > MAX_Y)
    {
        snake.y = 0 + 1;
    }
    return snake;
}



snake_t snakeMotion(snake_t snake, food_t food, int c)
{
    while (1)
    {
        if (kbhit())
        {
            c = getch();
        }
        switch (c)
            {
            case 'W':
            case 'w':
                snake = moveUp(snake);
                break;

            case 'A':
            case 'a':
                snake = moveLeft(snake);
                break;

            case 's':
            case 'S':
                snake = moveDown(snake);
                break;

            case 'D':
            case 'd':
                snake = moveRight(snake);
                break;
            }
            sleep(1);
            
            system("cls");              
            printSnakeFood(snake, food);
             
            }   
}



int main()
{
    struct snake_t snake = initSnake(10, 5, 2);
    struct food_t food = initFood(13, 7);
    //struct snake_t direction = snakeMotion(snake, food, "L");

    printSnakeFood(snake, food);

    char ch = 'a';

        snakeMotion(snake, food, ch);
            return 0;
}

