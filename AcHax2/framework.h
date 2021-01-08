#pragma once
#include "Offsets.h"

class framework
{
private:


    DWORD viewMatrix = 0x501AE8;
 public:


    void initialize() 
    {

    }
    intVector2 getCenterScreen()
    {
        int Width = *(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C94);
        int Height = *(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C98);

        return intVector2(Width/2,Height/2);
    }

 
    
    intVector2 getScreenSize()
    {
        int Width = *(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C94);
        int Height = *(int*)((DWORD)GetModuleHandleA(NULL) + 0x110C98);

        return intVector2(Width,Height);
    }
    
    
    

    DWORD getViewMatrix()
    {
        return viewMatrix;
    }
    
    


    

    int getNumOfPlayers()
    {
        return (int)*(DWORD*)(0x50F500);

    }
    DWORD getPlayerList()
    {
        return *(DWORD*)(0x50F4F8);


    }

};

