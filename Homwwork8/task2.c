/*������ 2. ������ � ������
�������� ������ ���� �������, ������� ������ � ������ ������� ��� ������
��������, � � ����� � ��� ��������. �� ��������� ������� ���������� �����
����� �����. ������ �������� ���������:
void sort_even_odd(int n, int a[])
������ �� �����: ������� ��������� �� ���� ����� �����
������ �� ������: ��������������� �������� ������
������ �1
������ �� �����: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
������ �� ������: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3
1
������ �2
������ �� �����: 1 0 1 0 1
������ �� ������: 0 0 1 1 1*/

/*#include <stdio.h>

int Input(int arr[], int n) // ������ ������
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}

void Print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/

void sort_even_odd(int n, int a[])
{
    int tmp;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            tmp = a[j];
            if (tmp % 2 != 0 && a[j + 1] % 2 == 0)
            {
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

/*int main()
{
    enum
    {
        BUFFER_SIZE = 20
    };
    int buffer[BUFFER_SIZE];
    Input(buffer, BUFFER_SIZE);
    sort_even_odd(BUFFER_SIZE, buffer);
    Print(buffer, BUFFER_SIZE);
    return 0;
}*/