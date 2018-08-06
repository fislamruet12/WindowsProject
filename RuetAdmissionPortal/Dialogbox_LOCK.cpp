


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
#include "resource.h"
#include <string>
#include<SQLAPI.h>
using namespace std;

BOOL CALLBACK AboutDlgProc4(HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam)
{

   HWND txtbox;
    switch (message)
    {

    case WM_INITDIALOG:
    {
    }
    return FALSE ;
       case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 550);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case P_ok:
          static char pass[100];
          static int val=1234;
          txtbox=GetDlgItem(hDlg,P_edit);

            GetWindowText(txtbox,pass,GetWindowTextLength(txtbox)+1);

            if(val==atol(pass))
            {
                EndDialog(hDlg,FALSE);
              //  cout<<" "<<pass<<endl;
                breaking(1);
            }
            break;

       case IDCANCEL:
        EndDialog(hDlg,FALSE);
     break;
        }
    }
    }
    return FALSE ;

}


