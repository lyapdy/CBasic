#include <stdio.h>
#include <Windows.h>
int main()
{
    //keybd_event('C', 0,0,0);
    keybd_event('C', 0,KEYEVENTF_KEYUP,0);
    system("PAUSE");
    return 0;
}