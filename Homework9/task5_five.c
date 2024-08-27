/*������ 5. ����� ������� �����
� ����� .txt ���� ������ ����, ����������� ���������. ����� ����� �������
����� � ������� ��� � ���� .txt. ������, ����� ����� ������� ���� ����� ����
���������, �� ������������.
������ �� �����: ������ �� ���������� ���� � ��������. �� �����
1000 ��������.
������ �� ������: ���� ����� �� ���������� ����.
������
������ �� �����: Hello beautiful world
������ �� ������: beautiful*/

#include <stdio.h>
#include <string.h>
const int line_width = 1024;
int main(void)
{
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char line[line_width];
    char result[line_width];
    FILE *file;
    int len, max_len = 0;
    file = fopen(input_file, "r");

    while (fscanf(file, "%s", line) == 1)
    {
        len = strlen(line);
        if (len > max_len)
        {
            max_len = len;
            strcpy(result, line);
        }
    }
    fclose(file);
    file = fopen(output_file, "w");
    fprintf(file, "%s", result);
    fclose(file);
    return 0;
}