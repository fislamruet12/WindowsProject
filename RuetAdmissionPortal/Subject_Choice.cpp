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

static HWND listarray[12];

BOOL CALLBACK AboutDlgProc_Subject(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    switch (message)
    {
    case WM_INITDIALOG:
    {



        listarray[1]=GetDlgItem(hDlg,IDC_LIST1);
        listarray[2]=GetDlgItem(hDlg,IDC_LIST2);
        listarray[3]=GetDlgItem(hDlg,IDC_LIST3);

       vector<int> *Choices= TakeSub();
          int aa[15];
       for(int i=1;i<=3500;i++) /// i=merit
    {
       int k=Choices[i].size();
       if(k!=0){
        for(int j=0;j<k;j++)
        {
            aa[j]=Choices[i][j];
          //  cout<<aa[j]<< "+- ";
        }
        //cout<<endl;
    }}
   int total=countTotal();
    //cout<<"total="<<total<<endl;
    createMeritlistInRange(hDlg,listarray[1],Choices,1,total/3);
    createMeritlistInRange(hDlg,listarray[2],Choices,total/3+1,2*total/3);
   createMeritlistInRange(hDlg,listarray[3],Choices,2*total/3+1,total);
// cout<<"farid"<<endl;
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



