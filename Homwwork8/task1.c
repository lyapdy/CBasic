/*������ 1. ���������� �� �����������
�������� ������ ���� �������, ������� ��������� ������ �� �����������.
���������� ����������� ������ ���� �������, ��� ��������� ���������� ��
����.
������ �������� ���������. ��� ������� � ��� ��������� ������ ����:
void sort_array(int size, int a[])
��� ��������� ��������� �� ����, ������ ���� ��� �������. ����� ������
���������������� ����� ���� ���������, ����� ������ �������.
������ �� �����: ������� ��������� �� ����, ������ �������� - ������
�������, ������ �������� - ����� �������� ��������.
������ �� ������: ������� ������ �� ����������. ����������
���������� ����������� �� ������� �� �����������.
������ �1
������ �� �����: 20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
������ �� ������: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
������ �2
������ �� �����: 5 4 3 2 1
������ �� ������: 1 2 3 4 5*/

/*#include <stdio.h>
int Input(int arr[], int n) // ������ ������
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return i;
}*/

void sort_array(int size, int a[])
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < size; ++i)
    {
        for (j = i; j < size; ++j)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/*void Print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    enum
    {
        BUFFER_SIZE = 20
    };
    int buffer[BUFFER_SIZE];
    Input(buffer, BUFFER_SIZE);
    sort_array(BUFFER_SIZE, buffer);
    Print(buffer, BUFFER_SIZE);
    return 0;
}*/