/*������� 3. �� ����
������������� Geek Brains ������� �����, ���������� N (1 ? N ? 1 000 000)
����������� �����, �� ������������� 1 000 000. ��������, ��� ����� ����
����� � ���� ������ ����������� ���� ���, � ��������� � ����� �� ��� ����.
�������� �� ����� ��� �����. ������� ������: � ������ ������� ������
�������� ����� N, ����� �� ������ ����� � ������ �������� N �����������
�����, �� ������������� 2 000 000 000. �������� ������: ���� ���������
������ ���������� �����, ������������� ���� ���, � ������� ��� �� �����.
��������: ������������ ������� �����������.
������ �� �����: ����������� ����� N (N > 0), ����� �������� �������
������������������ �� N ����� �����.
������ �� ������: ���� ����� �����.
������ �1
������ �� �����: 3 12 15 12
������ �� ������: 15
������ �2
������ �� �����: 5 1 2 0 2 1
������ �� ������: 0*/

#include <stdio.h>

int main()
{
    int N, val, k = 0;
    scanf("%d", &N);
    while (1)
    {
        if ((N < 1) || (N > 1000000))
        {
            printf("The number is out of range. Please try another option next time.\n");
            break;
        }
        else
        {

            for (int i = 0; i < N; ++i)
            {
                scanf("%d", &val);
                {
                    k ^= val;
                }
            }
            printf("%d", k);
            break;
        }
    }

    return 0;
}