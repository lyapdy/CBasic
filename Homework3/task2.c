/*Задача 2. Наименьшее из пяти чисел
Ввести пять чисел и вывести наименьшее из них
Нужно напечатать наименьшее число
Данные на входе: Пять целых чисел разделенных пробелом
Данные на выходе: Одно целое число
Данные на входе: 4 15 9 56 4
Данные на выходе: 4*/

#include <stdio.h>

int main() {
	
    int a, b, c, d, e, min;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    min = a;
    
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    if (d < min) {
        min = d;
    }
    if (e < min) {
        min = e;
    }
    
    printf("%d", min);
    
    return 0;
}