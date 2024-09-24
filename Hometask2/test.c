#include <stdio.h>

int res=0;

int main()
{
    res = rand() % (15 + 1 -1 );
    printf("%d\n", res);
    printf("%d\n", rand());
    printf("%d\n", rand()); 
    return 0;
}