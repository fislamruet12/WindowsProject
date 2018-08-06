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

static HWND hwdl[2];
BOOL CALLBACK AboutDlgProc_Range(HWND hDlg, UINT message,
                                 WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_INITDIALOG:
    {
        hwdl[0]=GetDlgItem(hDlg,R_frm);
        hwdl[1]=GetDlgItem(hDlg,R_to);

    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 650);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {


        case R_ok:


            static char ch[12][30];
            for(int i=0; i<2; i++)
            {
                GetWindowText(hwdl[i],ch[i],GetWindowTextLength(hwdl[i])+1);
                //  cout<<"far="<<ch[i]<<endl;
            }
            if(atol(ch[0]) >0 and atol(ch[1])>0)
            {
                s_Range_func(atol(ch[0]),atol(ch[1]));
                EndDialog(hDlg,FALSE);
            }
            else
            {
                MessageBox(hDlg,"Wrong Input ! ","Alert !",MB_ICONINFORMATION);
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



