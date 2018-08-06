#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
//=============================================================================
#include <windows.h>  //include all the basics
#include <tchar.h>    //string and other mapping macros
#include<bits/stdc++.h>
#if defined __MINGW_H
#define _WIN32_IE 0x0400
#endif
#include <commctrl.h>
#include<tchar.h>
#include "resource.h"
#include <string>
#include<SQLAPI.h>
using namespace std;
HINSTANCE hin_mark;
int xt=140,yt=40,zt=40;
void color(int x,int y,int z)
{
    xt=x;
    yt=y;
    zt=z;
}
BOOL CALLBACK AboutDlgProc_Marks(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {
            marksEntryInterface(hDlg);
    }
    return FALSE ;
    case WM_PAINT:
    {
        DrawRectangles(hDlg,0, 0, 580, 650);
       // hdc=BeginPaint(hDlg,&ps);
      //  TextOut(hdc,12,47,TEXT("Chose Series.."),12);
    }
    break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case ID_MARKSAVE:
        {
            savemarksintodatabase(hDlg);
        }
          break;
        case M_reset:
        {
            marksreset();

        }
        break;
        case ED_DIALOG:
        {
            DialogBox(hin_mark,TEXT("IDD_DIALOG2"),hDlg,AboutDlgProc);
            // cout<<"testinnnnng"<<endl;
        }
        break;


        case IDCANCEL:
            EndDialog(hDlg,FALSE);
            return TRUE;

        }
    }
    return TRUE ;
    }
    return FALSE ;
}



void DrawRectangles(HWND hwnd,int x,int y,int z,int w) {

    PAINTSTRUCT ps;

    HDC hdc = BeginPaint(hwnd, &ps);
    HPEN hPen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));
//    HPEN holdPen = SelectObject(hdc, hPen);

    HBRUSH hBrush1 = CreateSolidBrush(RGB(121, 90, 0));
    HBRUSH hBrush2 = CreateSolidBrush(RGB(240, 63, 19));
    HBRUSH hBrush3 = CreateSolidBrush(RGB(240, 210, 18));
   // HBRUSH hBrush4 = CreateSolidBrush(RGB(255, 255, 200));
    //HBRUSH hBrush4 = CreateSolidBrush(RGB(0, 255, 255)); /// aqua
    HBRUSH hBrush4 = CreateSolidBrush(RGB(xt,yt, zt));

  //  HBRUSH holdBrush = SelectObject(hdc, hBrush1);

   // Rectangle(hdc, 30, 30, 100, 100);
    SelectObject(hdc, hBrush4);
    Rectangle(hdc, x, y, z, w);
//    SelectObject(hdc, hBrush3);
//    Rectangle(hdc, 30, 110, 100, 180);
//    SelectObject(hdc, hBrush4);
//    Rectangle(hdc, 110, 110, 180, 180);

//    SelectObject(hdc, holdPen);
//    SelectObject(hdc, holdBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush1);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);

    EndPaint(hwnd, &ps);
}
