#include "Offsets.h"



framework* framew;


/*














DWORD findBestPlayer()
{
    const int amountOfPlayers = (int)*(DWORD*)(0x50F500);

    for (unsigned int i = 0; i < framew->getNumOfPlayers(); i++)
    {
        float matrix[16];
        DWORD current_plr = *(DWORD*)(framew->getPlayerList() + 0x4 * i);
        entity* current_plr_ent = (entity*)(current_plr);
        float lowestDist = FLT_MAX;
        DWORD lowestPlayer = NULL;
        Vector2 targetScreenPoint;
        memcpy(&matrix, (PBYTE*)(framew->getViewMatrix()), sizeof(matrix));

        if (current_plr)
        {

            WorldToScreen(current_plr_ent->HeadPos, targetScreenPoint, matrix, framew->getWindowSize().x, framew->getWindowSize().y);
            float nearesttome = Get2DDistance(targetScreenPoint, framew->getCenterScreen());
            if (nearesttome < lowestDist)
            {
                lowestDist = nearesttome;
                lowestPlayer = current_plr;

            }
        }
    }
    return NULL;
}








*/

















void mainfunc()
{
    
    MainClass* playerPtrClass = (MainClass*)((DWORD)GetModuleHandleA(NULL) + 0x109B74);

    framew->initialize();

    while (1)
    {
        if (GetAsyncKeyState(0x46) >> 15 & 1)
        {
            printf("Hp: %d \n", playerPtrClass->localPlayerPtr->Health);
        }
        Sleep(5);
    }
    /*
    std::thread aimbot([]()
        {
            while (1)
            {
                if (GetAsyncKeyState(0x46) >> 15 & 1)
                {
                    
                    findBestPlayer();
                    
                }
                Sleep(25);

            }
        });
    aimbot.detach();
    */

}
    
    

