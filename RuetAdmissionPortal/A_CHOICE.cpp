
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


#define IDC_Series 2010
#define A_R 301
#define A_M 302
#define A_S 303
#define A_D 304
#define A_RESET 405
TCHAR sub[13][50] =
{
    TEXT("Roll"), TEXT("Merit"), TEXT("Dept"), TEXT("Session")
};

HFONT  A_font=CreateFont (16, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
HWND a_combobox[20],a_adminInputs[20];

void ar_reset()
{
    for(int i=1; i<=5; i++)
        SendMessage(a_combobox[i],CB_SETCURSEL,(WPARAM)-1,(LPARAM)0);
}
void InitAcombo(HWND hwnd)
{

    a_combobox[1]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,320,10+1*30,100,20,
                               hwnd,(HMENU)A_R,NULL,NULL);
    a_combobox[2]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,320,10+3*30,100,20,
                               hwnd,(HMENU)A_M,NULL,NULL);
    a_combobox[3]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST|WS_VISIBLE,320,10+5*30,100,220,
                               hwnd,(HMENU)A_D,NULL,NULL);
    a_combobox[4]=CreateWindow(TEXT("STATIC"),"",SS_LEFT|WS_CHILD|WS_VISIBLE,320,10+7*30,100,30,
                               hwnd,(HMENU)A_S,NULL,NULL);
//combobox[5]=CreateWindow("button","Save Choice",WS_CHILD|SW_HIDE, 585, 480, 90, 40,hwnd,(HMENU)s_choice,NULL,NULL);
    a_combobox[5]=CreateWindow("button","Reset",WS_CHILD|WS_VISIBLE, 225, 268, 70, 22,hwnd,(HMENU)A_RESET,NULL,NULL);

    int t=1;
    for(int i=1; i<=4; i++)
    {
        a_adminInputs[i]=CreateWindow(TEXT("STATIC"),sub[i-1],
                                      WS_VISIBLE|SS_RIGHT|WS_CHILD,
                                      220,10+t*30,60,25,
                                      hwnd,(HMENU)NULL,NULL,NULL);
        t+=2;
    }
    for(int i=1; i<=7 ; i++)
    {
        SendMessage(a_combobox[i],WM_SETFONT,WPARAM(A_font),true);
        SendMessage(a_adminInputs[i],WM_SETFONT,WPARAM(A_font),TRUE);

    }
    SendMessage(a_combobox[3],CB_ADDSTRING,0,(LPARAM)"Architecture");
    static TCHAR series[205];
    //for(int i=1; i<=50; i++)
    {

       // SendMessage(a_combobox[4],CB_ADDSTRING,0,(LPARAM)series);
    }
    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;

        TCHAR series1[50];
        wsprintf(series1,_T(" Architecture Choice Form/Session / %s"),c);
        wsprintf(series,_T("%s"),c);
        SetWindowText(hwnd,series1);
        SetWindowText(a_combobox[4],series);


}

BOOL CALLBACK AboutDlgProc_AR(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {
        InitAcombo(hDlg);

    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 650);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case A_RESET:
            ar_reset();

            break;
        case A_OK:
            static char ar_record[6][20];
            for(int i=0; i<=3; i++)
            {
                GetWindowText(a_combobox[i+1],ar_record[i],GetWindowTextLength(a_combobox[i+1])+1);
               // cout<<ar_record[i]<<endl;
                printf("%d \n",ar_record[i]);
            }
                A_insert(ar_record,hDlg);
           //MessageBox(hDlg,"Succesfully Submitted","Alert box",MB_OK);

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



