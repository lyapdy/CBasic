/*������ 6. ������������� �� a
� ����� .txt ���� �����������. ���������� ����������, ������� ����
������������� �� ����� '�'. ����� �������� � ���� .txt.
������ �� �����: ������ �� ���������� ���� � �������� �� ����� 1000
��������.
������ �� ������: ���� ����� �����
������
������ �� �����: Mama mila ramu
������ �� ������: 2*/

#include <stdio.h>
#include <string.h>
const int line_width = 1024;
int main(void)
{
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char line[line_width];
    FILE *file;

    int count = 0;
    file = fopen(input_file, "r");
    while (fscanf(file, "%s", line) == 1)
        if (line[strlen(line) - 1] == 'a')
            count++;
    fclose(file);
    file = fopen(output_file, "w");
    fprintf(file, "%d", count);
    fclose(file);
    return 0;
}