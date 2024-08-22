/*������ 5. �������� �������
��������� �������, ������� ������ � ������� ����������� � ������������
������� �������. �������� �������
void change_max_min(int size, int a[])
������ �� �����: ������� ��������� �� ���� ������ ������� �
������ ����� ���� int
������ �� ������: ������� �� ���������� ��������, ����������
������ ����������� �� ����� ���������.
������
������ �� �����: 1 2 3 4 5 6 7 8 9 10
������ �� ������: 10 2 3 4 5 6 7 8 9 1*/

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

void change_max_min(int size, int a[])
{
    int min = a[0], max = a[0], min_index, max_index, tmp;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min) // ��� ���.
        {
            min = a[i];    // ���. ������� � �������
            min_index = i; // ������ ���. �������� � �������
        }

        else if (a[i] > max) // ��� ����.
        {
            max = a[i];    // ����. ������� � �������
            max_index = i; // ������ ����. �������� � �������
        }

        tmp = a[min_index];          // �������� ���.������� ��������� � ���������� tmp
        a[min_index] = a[max_index]; // ����. ������ ����������� ���.������.
        a[max_index] = tmp;
    }
}

/*int main()
{
    enum
    {
        BUFFER_SIZE = 10
    };
    int buffer[BUFFER_SIZE];
    Input(buffer, BUFFER_SIZE);
    change_max_min(BUFFER_SIZE, buffer);
    Print(buffer, BUFFER_SIZE);
    return 0;
}*/