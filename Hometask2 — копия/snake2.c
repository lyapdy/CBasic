#include <Windows.h>

void ClickKey(int vKeyCode)
{
    keybd_event(vKeyCode, 0, 0, 0); // зажать клавишу
    keybd_event(vKeyCode, 0, KEYEVENTF_KEYUP, 0); // отпустить клавишу
}

int main(int argc, char * argv[])
{
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        ClickKey('A'); // нажать и отпустить клавишу A
        Sleep(1000); // подождать 1 секунду (1000мс)
    }
}