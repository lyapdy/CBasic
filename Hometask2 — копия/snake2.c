#include <Windows.h>

void ClickKey(int vKeyCode)
{
    keybd_event(vKeyCode, 0, 0, 0); // ������ �������
    keybd_event(vKeyCode, 0, KEYEVENTF_KEYUP, 0); // ��������� �������
}

int main(int argc, char * argv[])
{
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        ClickKey('A'); // ������ � ��������� ������� A
        Sleep(1000); // ��������� 1 ������� (1000��)
    }
}