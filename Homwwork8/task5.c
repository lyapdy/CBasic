/*Задача 5. Поменять местами
Составить функцию, которая меняет в массиве минимальный и максимальный
элемент местами. Прототип функции
void change_max_min(int size, int a[])
Данные на входе: Функция принимает на вход размер массива и
массив чисел типа int
Данные на выходе: Функция не возвращает значения, измененный
массив сохраняется на месте исходного.
Пример
Данные на входе: 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 2 3 4 5 6 7 8 9 1*/

/*#include <stdio.h>

int Input(int arr[], int n) // вводим массив
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}

void Print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/

void change_max_min(int size, int a[])
{
    int min = a[0], max = a[0], min_index, max_index, tmp;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min) // для мин.
        {
            min = a[i];    // мин. элемент в массиве
            min_index = i; // индекс мин. элемента в массиве
        }

        else if (a[i] > max) // для макс.
        {
            max = a[i];    // макс. элемент в массиве
            max_index = i; // индекс макс. элемента в массиве
        }

        tmp = a[min_index];          // значение мин.индекса сохраняем в переменную tmp
        a[min_index] = a[max_index]; // макс. индекс присваиваем мин.индекс.
        a[max_index] = tmp;
    }
}

/*int main()
{
    enum
    {
        BUFFER_SIZE = 10
    };
    int buffer[BUFFER_SIZE];
    Input(buffer, BUFFER_SIZE);
    change_max_min(BUFFER_SIZE, buffer);
    Print(buffer, BUFFER_SIZE);
    return 0;
}*/