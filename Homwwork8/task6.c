/*Задача 6. Больше среднего
Определить количество положительных элементов квадратной матрицы,
превышающих по величине среднее арифметическое всех элементов главной
диагонали. Реализовать функцию среднее арифметическое главной
диагонали.
Данные на входе: 5 строк по 5 целых чисел через пробел
Данные на выходе: Одно целое число
Пример
Данные на входе: 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
Данные на выходе: 10*/

#include <stdio.h>

int sum_diagonal(int SIZE, int a[SIZE][SIZE])
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum = sum + a[i][i];
    return sum;
}

void set_mass(int SIZE, int a[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &a[i][j]);
    }
}

int main()
{
    int SIZE = 5;
    int a[SIZE][SIZE];
    set_mass(SIZE, a);
    int average = (sum_diagonal(SIZE, a)) / SIZE;
    int count_max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (a[i][j] > average)
                count_max++;
        }
    }
    printf("%d", count_max);
    return 0;
}