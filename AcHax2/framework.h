#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include "Offsets.h"
#include "Header.h"
class framework 
{
private:
   
    
    HWND window = FindWindowA(NULL, "AssaultCube");
    RECT r_window_dimensions;
    // Vector2 v_window_size = { (float)r_window_dimensions.right - (float)r_window_dimensions.left, (float)r_window_dimensions.bottom - (float)r_window_dimensions.top };
  

    DWORD ViewMatrix = 0x501AE8;
public:
    void initialize() 
    {
        //GetWindowRect(window, &r_window_dimensions);

    }
    DWORD getViewMatrix()
    {
        return ViewMatrix;
    }

 
    /*
    
    
    
    
    Vector2 getWindowSize()
    {
        return v_window_size;
    }
    Vector2 getCenterScreen()
    {
        return { v_window_size.x / 2, v_window_size.y / 2 };

    }
    
    */

    
    

    int getNumOfPlayers()
    {
        return (int)*(DWORD*)(0x50F500);

    }
    DWORD getPlayerList()
    {
        return *(DWORD*)(0x50F4F8);


    }

};

