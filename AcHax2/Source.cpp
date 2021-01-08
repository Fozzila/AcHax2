#include "includes.h"
#include "framework.cpp"

framework* framew;
DWORD viewMatrix = 0x501AE8;
HWND hwndAC_Client;
HBRUSH Brush;
HDC hdcAC_client;

void DrawFilledRect(int x, int y, int w, int h)
{
    RECT rect = { x, y, x + w, y + h };
    FillRect(hdcAC_client, &rect, Brush);
}
void DrawBorderBox(int x, int y, int w, int h, int thickness)
{

    DrawFilledRect(x, y, w, thickness);

    DrawFilledRect(x, y, thickness, h);

    DrawFilledRect((x + w), y, thickness, h);

    DrawFilledRect(x, y + h, w + thickness, thickness);
}

void draw()
{
    hdcAC_client = GetDC(hwndAC_Client);

    for (unsigned int i = 0; i < framew->getNumOfPlayers(); i++)
    {
        DWORD current_plr = *(DWORD*)(framew->getPlayerList() + 0x4 * i);
        if (current_plr)
        {
            
            float matrix[16];
            memcpy(&matrix, (PBYTE*)(viewMatrix), sizeof(matrix));
            entity* current_plr_ent = (entity*)(current_plr);
            Vector2 current_plr_screenpoint;

            if (WorldToScreen(current_plr_ent->HeadPos, current_plr_screenpoint, matrix, framew->getScreenSize().x, framew->getScreenSize().y))
            {
                if (current_plr_ent->Health < 200)
                {
                    Brush = CreateSolidBrush(RGB(158, 66, 244));

                    DrawBorderBox(current_plr_screenpoint.x, current_plr_screenpoint.y, 50, 50, 1.5);
                    DeleteObject(Brush);
                }
                

                
            }
        }
    }
    DeleteObject(hdcAC_client);
    std::cout << "\n";
}

void mainfunc()
{
    hwndAC_Client = FindWindowA(0, ("AssaultCube"));

    MainClass* playerPtrClass = (MainClass*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);
    bool espEnabled = false;
    framew->initialize();

    while (1)
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            espEnabled = !espEnabled;

        }
        if (espEnabled)
        {
            draw();
            Sleep(5);
        }
        else
        {
            if (Brush)
            {
                DeleteObject(Brush);

            }
            if (hdcAC_client)
            {
                DeleteObject(hdcAC_client);
            }
        }
        Sleep(10);
    }
    

    

}
    
    

