/*Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: Hello world!
Данные на выходе: Hello world!*/

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