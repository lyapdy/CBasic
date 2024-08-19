/*Задача 2. Найти минимум
Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
Данные на входе: 5 целых чисел через пробел
Данные на выходе: Одно единственное целое число
Пример №1
Данные на входе: 4 15 3 10 14
Данные на выходе: 3
Пример №2
Данные на входе: 1 2 3 4 -5
Данные на выходе: -5*/

#include <stdio.h>
int Input(int arr[], int n) // вводим массив
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}
void Print(int arr[], int len) // печатаем массив
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void Right_shift(int arr[], int len) // делаем сдвиг вправо на 4 элемента
{
    int temp;
    temp = arr[len - 1];
    for (int i = len - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}
int main()
{
    enum
    {
        BUFFER_SIZE = 12
    };
    int buffer[BUFFER_SIZE];
    Input(buffer, BUFFER_SIZE);
    for (int i = 0; i < 4; i++)
        Right_shift(buffer, BUFFER_SIZE);
    Print(buffer, BUFFER_SIZE);
    return 0;
}