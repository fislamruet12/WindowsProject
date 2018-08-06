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

static HWND abc[4];

BOOL CALLBACK AboutDlgProc_Cancel(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {
        abc[1]=GetDlgItem(hDlg,C_Roll);
        abc[2]=GetDlgItem(hDlg,C_merit);

    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 550);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

        case C_execute:
            char ch[100];
            int rol,mer;
            (GetWindowText(abc[1],ch,GetWindowTextLength(abc[1])+1));
             rol=atol(ch);
             cout<<rol<<endl;
            //adm_Can(rol,mer);
            (GetWindowText(abc[2],ch,GetWindowTextLength(abc[2])+1));
             mer=atol(ch);
              cout<<mer<<endl;
              adm_Can(hDlg,rol,mer);
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




