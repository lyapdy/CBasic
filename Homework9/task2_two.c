/*Задача 2. Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо
заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
строчные. Результат записать в .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов.
Данные на выходе: Строка из маленьких и больших английских
букв, знаков препинания и пробелов.
Пример
Данные на входе: aabbccddABCD
Данные на выходе: bbaaccddBACD*/

#include <stdio.h>
#include <string.h>
const int line_width = 1024;
int main(void)
{
    char *input_fn = "input.txt";
    char *output_fn = "output.txt";
    char line[line_width];
    FILE *fp;
    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);
    char c;
    int i = 0;
    while ((c = line[i]) != '\0')
    {
        if ((c == 'a') || (c == 'A'))
            line[i] += 1;
        else if ((c == 'b') || (c == 'B'))
            line[i] -= 1;
        i++;
    }
    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", line);
    fclose(fp);
    return 0;
}