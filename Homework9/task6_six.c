/*Задача 6. Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000
символов.
Данные на выходе: Одно целое число
Пример
Данные на входе: Mama mila ramu
Данные на выходе: 2*/

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