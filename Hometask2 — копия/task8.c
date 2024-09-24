#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
 
void MouseTskMng()
{
    printf("Try run TaskManager\n");
 
       SetCursorPos(700,731); // смещение в панель задач, зависит от разрешени€
       mouse_event (MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
       mouse_event (MOUSEEVENTF_RIGHTUP,0,0,0,0);
       mouse_event (MOUSEEVENTF_MOVE,30,-45,0,0); // подн€тьс€ до строчки диспетчера
       Sleep (500); // ожидание всплыти€ контекстного меню
       mouse_event (MOUSEEVENTF_LEFTDOWN,0,0,0,0);
       mouse_event (MOUSEEVENTF_LEFTUP,0,0,0,0);
       printf("TaskManager is running\n");
       Sleep (3000); // защита на вс€кий случай
}
 
int main()
{
    while (1)
    {
      printf("Press Enter to run TaskManager");
      getchar();
      MouseTskMng(); // вызов процедуры запуска диспетчера задач
    }
}