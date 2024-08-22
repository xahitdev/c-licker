#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define KEY_F7 0x76
#define KEY_F4 0x73

int main()
{
  int number;
  printf("Enter CPS value: ");
  scanf("%d", &number);
  printf("Press F6 to toggle enable or disable.");
  bool enabled = false;
  bool change = false;

  while (true)
  {
    while (!change)
    {
      if (GetAsyncKeyState(KEY_F7))
      {
        while (GetAsyncKeyState(KEY_F7))
          ; // wait till F6 is released
        enabled = !enabled;
        if (enabled)
        {
          printf(":ON\n");
        }
        else
        {
          printf(":OFF\n");
        }
      }

      if (enabled)
      {
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(1000 / number); // Control the click rate
      }
      if (GetAsyncKeyState(KEY_F4))
      {
        printf("Enter CPS value: ");
        scanf("%d", &number);
        printf("Press F6 to toggle enable or disable.");
      }
    }
  }
}
