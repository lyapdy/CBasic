/*������ 1. �� ������ ����
� ����� .txt ���� ��� ����� �� ����� 100 �������� ������, �����������
����� ��������. ������� ������ �� ������� ����, ������� ����������� �
����� ������ ������ ���� ���. ����������� �� ����� ������ � ���� .txt �
������������������ �������.
������ �� �����: ��� ����� �� ��������� ���������� ���� �����
������. ������ ������� ����� �� ������ 100 ��������.
������ �� ������: ��������� ���������� ����� ����� ������.
������ �1
������ �� �����: hello world
������ �� ������: o
������ �� �����: aabcd bcef
������ �� ������: b c*/

#include <stdio.h>
int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    FILE *file_in = fopen(name_in, "r");
    FILE *file_out = fopen(name_out, "w");
    char word1[100], word2[100];
    fscanf(file_in, "%s%s", word1, word2);
    int symbol1[26] = {0};
    int symbol2[26] = {0};
    int counter = -1;
    while (word1[++counter] != '\0')
        ++symbol1[word1[counter] - 'a'];
    counter = -1;
    while (word2[++counter] != '\0')
        ++symbol2[word2[counter] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (symbol1[i] == 1 && symbol2[i] == 1)
            fprintf(file_out, "%c ", i + 97);
    fclose(file_in);
    fclose(file_out);
    return 0;
}