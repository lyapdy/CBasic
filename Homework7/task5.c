/*������ 5. ������ � ����� ����
������� ������ �� 10 ��������� � �������� � ������ ������ ��� �����, �
������� ������ � ����� ����� (����� ��������) � ����.
������ �� �����: 10 ����� ����� ����� ������.
������ �� ������: ����� ����� ����� ������, � ������� ������ � �����
����� - ����
������
������ �� �����: 40 105 203 1 14 1000 22 33 44 55
������ �� ������: 105 203 1 1000*/

#include <stdio.h>
void arrPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    ;
}
int arrScan(int *in, int *out, int n)
{
    unsigned int pos_out = 0;
    for (int i = 0; i < n; i++)
    {
        if (in[i] / 10 % 10 == 0)
        {
            out[pos_out] = in[i];
            pos_out++;
        }
    }
    return pos_out;
}
int main()
{
    enum
    {
        arraySize = 10 // ������ �������
    };
    int array_in[arraySize] = {0};
    int array_out[arraySize] = {0};
    for (int i = 0; i < arraySize; i++)
        scanf("%d", &array_in[i]);
    arrPrint(array_out, arrScan(array_in, array_out, arraySize));
    return 0;
}
// ������� ���� ���������, ���� ���� ����� ��� ���, �� ������ ��������� �����