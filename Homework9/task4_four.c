/*Задача 4. Удалить повторяющиеся символы
В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов. Размер строки не более 1000 символов.
Данные на выходе: Строка из маленьких и больших английских
букв.
Пример
Данные на входе: abc cde def
Данные на выходе: abcdef*/

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