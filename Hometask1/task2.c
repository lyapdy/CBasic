/*������� 2. �������� �������
�� ���� ��������� �������� ����������� 32-������ ����� ����� N. ���������
�������� �������� ���� ����� �������� ����� ����� �� ��������������� �
������� ���������� ����� ������� �����.
������ �� �����: ����������� 32-������ ����� ����� N
������ �� ������: ���� ����� �����.
������ �1
������ �� �����: 1
������ �� ������: 4278190081
������ �2
������ �� �����: 4278190081
������ �� ������: 1*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int dec_to_bin(x)

{
    int i;
    for (i = 31; i >= 0; --i)
    {
        printf("%" PRIu32, x >> i & 1);
    }
    printf("\n");
    return 0;
}

int main()
{
    uint32_t N;
    uint32_t mask = ~0;
    uint32_t res;
    scanf("%u", &N);
    uint32_t inv_old_digit = N >> 24;
    inv_old_digit = ~inv_old_digit;
    inv_old_digit = inv_old_digit << 24;
    mask = mask >> 8;
    res = N & mask | inv_old_digit;
    dec_to_bin(inv_old_digit);
    dec_to_bin(N);
    dec_to_bin(res);
    printf("%u", res);
    return 0;
}
