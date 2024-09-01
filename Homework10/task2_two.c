/*������ 2. ������� ������� �� ������
� ����� .txt ���������� ������� ��� ������ ������� (� ������ �����������
� ��������� �������). ��� ������� ������ ����������� �������. ���������
�������� � .txt.
������ �� �����: ������ �� ���������� ����, ������ ���������� �
��������. �� ����� 1000 ��������.
������ �� ������: ������ �� ���������� ����, ������ ���������� �
��������.
������
������ �� �����: Hello world!
������ �� ������: Hello world!*/

#include <stdio.h>
#include <string.h>
enum States
{
    Start,
    In,
    Out
};

int main()
{
    FILE *file_in = fopen("input.txt", "r");
    FILE *file_out = fopen("output.txt", "w");
    int c, state = Start;
    while (c = fgetc(file_in) != EOF)
    {
        switch (state)
        {
        case Start:
            if (c != ' ')
            {
                state = In;
                fputc(c, file_out);
            }
            break;

        case In:
            if (c == ' ')
                state = Out;
            else
                fputc(c, file_out);
            break;
        case Out:
            if (c != ' ')
            {
                state = In;
                fputc(' ', file_out);
                fputc(c, file_out);
            }
            break;
        }
    }
    fclose(file_in);
    fclose(file_out);
    return 0;
}