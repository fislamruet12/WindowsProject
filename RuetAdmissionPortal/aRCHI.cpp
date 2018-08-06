
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

static HWND listArc;

BOOL CALLBACK AboutDlgProc_Subject_Ar(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {
        listArc=GetDlgItem(hDlg,IDC_LIST5);
        architect(listArc);

    }

    return FALSE ;

    case WM_PAINT:
    {
        //hdc=BeginPaint(hDlg,&ps);
        DrawRectangles(hDlg,0, 0, 880, 550);

      //  TextOut(hdc,12,47,TEXT("Chose Series.."),12);
    }
    break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {


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



