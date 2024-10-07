/*
Задание 1. Поиск первого и последнего слова
Используя код задачи 1, написать программу поиска первого и последнего
слова в строке.
Пример №1
Данные на входе: efg abcd zzz.
Данные на выходе: efg zzz.
Пример №2
Данные на входе: fffff kkkkkk a.
Данные на выходе: fffff a.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 1000 // макрос, определяющий размер строки

typedef struct list // определяем структуру список, имеющую параметры
{
	char *word;
	struct list *next;
} list;

list *inserting(char *value, list *head);
void print_list(list *head);
void print_first_last(list *head);
void invert_list(list **head);
void delete_list(list *head);

int main(int argc, char **argv)
{
	list *w_list = NULL;
	char word[STR_SIZE] = "";
	int ch = ' ';
	int i = 0;
	while (EOF != (ch = getchar())) // EOF - end of file
	{
		switch (ch)
		{
		case '.': 
		case ' ':
			word[i] = '\0';
			w_list = inserting(word, w_list);
			i = 0;
			break;
		default:
			word[i++] = ch;
			if (i >= STR_SIZE)
				i = 0; // Защита от переполнения строки
		}
		if ('.' == ch) // после ввода строки нужно поставить точку
			break;
	}

	invert_list(&w_list);
	print_first_last(w_list);
	delete_list(w_list);

	return 0;
}

void delete_list(list *lst)
{
	list *c = lst;
	list *n;
	while (c != NULL)
	{
		n = c->next;
		free(c->word); // освобождаем место под слово
		free(c);
		c = n;
	}
}

void invert_list(list **head) // функция, которая инвертирует
{
	list *prev = NULL;
	list *current = *head;
	list *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}

list *inserting(char *value, list *head)
{
	list *result = (list *)calloc(1, sizeof(list)); // выделяем память под массив структуры list
	int len = strlen(value);	 // определяем размер строки
	result->word = malloc(len + 1); // выделяем память под строку
	strcpy(result->word, value);	 // копируем строку в память
	result->next = head;			 // смещаем указатель 
	return result;					// возвращаем результат
}

void print_list(list *head)
{
	for (list *i = head; i != NULL; i = i->next)
		printf("%s ", i->word);
	putchar('\n');
}

void print_first_last(list *head) // печатаем первое и последнее слово
{
	list *currentNode = head;
	printf("%s ", currentNode->word);
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

	printf("%s ", currentNode->word);
	putchar('\n');
}

