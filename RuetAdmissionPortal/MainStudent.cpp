
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

HINSTANCE hin;
BOOL CALLBACK AboutDlgProc_MainStudent(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {

    }
    return FALSE ;
     case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 550);
        break;
    break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

          case S_choiceArena:
            DialogBox(hin,TEXT("IDD_DIALOG5"),hDlg,AboutDlgProc_Range);
            DialogBox(hin,TEXT("IDD_DIALOG3"),hDlg,AboutDlgProc3);

            break;
          case A_choiceArena:
              DialogBox(hin,TEXT("AR_CHOICE"),hDlg,AboutDlgProc_AR);

            break;
          case Make_final:
            DialogBox(hin,TEXT("IDD_DIALOG4"),hDlg,AboutDlgProc_Subject);
            cout<<"make final"<<endl;
           break;
           case Make_archi: /// archi result
               DialogBox(hin,TEXT("ARCHITECT"),hDlg,AboutDlgProc_Subject_Ar);

               break;
           case Make_Me: ///merit list gene
            DialogBox(hin,TEXT("Merit"),hDlg,AboutDlgProc_Merit);
            break;
            case Make_update: ///make Update
             {
                 Update(hDlg);
             }
            break;
            case Make_Ad: /// admis. cancle
                DialogBox(hin,TEXT("adm_cancel"),hDlg,AboutDlgProc_Cancel);

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



