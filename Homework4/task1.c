/*Домашнее задание №4
Задача 1. Сумма квадратов маленьких чисел
Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a
до b.
Данные на входе: Два целых числа по модулю не больше 100
Данные на выходе: Сумма квадратов от первого введенного числа до
второго
Пример №1
Данные на входе: 4 10
Данные на выходе: 371
Пример №2
Данные на входе: 1 5
Данные на выходе: 55*/

#include <stdio.h>

int main()

{
int a, b, sum;
scanf("%d%d", &a, &b);
    do
    {
        sum += a*a;
        a++;
    }
    while(a<=b);
printf("%d\n", sum);
return 0;
}