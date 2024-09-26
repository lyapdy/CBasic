/*Задание 2. Обратная польская запись
Написать алгоритм перевода из инфиксной записи в обратную польскую. Для
его реализации нужны данные по приоритетам операций. Реализовать
алгоритм, используя побитовые операции (&, |, ^).
Пример №1
Данные на вход: ( 3 & 5 ) ^ 4 | 9
Данные на выход: 3 5 & 4 ^ 9 |
Пример №2
Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 )
Данные на выход: 8 2 5 & ^ 6 1 & |*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BUFFER_SIZE 255
#define STACK_SIZE 255

char oper[STACK_SIZE] = {0};
int oend = 0;

void push(char v)
{
	oper[oend++] = v;
}

char pop() // выталкиваем значение из стека
{
	if (oend <= 0 || oend >= STACK_SIZE)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	return oper[--oend];
}

_Bool emptyStack() // очищаем стек
{
	return oend == 0;
}

_Bool isOperator(char c) // функция возвращает логическое значение является ли символ логическим оператором
{
	return c == '&' || c == '^' || c == '|';
}

int priority(char c) // приоритет логических операторов: 3 - самый высокий
{
	if (c == '&')
	{
		return 3;
	}
	else if (c == '^')
	{
		return 2;
	}
	else if (c == '|')
	{
		return 1;
	}

	return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // русский язык нужен
	char c; // символьная переменная с
	int pos = 0;
	char answer[BUFFER_SIZE] = {0};
	printf("Введите логическое выражение в стандартном виде: ");
	char str[1000];

	int len = 0;
	while ((c = getchar()) != '\n') // пока не перешли на следующую строку
	{
		str[len++] = c; // добавляем в переменную str вводимый символ
	}
	str[len] = '\0'; // заканчиваем строку меткой 0

	for (int i = 0; i < len; i++) // проходим по всей переменной str
	{
		if (str[i] >= '0' && str[i] <= '9') // если имеем дело с цифрой в диапазоне от 0 до 9
		{
			int number, size = 0;
			for (number = 0; str[i] >= '0' && str[i] <= '9'; i++, size++) // для числа в диапазоне от 0 до 9 расширяем размер переменно str
			{
				number = number * 10 + (str[i] - '0');
			}
			sprintf(answer + pos, "%d", number); //печатаем цифру
			pos += size + 1;
		}
		else
		{
			if (i >= len) // если i больше длины str
			{
				break; // останавливаем цикл
			}
			c = str[i];
			if (isOperator(c)) // является ли i-ый символ строки оператором 
			{
				while (!emptyStack()) // если стек не пустой
				{
					char top = pop(); // выталкиваем значение из стека
					if (priority(top) >= priority(c)) // условие приоритета
					{
						sprintf(answer + pos, "%c", top); // печатаем вытолкнутое из стека значение
						pos += 2;
					}
					else // иначе
					{
						push(top); // заталкиваем в стек значение
						break;
					}
				}
				push(c);
			}
			else if (c == '(') // работаем со скобками
			{
				push(c);
			}
			else if (c == ')') // работаем со скобками
			{
				while ((c = pop()) != '(')
				{
					sprintf(answer + pos, "%c", c);
					pos += 2;
				}
			}
		}
	}

	while (!emptyStack()) // пока в стеке что-то есть
	{
		char c = pop(); // выталкиваем верхнее значение из стека
		sprintf(answer + pos, "%c", c); //печатаем это значение на соответствующей позиции
		pos += 2; // меняем позицию в очереди печати строки
	}
	printf("Логическое выражение в польском варианте: ");
	for (int i = 0; i < pos; i++)
	{
		printf("%c", answer[i]);
	}

	return 0;
}