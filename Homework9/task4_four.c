/*������ 4. ������� ������������� �������
� ����� .txt ������ �� ��������� � ������� ���������� ����, ������
���������� � ��������. ��������� ������� �� ��� ������������� ������� �
��� �������. ��������� �������� � ���� .txt.
������ �� �����: ������ �� ��������� � ������� ���������� ����,
������ ���������� � ��������. ������ ������ �� ����� 1000 ��������.
������ �� ������: ������ �� ��������� � ������� ����������
����.
������
������ �� �����: abc cde def
������ �� ������: abcdef*/

#include <stdio.h>
int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    FILE *file_in = fopen(name_in, "r");
    FILE *file_out = fopen(name_out, "w");
    char str1[1002];
    int j;
    char c;
    int i = -1;
    fgets(str1, 1000, file_in);

    while (str1[++i] != '\0')
    {
        c = str1[i];
        j = i;
        while (str1[++j] != '\0')
            if (str1[j] == c)
                str1[j] = ' ';
    }
    i = -1;
    while (str1[++i] != '\0')
        if (str1[i] != ' ')
            fprintf(file_out, "%c",
                    str1[i]);
    fclose(file_in);
    fclose(file_out);
    return 0;
}