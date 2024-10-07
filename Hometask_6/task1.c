/*
������� 1. ����� ������� � ���������� �����
��������� ��� ������ 1, �������� ��������� ������ ������� � ����������
����� � ������.
������ �1
������ �� �����: efg abcd zzz.
������ �� ������: efg zzz.
������ �2
������ �� �����: fffff kkkkkk a.
������ �� ������: fffff a.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 1000 // ������, ������������ ������ ������

typedef struct list // ���������� ��������� ������, ������� ���������
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
				i = 0; // ������ �� ������������ ������
		}
		if ('.' == ch) // ����� ����� ������ ����� ��������� �����
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
		free(c->word); // ����������� ����� ��� �����
		free(c);
		c = n;
	}
}

void invert_list(list **head) // �������, ������� �����������
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
	list *result = (list *)calloc(1, sizeof(list)); // �������� ������ ��� ������ ��������� list
	int len = strlen(value);	 // ���������� ������ ������
	result->word = malloc(len + 1); // �������� ������ ��� ������
	strcpy(result->word, value);	 // �������� ������ � ������
	result->next = head;			 // ������� ��������� 
	return result;					// ���������� ���������
}

void print_list(list *head)
{
	for (list *i = head; i != NULL; i = i->next)
		printf("%s ", i->word);
	putchar('\n');
}

void print_first_last(list *head) // �������� ������ � ��������� �����
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

