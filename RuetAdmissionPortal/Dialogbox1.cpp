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

int series_no;

#define IDC_Series 2010
void Initcombo(HWND hwnd)
{
    TCHAR series[20];
    HWND seriesList;
    seriesList=GetDlgItem(hwnd,IDC_COMBO1);

    for(int i=1; i<=200; i++)
    {
        wsprintf(series,_T("%d-%d"),2009+i,2010+i);

        SendMessage(seriesList,CB_ADDSTRING,0,(LPARAM)series);
    }

    SendMessage(seriesList, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

}



BOOL CALLBACK AboutDlgProc1(HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {
        //  cout<<"faridul islam"<<endl;

        Initcombo(hDlg);


    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg,0, 0, 880, 650);
        break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

        case IDC_COMBO1:
        {
            if(HIWORD(wParam) == CBN_SELCHANGE)
            {
                int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL,(WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT,(WPARAM) ItemIndex, (LPARAM) ListItem);
                //            MessageBox(hDlg,ListItem,TEXT("You already select This Item"),MB_ICONINFORMATION);
                 series_no=ItemIndex+1;
                TCHARfromDialog1(ItemIndex+1);
               // string f;
               // f=S_A();
               // cout<<"farid= "<<series_no<<endl;
                EndDialog(hDlg,FALSE);
            }
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

string S_A()
{
    string s,s1;
    ostringstream c1,c2;
    c1<<(series_no+2009);
    s=c1.str();
    c2<<(series_no+2010);
    s1=c2.str();
    s=s+"-"+s1;

  cout<<s<<" series="<<series_no<<endl;
        return s;
}
