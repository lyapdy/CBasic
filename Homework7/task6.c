/*Задача 6. Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается
чаще всего. Гарантируется, что такое число ровно 1.
Данные на входе: 10 целых числе через пробел
Данные на выходе: Одно число, которое встречается чаще других.
Пример
Данные на входе: 4 1 2 1 11 2 34 11 0 11
Данные на выходе: 11*/

#include <stdio.h>
#define SIZE 10
int mostly(int *, int);
int Input(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}
int main()
{
    int in[SIZE];
    Input(in, SIZE);
    printf("%d ", mostly(in, SIZE));
    return 0;
}

int mostly(int *in, int len)
{
    int count[len];
    for (int i = 0; i < len; i++)
        count[i] = 0;
    int max = 0, numberMax = 0;
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (in[i] == in[j])
                count[i]++;
    for (int i = 0; i < len; i++)
        if (count[i] > max)
        {
            max = count[i];
            numberMax = i;
        }
    return in[numberMax];
}