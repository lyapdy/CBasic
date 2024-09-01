/*Задача 1. Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe*/

#include <stdio.h>
#include <string.h>
const int line_width = 1024;
void sym_exchange(int size, char *line)
{
    int i = 0, j;
    char b;
    while (i < size)
    {
        while (line[i] == ' ') // пропускаем пробелы
            i++;

        j = i + 1; // позиция без пробела
        while (line[j] == ' ')
            j++;
        if (j >= size) // проверка выхода за границу
            break;
        // меняем местами
        b = line[i];
        line[i] = line[j];
        line[j] = b;
        // следующий символ
        i = j + 1;
    }
}
int main(void)
{
    char *input_fn = "input.txt";
    char *output_fn = "output.txt";
    char line[line_width];
    FILE *fp;
    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);
    sym_exchange(strlen(line), line);
    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", line);
    fclose(fp);
    return 0;
}