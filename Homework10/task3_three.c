/*Задача 3. Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.htm*/

#include <stdio.h>
#include <string.h>

#define SIZE 10001

void input(char *strIn)
{
    FILE *in;
    in = fopen("input.txt", "r");
    while (fscanf(in, "%[^\n]", strIn) == 1)
        ;
    fclose(in);
}

void extension(char *strExt, char *buffer)
{
    for (int i = strlen(strExt) - 1; i >= 0; i--)
    {
        if (strExt[i] == '/')
        {
            strcpy(buffer, strExt);
            strcat(buffer, ".html");
            break;
        }
        else if (strExt[i] == '.')
        {
            for(int j = 0; j < i; j++)
            buffer[j] = strExt[j];
            memcpy(buffer, strExt, i);
            strcat(buffer, ".html");
            break;
        }
    }
}

void output(char *strOut)
{
    FILE *out;
    out = fopen("output.txt", "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main(int argc, char **argv)
{
    char str[SIZE], strFinal[SIZE];
    input(str);
    extension(str, strFinal);
    output(strFinal);
    return 0;
}
