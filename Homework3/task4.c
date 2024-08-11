/*Задача 4. Какое время года
Ввести номер месяца и вывести название времени года.
Данные на входе: Целое число от 1 до 12 - номер месяца.
Данные на выходе: Время года на английском: winter, spring, summer, autumn
Пример №1
Данные на входе: 4
Данные на выходе: spring
Пример №2
Данные на входе: 1
Данные на выходе: winter*/

#include <stdio.h>

int main() {
	
    int month;
    scanf("%d", &month);
    
    if (month == 12 || month == 1 || month == 2) {
        printf("winter");
    } else if (month == 3 || month == 4 || month == 5) {
        printf("spring");
    } else if (month == 6 || month == 7 || month == 8) {
        printf("summer");
    } else if (month == 9 || month == 10 || month == 11) {
        printf("autumn");
    } else {
		printf("Out of range");
	}
	
    return 0;
}