
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include<bits/stdc++.h>
#include<commctrl.h>
#include "resource.h"
#include<SQLAPI.h>
#include<string>
#include<sstream>
using namespace std;
int s_Range[5];
vector<int>showdept[10000];
SAConnection con24;
SACommand cmd24,cmd25,cmd26,cmp,range_cal,accom,nsoed,eee,ete,ece,me;
SACommand DEptwise;
int k=1;
class DataBase2
{
public :
    DataBase2()
    {
        con24.Connect("ruet_admission","root","",SA_MySQL_Client);
        cmd24.setConnection(&con24);
        cmd25.setConnection(&con24);
        cmd26.setConnection(&con24);
        cmp.setConnection(&con24);
        accom.setConnection(&con24);
        nsoed.setConnection(&con24);
        ete.setConnection(&con24);
        ece.setConnection(&con24);
        range_cal.setConnection(&con24);
       // range_cal1.setConnection(&con24);
         me.setConnection(&con24);
    }
    ~DataBase2()
    {
        con24.Disconnect();
    }


};

//TCHAR Planets[13][50] =
//{
//    TEXT("Computer Science And Engineering"), TEXT("Electrical And Electronics Engineering"), TEXT("Electronics and Telecommunication engineering"), TEXT("Electrical and Computer Engineering"),
//    TEXT("Civil Engineering"), TEXT("Glass and ceramic engineering"), TEXT("Mechanical Engineering"), TEXT("Industrial production Engineering"),
//    TEXT("Urban and Regional Planning"),TEXT("Architecture"),TEXT("Chemical and food processing engineering"),TEXT("Not determined")
//};
char ALLDEPT[11][20]={"EEE","CSE","MTE","ETE","ECE","ME","CE","IPE","GCE","CFPE","URP"};
TCHAR Planets[13][50] =
{
    TEXT("EEE"), TEXT("CSE"), TEXT("MTE"), TEXT("ETE"),
    TEXT("ECE"), TEXT("ME"), TEXT("CE"), TEXT("IPE"),
    TEXT("GCE"),TEXT("CFPE"),TEXT("URP")
};
TCHAR choiceOrder[26][50]=
{
    TEXT("First choice"),TEXT("Second choice"),TEXT("Third choice"),TEXT("Fourth choice"),TEXT("Fiveth choice"),TEXT("Sixth choice"),TEXT("Seventh choice"),TEXT("Eighth choice"),
    TEXT("Nineth choice"),TEXT("Tenth choice"),TEXT("Eleventh choice"),TEXT("Academic Session"),TEXT("Admission Test Roll:"),TEXT("Merit Position :")

};
int whatseries;
TCHAR entry[10][50]=
{
    TEXT("Roll"),TEXT("Math"),TEXT("Phy"),TEXT("Che"),
    TEXT("Eng")

};
HFONT  hFont=CreateFont (16, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
//SendMessage (hwnda, WM_SETFONT, WPARAM (hFont), TRUE);

HWND combobox[25],adminInput[25],submarks[25],markstext[10],adminInputs[26];

void TCHARfromDialog1(int k)
{
    whatseries=k;

}
char cs[13];
void convert()
{
    string s;
    s=S_A();
    for(int i=0; i<9; i++)
        cs[i]=s[i];
    for(int i=9; i<9+2; i++)
        cs[i]=NULL;
}
int s_Range_func(int to,int from)
{
    s_Range[0]=to;
    s_Range[1]=from;
    sort(s_Range,s_Range+2);
}

void cursorpos(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)

{

    HMENU hMenu, hSubMenu,hSubMenu1,hSubMenu2,hSubMenu3;

    hMenu = CreateMenu();

    hSubMenu= CreatePopupMenu();
    hSubMenu1=CreatePopupMenu();
    hSubMenu2=CreatePopupMenu();
    hSubMenu3=CreatePopupMenu();

    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Setcolor");

    AppendMenu(hSubMenu,MF_POPUP,(UINT_PTR)set_G, "Beguni");
    AppendMenu(hSubMenu,MF_SEPARATOR,0,0);
    AppendMenu(hSubMenu,MF_POPUP,(UINT_PTR)set_A,"Aqua");
    AppendMenu(hSubMenu,MF_SEPARATOR,0,0);
    AppendMenu(hSubMenu,MF_POPUP,(UINT_PTR)set_W,"Sky");
//    AppendMenu(hSubMenu,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu,MF_POPUP,(UINT_PTR)set_B,"Beguni");


//    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu1, "EntrySection");
//    AppendMenu(hSubMenu1, MF_POPUP,(UINT_PTR)ED_MARKSENTRY,"Marks Entry");
//    AppendMenu(hSubMenu1,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu1, MF_POPUP,(UINT_PTR)ED_INDIVMARK,"Individual Marks");
//    AppendMenu(hSubMenu1,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu1, MF_POPUP,(UINT_PTR)ED_DIALOG,"All student marks");
//
//    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu2, "Architect");
//    AppendMenu(hSubMenu2, MF_POPUP,(UINT_PTR)A_CHOICE,"Put Choices");
//    AppendMenu(hSubMenu2,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu2, MF_POPUP,(UINT_PTR)A_RESULT,"Show Result");
//
//    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu3, "Make Result");
//    AppendMenu(hSubMenu3, MF_STRING | MF_POPUP, (UINT)Mk_R,  "Assign Subject According To Last Call");
//    AppendMenu(hSubMenu3,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu3, MF_STRING | MF_POPUP, (UINT)NULL, "&Migration");
//    AppendMenu(hSubMenu3,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu3, MF_STRING | MF_POPUP, (UINT)NULL, "&Admission Cancel");
//    AppendMenu(hSubMenu3,MF_SEPARATOR,0,0);
//    AppendMenu(hSubMenu3, MF_STRING | MF_POPUP, (UINT)FinalResult, "Final Depts Result");
  /*

        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu1, "&Stuff");

        AppendMenu(hSubMenu1, MF_STRING,(UINT)ED_ADMIN, "&STUFF OPTION1");
        AppendMenu(hSubMenu1,MF_SEPARATOR,0,0);
        AppendMenu(hSubMenu1, MF_STRING,(UINT)ED_ADMIN, "&STUFF OPTION2");
        AppendMenu(hSubMenu1,MF_SEPARATOR,0,0);
        AppendMenu(hSubMenu1, MF_STRING,(UINT)ED_ADMIN, "&STUFF OPTION1");
        AppendMenu(hSubMenu1,MF_SEPARATOR,0,0);
        AppendMenu(hSubMenu1, MF_STRING,(UINT)ED_ADMIN, "&STUFF OPTION2");
        */
    SetMenu(hwnd, hMenu);

    TCHAR series[120];
    convert();
    wsprintf(series,_T("Admission test of Ruet./Session/ %s."),cs);
    SetWindowText(hwnd,series);
}
void hideadmin(HWND hwndDlg)
{
    for(int i=1; i<=14; i++)
    {
        int p;
        p=i;
        if(p==13)
            p=14;
        else if(p==14)
            p=16;
        adminInput[i]=CreateWindow(TEXT("STATIC"),choiceOrder[i-1],
                                   WS_VISIBLE|SS_RIGHT|WS_CHILD,
                                   200,10+p*30,120,25,
                                   hwndDlg,(HMENU)NULL,NULL,NULL);
        SendMessage(adminInput[i],WM_SETFONT,WPARAM(hFont),TRUE);
        //ShowWindow(adminInput[i],SW_SHOW);

    }

}
#define choice 1000
void COmBOBOXINFO(HWND hwnd)
{
//     combobox[0]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,590,14,100,20,
//                             hwnd,(HMENU)NULL,NULL,NULL);
    combobox[1]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+1*30,300,220,
                             hwnd,(HMENU)ID_S1,NULL,NULL);
    combobox[2]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+2*30,300,220,
                             hwnd,(HMENU)s_com1,NULL,NULL);
    combobox[3]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+3*30,300,220,
                             hwnd,(HMENU)ID_S3,NULL,NULL);
    combobox[4]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+4*30,300,220,
                             hwnd,(HMENU)ID_S4,NULL,NULL);
    combobox[5]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+5*30,300,220,
                             hwnd,(HMENU)ID_S5,NULL,NULL);
    combobox[6]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+6*30,300,220,
                             hwnd,(HMENU)ID_S6,NULL,NULL);
    combobox[7]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+7*30,300,220,
                             hwnd,(HMENU)ID_S7,NULL,NULL);
    combobox[8]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+8*30,300,220,
                             hwnd,(HMENU)ID_S8,NULL,NULL);
    combobox[9]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+9*30,300,220,
                             hwnd,(HMENU)ID_S9,NULL,NULL);
    combobox[10]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+10*30,300,220,
                              hwnd,(HMENU)ID_S10,NULL,NULL);
    combobox[11]=CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_DROPDOWNLIST,390,10+11*30,300,220,
                              hwnd,(HMENU)ID_S11,NULL,NULL);
    combobox[12]=CreateWindow(TEXT("STATIC"),"",SS_CENTER|WS_CHILD,390,10+12*30,200,20,
                              hwnd,(HMENU)ID_S12,NULL,NULL);

    combobox[13]=CreateWindow(TEXT("COMBOBOX"),"",WS_BORDER|WS_CHILD|CBS_SIMPLE,330,10+14*30,100,25,
                              hwnd,(HMENU)ID_ROLL,NULL,NULL);

    combobox[14]=CreateWindow(TEXT("COMBOBOX"),"",WS_BORDER|WS_CHILD|CBS_SIMPLE,330,10+16*30,100,25,
                              hwnd,(HMENU)ID_MERIT,NULL,NULL);

    for(int i=1; i<=14; i++)
    {
        // ShowWindow(combobox[i],SW_SHOW);
        SendMessage (combobox[i], WM_SETFONT, WPARAM (hFont), TRUE);

    }
    for(int k=1; k<=11; k++)
        for(int i=0; i<11; i++)
            SendMessage(combobox[k],CB_ADDSTRING,0,(LPARAM)Planets[i]);

    for(int k=1; k<=11; k++)
        SendMessage(combobox[k], CB_SETCURSEL, (WPARAM)k-1, (LPARAM)0);

    //CreateWindow( "button", _T("Save"), WS_CHILD|WS_VISIBLE,
    //                         585, 480, 90, 40, hwnd, (HMENU)ED_SAVE, NULL,NULL );
    combobox[15]=CreateWindow("button","Save Choice",WS_CHILD|SW_HIDE, 585, 480, 90, 40,hwnd,(HMENU)s_choice,NULL,NULL);
    combobox[16]=CreateWindow("button","Reset",WS_CHILD|SW_HIDE, 485, 480, 90, 40,hwnd,(HMENU)s_reset,NULL,NULL);

    SendMessage(combobox[15],WM_SETFONT,WPARAM(hFont),TRUE);
    SendMessage(combobox[16],WM_SETFONT,WPARAM(hFont),TRUE);

    TCHAR series[120],series1[120];
//    //SendMessage(combobox[0],CB_ADDSTRING,0,(LPARAM)"Session");
//    for(int i=1; i<=200; i++)
//    {

    wsprintf(series,_T("Admission test of Ruet./Session./ %d-%d.             [_] Range for the merit ( %d to  %d )."),2009+whatseries,2010+whatseries,s_Range[0],s_Range[1]);
    convert();
    wsprintf(series1,_T("%s"),cs);
//
    SetWindowText(hwnd,series);
    SetWindowText(combobox[12],series1);
//    }
//
//    SendMessage(combobox[12], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
//

}

void showcombobox()
{
    for(int i=1; i<=16; i++)
    {
        ShowWindow(combobox[i],SW_SHOW);
        ShowWindow(adminInput[i],SW_SHOW);

    }
}
void hidecombobox()
{
    for(int i=1; i<=16; i++)
    {
        ShowWindow(combobox[i],SW_HIDE);
        ShowWindow(adminInput[i],SW_HIDE);

    }
}




void marksEntryInterface(HWND hwnd)
{

    submarks[1]= CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,390,40+1*25,150,25,
                              hwnd,(HMENU)ID_ROLL,NULL,NULL);

    submarks[2]= CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,390,40+3*25,150,25,
                              hwnd,(HMENU)ID_MATH,NULL,NULL);
    submarks[3]= CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,390,40+5*25,150,25,
                              hwnd,(HMENU)ID_PHY,NULL,NULL);
    submarks[4]= CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,390,40+7*25,150,25,
                              hwnd,(HMENU)ID_CHE,NULL,NULL);
    submarks[5]= CreateWindow(TEXT("COMBOBOX"),"",SS_CENTER|WS_CHILD|CBS_SIMPLE|WS_VISIBLE,390,40+9*25,150,25,
                              hwnd,(HMENU)ID_ENG,NULL,NULL);


    submarks[6]=CreateWindow("button","Save Marks",WS_CHILD|WS_VISIBLE, 450,340,100,40,hwnd,(HMENU)ID_MARKSAVE,GetModuleHandle(NULL),NULL);
    submarks[7]=CreateWindow("button","Reset",WS_CHILD|WS_VISIBLE, 330,340,100,40,hwnd,(HMENU)M_reset,GetModuleHandle(NULL),NULL);
    submarks[8]=CreateWindow("button","All marks",WS_CHILD|WS_VISIBLE, 210,340,100,40,hwnd,(HMENU)ED_DIALOG,GetModuleHandle(NULL),NULL);

//    for(int i=0; i<=5; i++)
//    {
//        SendMessage(submarks[i+1],CB_ADDSTRING,0,(LPARAM(entry[i])));
//        SendMessage(submarks[i+1], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
//    }

    int t=1;
    for(int i=1; i<=5; i++)
    {
        adminInputs[i]=CreateWindow(TEXT("STATIC"),entry[i-1],
                                    WS_VISIBLE|SS_RIGHT|WS_CHILD,
                                    335,40+t*25,40,25,
                                    hwnd,(HMENU)NULL,NULL,NULL);
        t+=2;
    }
    wsprintf(entry[5],_T("Session : %d-%d"),2009+whatseries,2010+whatseries);

      SetWindowText(hwnd,entry[5]);
    adminInputs[6]=CreateWindow(TEXT("STATIC"),entry[5],
                                WS_VISIBLE|SS_RIGHT|WS_CHILD,
                                590,14,140,20,
                                hwnd,(HMENU)NULL,NULL,NULL);
    for(int i=1; i<=8 ; i++)
    {
        SendMessage(submarks[i],WM_SETFONT,WPARAM(hFont),true);
        SendMessage(adminInputs[i],WM_SETFONT,WPARAM(hFont),TRUE);

    }


}
void hidemarksEntryInterface()
{
    for(int i=1; i<=7; i++)
    {
        ShowWindow(submarks[i],SW_HIDE);
        ShowWindow(adminInputs[i],SW_HIDE);
    }

}
void  showmarksEntryInterface()
{

    for(int i=1; i<=7; i++)
    {
        ShowWindow(submarks[i],SW_SHOW);
        ShowWindow(adminInputs[i],SW_SHOW);
    }
}


/*
void DrawPixels(HWND hwnd,int a,int b,int c,int d,int e,int f)
{

    PAINTSTRUCT ps;

    HDC hdc = BeginPaint(hwnd, &ps);

    RoundRect(hdc, a,b,c,d,e,f);

    EndPaint(hwnd, &ps);
}

*/
HWND hd;
DataBase2 b;
bool checkeddigit(char a[])
{
    // printf("%d\n",strlen(a));
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]<'0' or a[i]>'9')
            return true;
    }
    return false;
}
void savemarksintodatabase(HWND hwnd)
{

    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;


    int length[10];
    memset(length,0,sizeof(length));
    static char marksarray[10][10];
    bool flag=0;
    for(int i=1; i<=5; i++)
    {
        length[i]=GetWindowTextLength(submarks[i])+1;
        GetWindowText(submarks[i],marksarray[i-1],length[i]);

        if(checkeddigit(marksarray[i-1]))
            flag=1;
    }

    cmd24.setCommandText("select roll from student_marks where roll=:1 and ser =:2");
    cmd24.Param(1).setAsLong()=atol(marksarray[0]);
    cmd24.Param(2).setAsString()=c;
    cmd24.Execute();
    while(cmd24.FetchNext())
    {
        flag=1;
        //    cout<<cmd24.Field("roll").asLong()<<endl;

    }

    if(atol(marksarray[0])==0)
        flag=1;
    if(flag==1)
    {
        MessageBox(hwnd,"Wrong Input","Alert !",MB_ICONINFORMATION);
        return;
    }

    cmd25.setCommandText("insert into  student_marks values(:1,:2,:3,:4,:5,:6)");
    //int long=val,;
    //val=whatseries;

    for(int i=1; i<=6; i++)
    {
        if(i==6)
        {
            cmd25.Param(6).setAsLongChar()=c;
        }
        else
            cmd25.Param(i).setAsLong()=atol(marksarray[i-1]);
    }

    cmd25.Execute();
    MessageBox(hwnd,"Successfully Executed....('^ , ^')","Alert !",MB_ICONINFORMATION);

//    for(int i=0; i<5; i++)
//    {
//        //  SendMessage(submarks[i+1],CB_ADDSTRING,0,(LPARAM(TEXT(""))));
//       // SendMessage(submarks[i+1], CB_SETCURSEL, (WPARAM)1, (LPARAM)0);
//    }


}
int checkcorrectchoice(int correct[])
{
    int a[20]= {0};
    for(int i=0; i<11; i++)
    {
        a[correct[i]]++;
        if(a[correct[i]]>1)
            return 1;
    }
    if(correct[12]==0||correct[13]==0)
        return 1;
    return 0;
}

void Insertingchoices(int a[],HWND hwnd)
{
    string s;
    s=S_A();
    //  cout<<"farid="<<s<<endl;

    whatseries=s.length();
    char c[whatseries],ss[whatseries];
    for(int i=0; i<whatseries; i++)
        c[i]=s[i];
    for(int i=whatseries; i<whatseries+2; i++)
        c[i]=NULL;

    static char rollandmerit[20][20];
    for(int i=12; i<=13; i++)
    {
        GetWindowText(combobox[i+1],rollandmerit[i],GetWindowTextLength(combobox[i+1])+1);
        a[i]=atol(rollandmerit[i]);
        //  cout<<a[i]<<endl;

    }
    swap(a[12],a[13]);
// for(int i=0;i<=13;i++)
//      cout<<a[i]<<" ";
//      cout<<endl;

    if(a[12]<s_Range[0] or a[12]>s_Range[1])
    {
        MessageBox(hwnd,"Error Out Of range.","Alert !",MB_ICONINFORMATION);
        return;
    }
    if(checkcorrectchoice(a))
    {
        MessageBox(hwnd,"Duplicate Choice Entry..","Alert !",MB_ICONINFORMATION);
        return;
    }


    cmd25.setCommandText("select count(roll) from student_choice where (roll=:1 or merit =:2) and series=:3");
    cmd25.Param(1).setAsLong()=a[13]; ///roll
    cmd25.Param(2).setAsLong()=a[12];
    cmd25.Param(3).setAsString()=c;
    cmd25.Execute();

    while(cmd25.FetchNext())
    {
        //cout<<cmd25.Field("count(roll)").asLong()<<endl;
        if(cmd25.Field("count(roll)").asLong()>0)
        {
            MessageBox(hwnd,"This student Information Already Exists..","Alert !",MB_ICONINFORMATION);
            return;
        }

    }
    cmd25.Close();


cmd26.setCommandText("SELECT *from student_marks where roll=:1 and ser=:2");
    cmd26.Param(1).setAsLong()=a[13];
    cmd26.Param(2).setAsString()=c;
    cmd26.Execute();
    int chk=0;
    while(cmd26.FetchNext())
    {
        chk=1;
       // cout<<cmd26.Field("roll").asLong()<<endl;

    }
    cmd26.Close();
    if(chk<1)
    {
        MessageBox(hwnd,"This student Is Not Exists..","Alert !",MB_ICONINFORMATION);
        return;

    }

    cmd24.setCommandText("insert into student_choice values(:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12,:13,:14,:15)");

    cmd24.Param(1).setAsLong()=a[13];
    cmd24.Param(2).setAsLong()=a[12];
    for(int i=1; i<=11; i++)
    {
        cmd24.Param(i+2).setAsLong()=a[i-1];
    }
    cmd24.Param(14).setAsString()=c;
    cmd24.Param(15).setAsLong()=0;
    cmd24.Execute();
    cmd26.Close();

    //SetsubjectIntoDatabase(hwnd,a);

    MessageBox(hwnd,"Successfully Executed....('^,,^')","Alert !",MB_ICONINFORMATION);
    // SetWindowText(hwnd,TEXT("farid m"));


}

void reset(HWND hwnd)
{
    for(int k=0; k<=14; k++)
        SendMessage(combobox[k], CB_SETCURSEL, (WPARAM)-1, (LPARAM)0);


}
void marksreset()
{
    for(int i=1; i<=5; i++)
        SendMessage(submarks[i],CB_SETCURSEL,(WPARAM)-1,(LPARAM)0);
}

void A_insert(char ar_record[][20],HWND hd)
{
    if(atol(ar_record[0])==0 or atol(ar_record[1])==0 or !ar_record[2] or !ar_record[3])
    {
        MessageBox(hd,"Input Field Is Empty('^,,^')","Alert !",MB_ICONINFORMATION);
        return ;
    }
    cmd24.setCommandText("insert into architect values(:1,:2,:3,:4)");
    cmd24.Param(1).setAsLong()=atol(ar_record[0]);
    cmd24.Param(2).setAsLong()=atol(ar_record[1]);
    cmd24.Param(3).setAsString()=ar_record[2];
    cmd24.Param(4).setAsString()=ar_record[3];
    cmd24.Execute();
    // cout<<"ok"<<endl;
    MessageBox(hd,"Successfully Executed....('^,,^')","Alert !",MB_ICONINFORMATION);

}

void  createMeritlist(HWND hwnd,HWND CreateLIst)
{
    LVCOLUMN staticcol; // Make Coluom struct for ListView
    LVITEM staticlvitem;

    ListView_DeleteAllItems(CreateLIst);
    memset(&staticcol,0,sizeof(staticcol));
    staticcol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
    staticcol.cx=0x36;
    staticcol.pszText="Merit";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,0,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Roll No";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,1,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Dept";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,2,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Old Dept";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,3,(LPARAM)&staticcol); // Insert/Show the coloum


    memset(&staticlvitem,0,sizeof(staticlvitem));
    staticlvitem.mask=LVIF_TEXT;
    staticlvitem.cchTextMax=250;
    char Temp[200];

    me.setCommandText("select *from dept where series=:1");
    me.Param(1).setAsLongChar()=cs;
    me.Execute();

   // for(int j=0; j<=100; j++)
   int j=0;
    static int abb[5];
   while(me.FetchNext())
    {
        staticlvitem.iItem=j;
        staticlvitem.iSubItem=0;

        int k=me.Field("merit").asLong();
        abb[1]=me.Field("roll").asLong();
         abb[2]=me.Field("dep").asLong();
        abb[3]= me.Field("olddep").asLong();

        sprintf(Temp,"%d",k);
        staticlvitem.pszText=Temp;
        SendMessage(CreateLIst,LVM_INSERTITEM,0,(LPARAM)&staticlvitem);
    j++;
            staticlvitem.iSubItem=1;
            sprintf(Temp,"%d",abb[1]);
            staticlvitem.pszText=Temp;
            SendMessage(CreateLIst,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        for(int i=2; i<=3; i++) // Add SubItems in a loop
        {
            staticlvitem.iSubItem=i;
            sprintf(Temp,"%s",ALLDEPT[abb[i]]);
            staticlvitem.pszText=Temp;
            SendMessage(CreateLIst,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        }

    }

}


///*** merit list Section***///

vector<int> Choices[10000];

vector<int>* Takechoice()
{

    convert(); ///calculate series by cs

    cmp.setCommandText("select *from student_choice where series =:1 and chk=:2");
    cmp.Param(1).setAsLongChar()=cs;
    cmp.Param(2).setAsLong()=0;
    cmp.Execute();
    int a[15];
    while(cmp.FetchNext())
    {

        //cout<<cmp.Field("Roll").asLong()<<endl;
        a[0]=cmp.Field("first").asLong();
        a[1]=cmp.Field("secend").asLong();
        a[2]=cmp.Field("third").asLong();
        a[3]=cmp.Field("fourth").asLong();
        a[4]=cmp.Field("fifth").asLong();
        a[5]=cmp.Field("sixth").asLong();
        a[6]=cmp.Field("seven").asLong();
        a[7]=cmp.Field("eight").asLong();
        a[8]=cmp.Field("nine").asLong();
        a[9]=cmp.Field("ten").asLong();
        a[10]=cmp.Field("eleven").asLong();

        a[11]=cmp.Field("merit").asLong();
        a[12]=cmp.Field("Roll").asLong();
        for(int j=0; j<13; j++)
        {
            //     cout<<a[j]<<" ";
            Choices[a[12]].push_back(a[j]);
        }

        // cout<<endl;

    }
    return Choices;

}

int countTotal()
{

convert();
//cout<<cs<<endl;
    cmp.setCommandText("select count(distinct merit) as ct from testdept where series=:1");
    cmp.Param(1).setAsLongChar()=cs;
    cmp.Execute();
    int a[15];
    int k=1;
    while(cmp.FetchNext())
    {
        return cmp.Field("ct").asLong();
    }
    return 0;



}
///*** Calculate Choice ***///


void SetsubjectIntoDatabase(HWND hwnd,int b[])
{
    int getsR[15],C_S[15];
    memset(C_S,0,sizeof(C_S));

//    for(int i=0;i<13;i++)
//    //  cout<<b[i]<<" ";
//      cout<<endl;

//cout<<"cs==="<<cs<<endl;
    accom.setCommandText("select *from Accomodation");
    accom.Execute();
    while(accom.FetchNext())
    {
        getsR[1]=accom.Field("EEE").asLong(); ///eee sit vacancy
        getsR[2]=accom.Field("CSE").asLong();
        getsR[3]=accom.Field("MTE").asLong();
        getsR[4]=accom.Field("ETE").asLong();
        getsR[5]=accom.Field("ECE").asLong();
        getsR[6]=accom.Field("ME").asLong();
        getsR[7]=accom.Field("CE").asLong();
        getsR[8]=accom.Field("IPE").asLong();
        getsR[9]=accom.Field("GCE").asLong();
        getsR[10]=accom.Field("CFPE").asLong();
        getsR[11]=accom.Field("URP").asLong();
    }
  DEptwise.setConnection(&con24);
   nsoed.setCommandText("SELECT dep,COUNT(MERIT) AS TOTAL FROM testDEPT WHERE series=:3 GROUP BY DEP ASC");
  nsoed.Param(3).setAsLongChar()=cs;
    nsoed.Execute();
//cout<<"cs==="<<cs<<endl;

    while (nsoed.FetchNext() )
    {
       C_S[nsoed.Field("dep").asLong()]= nsoed.Field("TOTAL").asLong(); /// remaining sit ...
        //k++;
    }


    deptdb(C_S,getsR,b);



   // cout<<"testing2"<<endl;

}



void  createMeritlistInRange(HWND hwnd,HWND CreateLIst,std::vector<int>v[],int range1,int range2)
{
    LVCOLUMN staticcol; // Make Coluom struct for ListView
    LVITEM staticlvitem;

    ListView_DeleteAllItems(CreateLIst);
    memset(&staticcol,0,sizeof(staticcol));
    staticcol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
    staticcol.cx=0x48;
    staticcol.pszText="Merit";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,0,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Roll No";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,1,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Dept";                     // First Header
    SendMessage(CreateLIst,LVM_INSERTCOLUMN,2,(LPARAM)&staticcol); // Insert/Show the coloum
    //staticcol.pszText="Old Dept";                     // First Header
    //SendMessage(CreateLIst,LVM_INSERTCOLUMN,3,(LPARAM)&staticcol); // Insert/Show the coloum


    memset(&staticlvitem,0,sizeof(staticlvitem));
    staticlvitem.mask=LVIF_TEXT;
    staticlvitem.cchTextMax=250;
    char Temp[20];
int p=0;
for(int j=range1; j<=range2; j++)
    {
        int k=v[j].size();

        if(k!=0){

        staticlvitem.iItem=p;
        staticlvitem.iSubItem=0;
        sprintf(Temp,"%d",v[j][0]);
     //   cout<<v[j][0]<<" ";
        staticlvitem.pszText=Temp;
        SendMessage(CreateLIst,LVM_INSERTITEM,0,(LPARAM)&staticlvitem);
    p++;
            staticlvitem.iSubItem=1;
            sprintf(Temp,"%d",v[j][1]);
         //   cout<<v[j][1]<<" "<<endl;
            staticlvitem.pszText=Temp;
            SendMessage(CreateLIst,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        for(int i=2; i<=2; i++) // Add SubItems in a loop
        {
            staticlvitem.iSubItem=i;
            sprintf(Temp,"%s",ALLDEPT[v[j][i]]);
            staticlvitem.pszText=Temp;
            SendMessage(CreateLIst,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        }
        }

    }

}

/// Update Result section ??///
///----------------
void Recalldept()
{


}


///^Update Result section ??///



/// adm cancel



std::vector<int>* TakeSubfromassign()
{
    k=1;
    return showdept;
}
