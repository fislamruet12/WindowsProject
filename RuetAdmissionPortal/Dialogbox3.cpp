

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

int choicelistarray[]={0,1,2,3,4,5,6,7,8,9,10};
HINSTANCE hnst;
int br=0;
void breaking(int k)
{
    br=k;

}
BOOL CALLBACK AboutDlgProc3(HWND hDlg3, UINT message,
                            WPARAM wParam, LPARAM lParam)
{
    //cout<<"farid";
    static HWND to,from ;
    static int iColor, iFigure ;

    switch (message)
    {

    case WM_INITDIALOG:
    {
       //int a[]={7,10,1,3,4,5,6,2,8,9,0};
        //SetsubjectIntoDatabase(hDlg3,a);

         CreateWindow( "Button", "Student Choice Selection Box", WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
                           151, 5, 580, 520, hDlg3, 0, GetModuleHandle(0), 0 );
        COmBOBOXINFO(hDlg3);
        showcombobox();
        hideadmin(hDlg3);

    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg3,5, 5, 880, 580);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case s_choice:
            {
             Insertingchoices(choicelistarray,hDlg3);

            }
            break;

        case s_reset:
            {
                reset(hDlg3);

            }
            break;
        case IDC_LOCK:
            {
                 DialogBox(hnst,TEXT("LOCK_DLG"),hDlg3,AboutDlgProc4);
                 if(br==1)
                    EndDialog(hDlg3,FALSE),br=0;

            }
            break;
            case IDCANCEL:
            EndDialog(hDlg3,FALSE);
            return TRUE;
        }

        switch(LOWORD(wParam))
        {

        case ID_S1:
        {
            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
              //  MessageBox(hwnd,ListItem,TEXT("You already select This Item"),MB_ICONINFORMATION);
              choicelistarray[0]=ItemIndex;
              //cout<<ItemIndex<<endl;
            }
        }
        break;
        case s_com1:
        {
            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
                choicelistarray[1]=ItemIndex;

            }
        }

        break;
        case ID_S3:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
               choicelistarray[2]=ItemIndex;

            }

        }

        break;
        case ID_S4:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
               choicelistarray[3]=ItemIndex;


            }

        }

        break;
        case ID_S5:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
                choicelistarray[4]=ItemIndex;

            }

        }

        break;
        case ID_S6:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
               choicelistarray[5]=ItemIndex;


            }

        }

        break;
        case ID_S7:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
             choicelistarray[6]=ItemIndex;

            }

        }

        break;
        case ID_S8:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
               choicelistarray[7]=ItemIndex;


            }

        }

        break;
        case ID_S9:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
               choicelistarray[8]=ItemIndex;

            }

        }

        break;
        case ID_S10:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
              choicelistarray[9]=ItemIndex;


            }

        }

        break;
        case ID_S11:
        {

            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
                choicelistarray[10]=ItemIndex;


            }

        }

        break;
    }
    }
    }
    return FALSE ;
}


