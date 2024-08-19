/*������ 4. ������������� �� ��������� �����
������� ������ �� 10 ��������� � ������������� ��� �� ��������� �����.
������ �� �����: 10 ����� ����� ����� ������
���� �� ������ ��������������� �� ��������� �����
������ �1
������ �� �����: 14 25 13 30 76 58 32 11 41 97
������ �� ������: 30 11 41 32 13 14 25 76 97 58
������ �2
������ �� �����: 109 118 100 51 62 73 1007 16 4 555
������ �� ������: 100 51 62 73 4 555 16 1007 118 109*/

#include <stdio.h>
void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    ;
}
void aSortLast(int *arr, int n) // ��������� �� ��������� �����
{
    int i, j;
    for (i = 0; i < n; ++i) // n ����� - ����������� �������
    {
        for (j = i; j < n; ++j)
        {
            if (arr[i] % 10 > arr[j] % 10) // �������� ������� �� ������� ����� �������
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    enum
    {
        arraySize = 10
    };
    int array[arraySize] = {0};
    for (int i = 0; i < arraySize; i++)
        scanf("%d", &array[i]);
    aSortLast(array, arraySize);
    aPrint(array, arraySize);
    return 0;
}