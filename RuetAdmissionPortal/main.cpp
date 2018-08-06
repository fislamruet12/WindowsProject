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
int click=0;
//define an unicode string type alias
typedef basic_string<TCHAR> ustring;
//=============================================================================
//message processing function declarations
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void OnCreate(const HWND,CREATESTRUCT*);
void OnDestroy(const HWND);
void OnSize(const HWND,int,int,UINT);
int choicearray[123];
//non-message function declarations
HWND CreateListview(const HWND,const HINSTANCE,DWORD,const RECT&,const int);
inline int ErrMsg(const ustring&);
void StartCommonControls(DWORD);
void showMerit(HWND hwnd);
void hideMerit(HWND hwnd);
//setup some control id's

HWND hList,hList1=NULL;  // List View identifier
LVCOLUMN LvCol; // Make Coluom struct for ListView
LVITEM LvItem;  // ListView Item struct
LV_DISPINFO lvd;
int iSelect=0;
int index=0;
int flag=0;
HWND hEdit;
bool escKey=0;
char tempstr[100]="";
TCHAR tchar;
MSG msg;
enum
{
    IDC_IPADDRESS=200,
    //aboutbox ,DialogBox
};
//TCHAR tmp[]={_T("exaple"),_T("hell0")};
SAConnection con;
SACommand cmd,cmd1,cmd2,range_cal1;
HINSTANCE hInst;

class DataBase
{
public :
    DataBase()
    {
        con.Connect("ruet_admission","root","",SA_MySQL_Client);
        cmd.setConnection(&con);
        cmd1.setConnection(&con);
        cmd2.setConnection(&con);
        range_cal1.setConnection(&con);
    }
    ~DataBase()
    {
        con.Disconnect();
    }


};
struct LVHandles
{
    HWND       hListview;
    HIMAGELIST hLargeIcons;
    HIMAGELIST hSmallIcons;
};
HWND progresses;
//=============================================================================
void showmarkINlist()
{
    ShowWindow(hList,WS_VISIBLE);
}

void  deptdb(int C_st[],int getsRt[],int b[])
{

 string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;
   cout<<c<<endl;
    for(int i=0;i<11;i++)
        {
           if(C_st[b[i]+1]<getsRt[b[i]+1])
           {
             cout<<b[11]<<" "<<b[12]<<"   "<<b[i]<<" "<<" "<<c<<endl;
               range_cal1.setCommandText("insert into testdept values(:1,:2,:3,:4,:5)");
               range_cal1.Param(1).setAsLong()=b[11];
               range_cal1.Param(2).setAsLong()=b[12];
               range_cal1.Param(3).setAsLong()=b[i];
               range_cal1.Param(4).setAsLong()=b[i];
               range_cal1.Param(5).setAsString()=c;
               range_cal1.Execute();
           //   DEptwise.Execute();
           range_cal1.Close();
              return;
           }

        }

}
void progress (HWND hwnd)
{
    RECT prog= {0,0,0,0};
    StartCommonControls(ICC_PROGRESS_CLASS);
    progresses=CreateWindowEx(0,PROGRESS_CLASS,
                              0,WS_CHILD|WS_VISIBLE,170,100,400,30,hwnd,(HMENU)NULL,GetModuleHandle(NULL),0);
    SendMessage(progresses,PBM_SETPOS,0,0);
}
void Insert(HWND hwnd)
{
// ShowWindow(hList,WS_VISIBLE);
    int i;
    char Temp[255];
    LVBKIMAGE plvbki= {0};
    memset(&plvbki,0,sizeof(plvbki));
    plvbki.ulFlags=LVBKIF_SOURCE_URL;
    plvbki.xOffsetPercent=40;
    plvbki.yOffsetPercent=15;
    OleInitialize(NULL);
    hList=CreateWindowEx(0,WC_LISTVIEW,_T(""),LVS_REPORT|WS_CHILD|WS_VISIBLE
                         ,135,17,595,550,hwnd,(HMENU)NULL,GetModuleHandle(NULL),NULL);
//ShowWindow(hList,SW_HIDE);
    ListView_DeleteAllItems(hList);
//    SendMessage(hList,LVM_SETTEXTBKCOLOR, 0,(LPARAM)CLR_NONE);
//    SendMessage(hList,LVM_SETBKIMAGE,0,(LPARAM)(LPLVBKIMAGE)&plvbki);
//
//    SendMessage(hList,LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_FULLROWSELECT); // Set style

    memset(&LvCol,0,sizeof(LvCol)); // Reset Coluom
    LvCol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM; // Type of mask
    LvCol.cx=0x60;                                // width between each coloum
    LvCol.pszText="Roll";                     // First Header

    // Inserting Couloms as much as we want
    SendMessage(hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
    LvCol.pszText="Math";                          // Next coloum
    SendMessage(hList,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
    LvCol.pszText="Che";                       //
    SendMessage(hList,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); //
    LvCol.pszText="Phy";                              //
    SendMessage(hList,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol); //
    LvCol.pszText="Eng";                            //
    SendMessage(hList,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol); //
    LvCol.pszText="Total";                      //
    SendMessage(hList,LVM_INSERTCOLUMN,5,(LPARAM)&LvCol); // ...same as above
    int m[10],m1[10];
    try
    {



        cmd.setCommandText("Select *from student_marks order by roll asc");

//cmd.Param(1).setAsLong()=1;
        cmd.Execute();
        // cout<<"testing"<<endl;
        // fetch results row by row and print  results
        int cn=0;
        memset(&LvItem,0,sizeof(LvItem)); // Reset Item Struct

        //  Setting properties Of Items:

        LvItem.mask=LVIF_TEXT;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test

        while(cmd.FetchNext())
        {
            m1[1]=0;
            m[0]=cmd.Field("roll").asLong();
            m1[1]+=m[1]=cmd.Field("math").asLong();
            m1[1]+=m[2]=cmd.Field("che").asLong();
            m1[1]+=m[3]=cmd.Field("phy").asLong();
            m1[1]+=m[4]=cmd.Field("eng").asLong();
            m[5]=m1[1];


            // lets add a new Item:
            LvItem.iItem=cn++;            // choose item
            LvItem.iSubItem=0;
            sprintf(Temp,"%d",m[0]);   // Text to display (can be from a char variable) (Items)
            // Put in first coluom
            LvItem.pszText=Temp;
            SendMessage(hList,LVM_INSERTITEM,0,(LPARAM)&LvItem); // Send to the Listview

            for(i=1; i<=6; i++) // Add SubItems in a loop
            {
                LvItem.iSubItem=i;
                sprintf(Temp,"%d",m[i]);
                LvItem.pszText=Temp;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter etxt to SubItems
            }
        }
    }
    catch(SAException &x)
    {

    }


}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR pStr,int nCmd)
{
    DataBase database;
    ustring classname=_T("SIMPLEWND");
    WNDCLASSEX wcx= {0}; //used for storing information about the wnd 'class'

    wcx.cbSize         = sizeof(WNDCLASSEX);
    wcx.lpfnWndProc    = WndProc;             //wnd Procedure pointer
    wcx.hInstance      = hInst;               //app instance
//use 'LoadImage' to load wnd class icon and cursor as it supersedes the
//obsolete functions 'LoadIcon' and 'LoadCursor', although these functions will
//still work. Because the icon and cursor are loaded from system resources ie
//they are shared, it is not necessary to free the image resources with either
//'DestroyIcon' or 'DestroyCursor'.
    wcx.hIcon         = reinterpret_cast<HICON>(LoadImage(0,IDI_APPLICATION,
                        IMAGE_ICON,0,0,LR_SHARED));
    wcx.hCursor       = reinterpret_cast<HCURSOR>(LoadImage(0,IDC_ARROW,
                        IMAGE_CURSOR,0,0,LR_SHARED));
    wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
    wcx.lpszClassName = classname.c_str();
    if (!RegisterClassEx(&wcx))
    {
        ErrMsg(_T("Failed to register wnd class"));
        return -1;
    }

    //  int desktopwidth=GetSystemMetrics(SM_CXSCREEN);
    //  int desktopheight=GetSystemMetrics(SM_CYSCREEN);

    HWND hwnd=CreateWindowEx(0,                     //extended styles
                             classname.c_str(),     //name: wnd 'class'
                             _T("Ruet Admission Test"),      /* Title Text */
                             WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, /* default window */
                             CW_USEDEFAULT,       /* Windows decides the position */
                             CW_USEDEFAULT,  705,      //width
                             658,//height
                             0,                     //parent wnd handle
                             0,                     //menu handle/wnd id
                             hInst,                 //app instance
                             0);                    //user defined info
    if (!hwnd)
    {
        ErrMsg(_T("Failed to create wnd"));
        return -1;
    }

    ShowWindow(hwnd,nCmd);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg,0,0,0)>0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return static_cast<int>(msg.wParam);
}
HFONT  hFont1=CreateFont (17, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");

//=============================================================================
HWND box,box1[10];

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HBRUSH hbrush;
    HPEN hpen;
    switch (message)                  /* handle the messages */
    {


    case WM_NOTIFY:
    {
        switch(LOWORD(wParam))
        {
        case IDC_IPADDRESS:
            LPNMLISTVIEW pnm = (LPNMLISTVIEW)lParam;

            if(pnm->hdr.hwndFrom == hList &&pnm->hdr.code == NM_CUSTOMDRAW)
            {
                //  SetWindowLong(hwnd, DWL_MSGRESULT, (LONG)ProcessCustomDraw(lParam));
                return TRUE;
            }
        }

        break;
    }

    case WM_CREATE:
    {
          //DialogBox(hInst,TEXT("IDD_DIALOGlogin"),hwnd,AboutDlgProclogin);

          DialogBox(hInst,TEXT("IDD_DIALOG1"),hwnd,AboutDlgProc1);

          //PostQuitMessage(0);       /* send a WM_QUIT to the message queue */


        box1[1]=CreateWindow( "Button", "Admin Arena", WS_CHILD|SW_HIDE|WS_SYSMENU,
                              220, 100, 250, 40, hwnd, 0, GetModuleHandle(0), 0 );
        box1[2]=CreateWindow( "Button", "Student Arena", WS_CHILD|WS_VISIBLE|WS_SYSMENU,
                              220, 180, 250, 40, hwnd, (HMENU)Main_Student, GetModuleHandle(0), 0 );
        box1[3]=CreateWindow( "Button", "Marks Entry Arena", WS_CHILD|WS_VISIBLE|WS_SYSMENU,
                              220, 260, 250, 40, hwnd, (HMENU)ED_MARKSENTRY, GetModuleHandle(0), 0 );
        box1[4]=CreateWindow( "Button", "Make Result Arena", WS_CHILD|WS_VISIBLE|WS_SYSMENU,
                              220, 340, 250, 40, hwnd, (HMENU)Make_REsult, GetModuleHandle(0), 0 );

        box1[5]=CreateWindow( "Button", "Error Correction Arena", WS_CHILD|WS_VISIBLE|WS_SYSMENU,
                              220, 420, 250, 40, hwnd, 0, GetModuleHandle(0), 0 );

        //ShowWindow(hList,SW_HIDE);

        for(int i=1; i<=5; i++)
            SendMessage(box1[i],WM_SETFONT,WPARAM(hFont1),true);
        cursorpos(hwnd,message,wParam,lParam);

        OnCreate(hwnd,reinterpret_cast<CREATESTRUCT*>(lParam));





    }
    break;

    case WM_LBUTTONDOWN:
    {

        POINT p;
        int x,y;
        GetCursorPos(&p);
        //cout<<p.x<<" "<<p.y<<endl;
    }
    break;

    case WM_RBUTTONDBLCLK:
    {
//        cout<<"right clicked"<<endl;

    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
     case WM_PAINT:
         DrawRectangles(hwnd,0, 0, 880, 650);
        // cout<<"draw Paint"<<endl;
        break;
    case WM_COMMAND:
    {
        switch(wParam)
        {
        case ED_MARKSENTRY:
        {

            DialogBox(hInst,TEXT("Marks_entry"),hwnd,AboutDlgProc_Marks);

        }

        break;
        case ED_Merit:
        {

            if(click!=2)
            {

                ShowWindow(box,SW_HIDE);
                ShowWindow(hList,SW_HIDE);
                hidecombobox();
                showMerit(hwnd);
            }
            click=2;
        }

        break;
        case ED_choicebox:
        {
            DialogBox(hInst,TEXT("IDD_DIALOG5"),hwnd,AboutDlgProc_Range);

            DialogBox(hInst,TEXT("IDD_DIALOG3"),hwnd,AboutDlgProc3);


            click=3;

        }
        break;
        case ED_INDIVMARK:
        {

            if(click!=5)
            {
                hideMerit(hwnd);
                ShowWindow(box,SW_HIDE);
                hidecombobox();
                Insert(hwnd);
            }
            click=5;
        }
        break;

        case Main_Student:

            DialogBox(hInst,TEXT("Student_arena"),hwnd,AboutDlgProc_MainStudent);

            break;
        case Make_REsult:

            DialogBox(hInst,TEXT("Make_result"),hwnd,AboutDlgProc_MainStudent);

            break;
        case FinalResult:
            //DialogBox(hInst,TEXT("IDD_DIALOG5"),hwnd,AboutDlgProc_Range);
            break;

//    HBRUSH hBrush1 = CreateSolidBrush(RGB(121, 90, 0));
//    HBRUSH hBrush2 = CreateSolidBrush(RGB(240, 63, 19));
//    HBRUSH hBrush3 = CreateSolidBrush(RGB(240, 210, 18));
//   // HBRUSH hBrush4 = CreateSolidBrush(RGB(255, 255, 200));
//    //HBRUSH hBrush4 = CreateSolidBrush(RGB(0, 255, 255)); /// aqua
//    HBRUSH hBrush4 = CreateSolidBrush(RGB(25,0, 25));

        case set_A:
            color(25,0,25);
            break;
            case set_B:
            color(257,0,125);
            break;
            case set_G:
            color(225,0,225);
            break;
            case set_W:
            color(25,20,125);
            break;
        case ED_EXIT:
        {
            PostQuitMessage(0);

        }
        break;
        }

    }
    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);

    }
}

//=============================================================================
void OnCreate(const HWND hwnd,CREATESTRUCT *cs)
{
    // cout<<"oK"<<endl;
    RECT rc= {115,15,725,558}; //dimesnions will be set in WM_SIZE handler
    StartCommonControls(ICC_LISTVIEW_CLASSES); //ICC_WIN95_CLASSES can also be used
    LVHandles *lvh=new LVHandles;

    SetWindowLongPtr(hwnd,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(lvh));

    lvh->hListview=CreateListview(hwnd,cs->hInstance,LVS_ICON,rc,IDC_IPADDRESS);
    ShowWindow(lvh->hListview,SW_HIDE);
    SendMessage(lvh->hListview,WM_SETFONT,WPARAM(hFont1),true);

    return ;
}
//=============================================================================
void OnDestroy(const HWND hwnd)
{
//free up resources - first get the information which has been previously
//stored as the user data of the main window
    LVHandles *lvh=reinterpret_cast<LVHandles*>(static_cast<LONG_PTR>
                   (GetWindowLongPtr(hwnd,GWLP_USERDATA)));
    ImageList_Destroy(lvh->hLargeIcons);
    ImageList_Destroy(lvh->hSmallIcons);
    delete lvh;

    PostQuitMessage(0);    //signal end of application
}
//=============================================================================
void OnSize(const HWND hwnd,int cx,int cy,UINT uFlags)
{

    LVHandles *lvh=reinterpret_cast<LVHandles*>(static_cast<LONG_PTR>
                   (GetWindowLongPtr(hwnd,GWLP_USERDATA)));

    MoveWindow(lvh->hListview,0,0,cx,cy,1);
//arrange contents of listview along top of control
    SendMessage(lvh->hListview,LVM_ARRANGE,LVA_ALIGNTOP,0);
}
void showMerit(HWND hwnd)
{
    LVHandles *lvh=reinterpret_cast<LVHandles*>(static_cast<LONG_PTR>
                   (GetWindowLongPtr(hwnd,GWLP_USERDATA)));

    ShowWindow(lvh->hListview,SW_SHOW);

    ListView_DeleteAllItems(lvh->hListview);
    HICON hIcon;
    LVITEM lvi= {0};

    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;

  //  cout<<c<<endl;
    lvi.mask=LVIF_TEXT;
    //lvi.
    int i;

    /*  for (i=0; i<nNumIcons; ++i)
      {
          hIcon=ExtractIcon(0,_T("shell32.dll"),i);
          ImageList_AddIcon(lvh->hLargeIcons,hIcon);
          ImageList_AddIcon(lvh->hSmallIcons,hIcon);
          DestroyIcon(hIcon);
      }
    //attach image lists to list view common control
      ListView_SetImageList(lvh->hListview,lvh->hLargeIcons,LVSIL_NORMAL);
      ListView_SetImageList(lvh->hListview,lvh->hSmallIcons,LVSIL_SMALL);
    */
//add some items to the the list view common control

//flags to determine what information is to be set


    cmd1.setCommandText("select roll, phy+math+che+eng as total from student_marks  where ser = :1 order by total desc");
    cmd1.Param(1).setAsLongChar()=c;
    cmd1.Execute();
//cout<<"farid"<<endl;
    int merit=1,l=0,roll1,state=0;
    i=0;
    while(cmd1.FetchNext())
    {
        // state=i*100/12530;
//        SendMessage(progresses,PBM_SETPOS,(state++)*100/1000,0);
//        if((state)*100/1000>2)
//            ShowWindow(progresses,SW_HIDE);
        string rol;
        TCHAR chBuffer[16];
        rol=cmd1.Field("roll").asString();
        roll1=atoi(rol.c_str());
        //cout<<roll1<<endl;
        if(i%16==0)
        {
            //the zero-based item index
            lvi.iItem=i;
            wsprintf(chBuffer,_T("Merit-\nRoll-"));
            lvi.pszText=chBuffer;            //item label
            //lvi.cchTextMax=lstrlen(chBuffer);//length of item label
            //image list index
            SendMessage(lvh->hListview,LVM_INSERTITEM,0,(LPARAM)&lvi);
            i++;

        }
        lvi.iItem=i;
        wsprintf(chBuffer,_T("%d\n%d"),merit,roll1),merit++;//convert item index int to string

        lvi.pszText=chBuffer;            //item label
        // lvi.cchTextMax=lstrlen(chBuffer);//length of item label
        SendMessage(lvh->hListview,LVM_INSERTITEM,0,(LPARAM)&lvi);
        i++;
    }


}
void hideMerit(HWND hwnd)
{
    LVHandles *lvh=reinterpret_cast<LVHandles*>(static_cast<LONG_PTR>
                   (GetWindowLongPtr(hwnd,GWLP_USERDATA)));

    ShowWindow(lvh->hListview,SW_HIDE);

}
//=============================================================================
HWND CreateListview(const HWND hParent,const HINSTANCE hInst,DWORD dwStyle,
                    const RECT& rc,const int id)
{
    dwStyle|=WS_CHILD|WS_VISIBLE;
    return CreateWindowEx(0,                  //extended styles
                          WC_LISTVIEW,        //control 'class' name
                          0,                  //control caption
                          dwStyle,            //wnd style
                          rc.left,            //position: left
                          rc.top,             //position: top
                          rc.right,           //width
                          rc.bottom,          //height
                          hParent,            //parent window handle
                          //control's ID
                          reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)),
                          hInst,              //instance
                          0);                 //user defined info
}
//=============================================================================
inline int ErrMsg(const ustring& s)
{
    return MessageBox(0,s.c_str(),_T("ERROR"),MB_OK|MB_ICONEXCLAMATION);
}
//=============================================================================
void StartCommonControls(DWORD flags)
{
//load the common controls dll, specifying the type of control(s) required
    INITCOMMONCONTROLSEX iccx;
    iccx.dwSize=sizeof(INITCOMMONCONTROLSEX);
    iccx.dwICC=flags;
    InitCommonControlsEx(&iccx);
}
//=============================================================================

void makemerit(HWND hwnd)
{
   hList1=CreateWindowEx(0,WC_LISTVIEW,_T(""),WS_CHILD|WS_VISIBLE
                         ,135,17,595,550,hwnd,(HMENU)NULL,GetModuleHandle(NULL),NULL);


SendMessage(hList1,WM_SETFONT,WPARAM(hFont1),true);


    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;

        ListView_DeleteAllItems(hList1);
    TCHAR series[120];

    wsprintf(series,_T("Merit List of Ruet./Session/ %s."),c);
    SetWindowText(hwnd,series);

LVITEM lvi={0};
  //  cout<<c<<endl;
    lvi.mask=LVIF_TEXT;
    int i;


    cmd1.setCommandText("select roll, phy+math+che+eng as total from student_marks  where ser = :1 order by total desc");
    cmd1.Param(1).setAsLongChar()=c;
    cmd1.Execute();
//cout<<"farid"<<endl;
    int merit=1,l=0,roll1,state=0;
    i=0;
    while(cmd1.FetchNext())
    {
        string rol;
        TCHAR chBuffer[16];
        rol=cmd1.Field("roll").asString();
        roll1=atoi(rol.c_str());
        //cout<<roll1<<endl;
        if(i%13==0)
        {
            //the zero-based item index
            lvi.iItem=i;
            wsprintf(chBuffer,_T("Merit-\nRoll-"));
            lvi.pszText=chBuffer;            //item label
            //lvi.cchTextMax=lstrlen(chBuffer);//length of item label
            //image list index
            SendMessage(hList1,LVM_INSERTITEM,0,(LPARAM)&lvi);
            i++;

        }
        lvi.iItem=i;
        wsprintf(chBuffer,_T("%d\n%d"),merit,roll1),merit++;//convert item index int to string

        lvi.pszText=chBuffer;            //item label
        // lvi.cchTextMax=lstrlen(chBuffer);//length of item label
        SendMessage(hList1,LVM_INSERTITEM,0,(LPARAM)&lvi);
        i++;
    }


}

void adm_Can(HWND hd,int r,int m)
{
    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;
  range_cal1.setCommandText("UPDATE student_choice SET chk=1 where Roll =:1 and merit =:2 and series=:3");
  range_cal1.Param(1).setAsLong()=r;
  range_cal1.Param(2).setAsLong()=m;
  range_cal1.Param(3).setAsLongChar()=c;

  range_cal1.Execute();
  MessageBox(hd,"Query Executed ","Alert",MB_OK);

}


void Update(HWND hDlg)
{
   HWND progresse=CreateWindowEx(0,PROGRESS_CLASS,
                              0,WS_CHILD|WS_VISIBLE,6, 193, 146, 23,hDlg,(HMENU)NULL,GetModuleHandle(NULL),0);
       SendMessage(progresses,PBM_SETPOS,0,0);

    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;
        //cout<<"update="<<c<<endl;
        cmd1.setConnection(&con);
      cmd1.setCommandText("delete from testdept where series=:1");
      cmd1.Param(1).setAsLongChar()=c;
      cmd1.Execute();
   ShowWindow(progresse,WS_VISIBLE);
  //int i=0;

       vector<int> *Choices= Takechoice();
           int aa[15];
           int k=3;
       for(int i=0;i<=4050;i++)
    {
       int k=Choices[i].size();
       if(k!=0){
        for(int j=0;j<k;j++)
        {
            Choices[i].clear();
            aa[j]=Choices[i][j];
         //  cout<<aa[j]<< " ->>";
        }
       // cout<<endl;
       SetsubjectIntoDatabase(hDlg,aa);
       SendMessage(progresse,PBM_SETPOS,i,0);
       }
    }
    ShowWindow(progresse,SW_HIDE);


}

void architect(HWND arclist)
{

    string s;
    s=S_A();
    char c[10];
    for(int i=0; i<9; i++)
        c[i]=s[i];
    for(int i=9; i<9+2; i++)
        c[i]=NULL;
  //cout<<c<<endl;
    LVCOLUMN staticcol; // Make Coluom struct for ListView
    LVITEM staticlvitem;

    ListView_DeleteAllItems(arclist);
    memset(&staticcol,0,sizeof(staticcol));
    staticcol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
    staticcol.cx=0x60;
    staticcol.pszText="Merit";                     // First Header
    SendMessage(arclist,LVM_INSERTCOLUMN,0,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Roll No";                     // First Header
    SendMessage(arclist,LVM_INSERTCOLUMN,1,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Dept";                     // First Header
    SendMessage(arclist,LVM_INSERTCOLUMN,2,(LPARAM)&staticcol); // Insert/Show the coloum
    staticcol.pszText="Old Dept";                     // First Header
    SendMessage(arclist,LVM_INSERTCOLUMN,3,(LPARAM)&staticcol); // Insert/Show the coloum


    memset(&staticlvitem,0,sizeof(staticlvitem));
    staticlvitem.mask=LVIF_TEXT;
    staticlvitem.cchTextMax=250;
    char Temp[200];

    cmd.setCommandText("select roll,merit from architect where series=:1 order by merit asc");
    cmd.Param(1).setAsLongChar()=c;
    cmd.Execute();

   // for(int j=0; j<=100; j++)
   int j=0;
    static int abb[5];
   while(cmd.FetchNext())
    {
        staticlvitem.iItem=j;
        staticlvitem.iSubItem=0;

       // int k=cmd.Field("merit").asLong();
        abb[1]=cmd.Field("roll").asLong();
         abb[2]=cmd.Field("merit").asLong();
        //abb[3]= cmd.Field("olddep").asLong();

        sprintf(Temp,"%d",abb[2]);
        staticlvitem.pszText=Temp;
        SendMessage(arclist,LVM_INSERTITEM,0,(LPARAM)&staticlvitem);
    j++;
            staticlvitem.iSubItem=1;
            sprintf(Temp,"%d",abb[1]);
            staticlvitem.pszText=Temp;
            SendMessage(arclist,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        for(int i=2; i<=3; i++) // Add SubItems in a loop
        {
            staticlvitem.iSubItem=i;
            sprintf(Temp,"Architect");
            staticlvitem.pszText=Temp;
            SendMessage(arclist,LVM_SETITEM,0,(LPARAM)&staticlvitem); // Enter etxt to SubItems

        }

    }

}
