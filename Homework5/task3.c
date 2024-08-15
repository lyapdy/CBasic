/*Задача 3. Сумма цифр равна произведению
Составить логическую функцию, которая определяет, верно ли, что в заданном
числе сумма цифр равна произведению.
int is_happy_number(int n)
Данные на входе: Целое не отрицательное число
Данные на выходе: YES или NO
Пример №1
Данные на входе: 123
Данные на выходе: YES
Пример №2
Данные на входе: 528
Данные на выходе: NO*/

#include <stdio.h>
int is_happy_number(int n)
{
int sum = 0, mul = 1;
    while (n > 0)
    {
        sum += n % 10;
        mul *= n % 10;
        n /= 10;
    }
    return (sum == mul);
}

int main()
{
int n;
    scanf("%d", &n);
    if (is_happy_number(n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    //is_happy_number(n) ? printf("YES") : printf("NO");
    return 0;
}
