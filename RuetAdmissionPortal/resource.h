
#ifndef IDC_STATIC
#define IDC_STATIC (-1)
void cursorpos(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
void hideadmin(HWND hwnd);
void COmBOBOXINFO(HWND hwnd);
void showcombobox();
void hidecombobox();
void marksEntryInterface(HWND hwnd);
//void DrawPixels(HWND hwnd ,int a,int b,int c,int d,int e,int f);
void hidemarksEntryInterface();
void showmarksEntryInterface();
void Insertingchoices(int a[],HWND hwnd);
void marksreset();
void test();
void Update(HWND hDlg);
void breaking(int n);
void reset(HWND hwnd);
void TCHARfromDialog1(int k);
void A_insert(char ar_record[][20],HWND hd);
void savemarksintodatabase(HWND hwnd);
std::string S_A();
std::vector<int>* Takechoice();
std::vector<int>* TakeSub();
std::vector<int>* TakeSubfromassign();
int countTotal();
int s_Range_func(int to,int from);
void color(int x,int y,int z);
void SetsubjectIntoDatabase(HWND hwnd,int b[]);
void  createMeritlist(HWND hwnd,HWND CreateLIst);
void architect(HWND arclist);
void makemerit(HWND hwnd);
void DrawRectangles(HWND hwnd,int x,int y,int z,int w);
void adm_Can(HWND hd,int r,int m);
void  createMeritlistInRange(HWND hwnd,HWND CreateLIst,std::vector<int>v[],int range1,int range2);
void deptdb(int C_st[],int getsRt[],int bt[]);
BOOL CALLBACK AboutDlgProclogin(HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam);

BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc1 (HWND hDlg, UINT message,
                             WPARAM wParam, LPARAM lParam);

BOOL CALLBACK AboutDlgProc3 (HWND hDlg, UINT message,
                             WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc4(HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc_AR(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc_Subject(HWND hDlg, UINT message,
                                   WPARAM wParam, LPARAM lParam);

BOOL CALLBACK AboutDlgProc_Range(HWND hDlg, UINT message,
                                 WPARAM wParam, LPARAM lParam);

BOOL CALLBACK AboutDlgProc_Subject_Ar(HWND hDlg, UINT message,
                              WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc_MainStudent(HWND hDlg, UINT message,
                                       WPARAM wParam, LPARAM lParam);

BOOL CALLBACK AboutDlgProc_Marks(HWND hDlg, UINT message,
                                 WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc_Merit(HWND hDlg, UINT message,
                                 WPARAM wParam, LPARAM lParam)  ;

BOOL CALLBACK AboutDlgProc_Cancel(HWND hDlg, UINT message,
                                  WPARAM wParam, LPARAM lParam);

///http://www.codeproject.com/KB/list/listview-win32-api/article_demo.zip
#endif
#define id_settimer 1
#define ED_MARKSENTRY 1
#define ED_Merit 2
#define ED_choicebox 3
#define ED_SAVE 4
#define ED_MIGRATE 5
#define ED_EXIT 6
#define ED_INDIVMARK 7
#define IDD_MARKBOX 8
#define ED_DIALOG 9
/** Combobox id  **/
#define ID_S1  1
#define ID_S2  2
#define ID_S3  3
#define ID_S4  4
#define ID_S5  5
#define ID_S6  6
#define ID_S7  7
#define ID_S8  8
#define ID_S9  9
#define ID_S10  10
#define ID_S11  11
#define ID_S12  12
#define ID_ROLL 13
#define ID_MERIT 14
#define ID_SAVECHOICE 15
/** marks Entry **/

#define ID_PHY 201
#define ID_CHE 202
#define ID_MATH 203
#define ID_ENG 204
#define ID_MARKSAVE 205

/** Merit List  **/

/**   Architect    **/
#define A_CHOICE 5001
#define A_RESULT 5002
#define A_OK  5003

#define s_choice 1000
#define s_reset 1001
#define s_com1   1002
#define  M_reset  2006

#define IDC_LOCK                                2001
#define Search_ok                               2002
#define Search_EDIT                             2003
#define IDC_COMBO1                              10000

#define P_edit                                  10002
#define P_ok                                    10003
#define Mk_CALL      601
#define Mk_R         602



#define IDC_LIST1                               1000
#define IDC_LIST2                               1001
#define IDC_LIST3                               1002
#define IDC_LIST4                               1003
#define IDC_LIST5                               1004
#define R_to                                    702
#define R_frm                                   703
#define R_ok                                    704

#define FinalResult    1101


#define Main_Student                        1200
#define S_choiceArena                           1201
#define A_choiceArena                           1202
#define S_errorArena                            1203

#define Make_REsult   1300
#define Make_Me                                 1301
#define Make_Ad                                 1302
#define Make_update                             1303
#define Make_final                              1304
#define Make_archi                              1305


#define C_Roll                                  14004
#define C_merit                                 14005
#define C_execute                               14006
#define C_check                                 14007


/// *COLOR16

#define set_G  14101
#define set_A  14102
#define set_B  14103
#define set_W  14104

#define P_Elogin 3333
#define P_Login 3334
