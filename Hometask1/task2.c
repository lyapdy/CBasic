/*Задание 2. Инверсия старших
На вход программе подается беззнаковое 32-битное целое число N. Требуется
изменить значения всех битов старшего байта числа на противоположные и
вывести полученное таким образом число.
Данные на входе: Беззнаковое 32-битное целое число N
Данные на выходе: Одно целое число.
Пример №1
Данные на входе: 1
Данные на выходе: 4278190081
Пример №2
Данные на входе: 4278190081
Данные на выходе: 1*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int dec_to_bin(x)

{
    int i;
    for (i = 31; i >= 0; --i)
    {
        printf("%" PRIu32, x >> i & 1);
    }
    printf("\n");
    return 0;
}

int main()
{
    uint32_t N;
    uint32_t mask = ~0;
    uint32_t res;
    scanf("%u", &N);
    uint32_t inv_old_digit = N >> 24;
    inv_old_digit = ~inv_old_digit;
    inv_old_digit = inv_old_digit << 24;
    mask = mask >> 8;
    res = N & mask | inv_old_digit;
    dec_to_bin(inv_old_digit);
    dec_to_bin(N);
    dec_to_bin(res);
    printf("%u", res);
    return 0;
}
