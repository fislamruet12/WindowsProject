
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
HWND dialist;
SAConnection con4;
SACommand cmd4,cmd29;
HINSTANCE hInst1;


class DataBase1
{
public :
    DataBase1()
    {
        con4.Connect("ruet_admission","root","",SA_MySQL_Client);
        cmd4.setConnection(&con4);
        cmd29.setConnection(&con4);
        // cmd1.setConnection(&con);
    }
    ~DataBase1()
    {
        con4.Disconnect();
    }


};

vector<int>Subject[10000];

std::vector<int>* TakeSub()
{
    DataBase1 b;

    for(int i=0;i<5000;i++)
        Subject[i].clear();
 string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;

cmd29.setCommandText("select *from testdept where series=:1");

    cmd29.Param(1).setAsLongChar()=c;
    cmd29.Execute();
    int a[15];
    int k=1;
    while(cmd29.FetchNext())
    {

        //cout<<cmp.Field("Roll").asLong()<<endl;
        a[0]=cmd29.Field("merit").asLong();
        a[1]=cmd29.Field("roll").asLong();
        a[2]=cmd29.Field("dep").asLong();
        a[3]=cmd29.Field("old").asLong();

        for(int j=0; j<4; j++)
        {
            //     cout<<a[j]<<" ";
            Subject[k].push_back(a[j]);
        }
          k++;
    }
    return Subject;

}

void showMerit1(HWND hwnd)
{
    DataBase1 base;
    int i;
    char Temp[255];
    LVCOLUMN LvCol; // Make Coluom struct for ListView
    LVITEM LvItem;  // ListView Item struct

    LVBKIMAGE plvbki= {0};
    memset(&plvbki,0,sizeof(plvbki));
    plvbki.ulFlags=LVBKIF_SOURCE_URL;
    plvbki.xOffsetPercent=40;
    plvbki.yOffsetPercent=15;
    OleInitialize(NULL);
    dialist=CreateWindowEx(0,WC_LISTVIEW,_T(""),LVS_REPORT|WS_CHILD|WS_VISIBLE
                           ,13,40,588,535,hwnd,(HMENU)NULL,GetModuleHandle(NULL),NULL);
//ShowWindow(hList,SW_HIDE);
    ListView_DeleteAllItems(dialist);
//    SendMessage(hList,LVM_SETTEXTBKCOLOR, 0,(LPARAM)CLR_NONE);
//    SendMessage(hList,LVM_SETBKIMAGE,0,(LPARAM)(LPLVBKIMAGE)&plvbki);
//
//    SendMessage(hList,LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_FULLROWSELECT); // Set style

    memset(&LvCol,0,sizeof(LvCol)); // Reset Coluom
    LvCol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM; // Type of mask
    LvCol.cx=0x68;                                // width between each coloum
    LvCol.pszText="Roll";                     // First Header
    LvCol.cx=0x60;

    // Inserting Couloms as much as we want
    SendMessage(dialist,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
    LvCol.pszText="Math";                          // Next coloum
    SendMessage(dialist,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
    LvCol.pszText="Che";                       //
    SendMessage(dialist,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); //
    LvCol.pszText="Phy";                              //
    SendMessage(dialist,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol); //
    LvCol.pszText="Eng";                            //
    SendMessage(dialist,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol); //
    LvCol.pszText="Total";                      //
    SendMessage(dialist,LVM_INSERTCOLUMN,5,(LPARAM)&LvCol); // ...same as above
    int m[10],m1[10];
    try
    {
        int w;
        string s;
        s=S_A();
        w=s.length();
        char c[w];
        for(int i=0; i<w; i++)
            c[i]=s[i];
        for(int i=w; i<w+2; i++)
            c[i]=NULL;

        TCHAR series[50];
        wsprintf(series,_T(" Admission marks of Ruet /Session / %s"),c);
        SetWindowText(hwnd,series);

        cmd4.setCommandText("Select *from student_marks where ser =:1 order by roll asc");

       cmd4.Param(1).setAsString()=c;
        cmd4.Execute();
        // cout<<"testing"<<endl;
        // fetch results row by row and print  results
        int cn=0;
        memset(&LvItem,0,sizeof(LvItem)); // Reset Item Struct

        //  Setting properties Of Items:

        LvItem.mask=LVIF_TEXT;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test

        while(cmd4.FetchNext())
        {
            //   SendMessage(progresses,PBM_SETPOS,cn*100/12217,0);
//            if(cn*100/12217>99)
//                ShowWindow(progresses,SW_HIDE);
            m1[1]=0;
//            cout<<cmd.Field("roll").asLong()<<" ";
//            cout<<cmd.Field("math").asLong()<<" ";
//            cout<<cmd.Field("che").asLong()<<" ";
//            cout<<cmd.Field("phy").asLong()<<" ";
//            cout<<cmd.Field("eng").asLong()<<" ";

            m[0]=cmd4.Field("roll").asLong();
            m1[1]+=m[1]=cmd4.Field("math").asLong();
            m1[1]+=m[2]=cmd4.Field("che").asLong();
            m1[1]+=m[3]=cmd4.Field("phy").asLong();
            m1[1]+=m[4]=cmd4.Field("eng").asLong();
            m[5]=m1[1];

            //  cout<<(const  char*)cmd.Field("che").asLong()<<" ";
            // cout<<m[5]<<endl;



            // lets add a new Item:
            LvItem.iItem=cn++;            // choose item
            LvItem.iSubItem=0;
            sprintf(Temp,"%d",m[0]);   // Text to display (can be from a char variable) (Items)
            // Put in first coluom
            LvItem.pszText=Temp;
            SendMessage(dialist,LVM_INSERTITEM,0,(LPARAM)&LvItem); // Send to the Listview

            for(i=1; i<=6; i++) // Add SubItems in a loop
            {
                LvItem.iSubItem=i;
                sprintf(Temp,"%d",m[i]);
                LvItem.pszText=Temp;
                SendMessage(dialist,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter etxt to SubItems
            }
        }
    }
    catch(SAException &x)
    {

    }




}
BOOL CALLBACK AboutDlgProc (HWND hDlg4, UINT message,
                            WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_INITDIALOG:
    {

        showMerit1(hDlg4);

    }
    return FALSE ;
    case WM_PAINT:
        DrawRectangles(hDlg4,0, 0, 880, 550);
         break;
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDCANCEL:


            EndDialog(hDlg4,FALSE);
            return TRUE;
        case IDOK:
        {

        }
        break;
        }
    }
    return TRUE ;
    }
    return FALSE ;
}


