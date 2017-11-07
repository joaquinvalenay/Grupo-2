#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
int MapW,MapH;
char Map[100][100]={
"########################################################",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"########################################################"};
struct Block{
    int x,y;
};

void gotoxy(int x, int y)
{
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawMap(vector <Block>j)
{
    MapH=0;
    system("cls");
    for (int i=0;Map[i][0];i++)
    {
        MapW=0;
        for (int j = 0 ;Map[i][j];j++)
        {
            MapW++;
            if (Map[i][j]!=' ')
            {
                gotoxy(j,i);
                cout<<Map[i][j];
            }
        }
        MapH++;
    }
    for (int i =0 ;i<j.size();i++)
    {
        gotoxy(j[i].x,j[i].y);
        cout<<char (219);
    }
}

bool checkLose(int x, int y,vector <Block>&j)
{
    if (Map[y][x]=='#')
        return true;
    return false;
}

void Init(int x,int y ,vector<Block> &j)
{
    Block newj;
    newj.x=x;
    newj.y=y;
    j.push_back(newj);
}

bool Move(vector<Block>&j,short dire[2])
{
    int oldx,oldy,x,y;
    gotoxy(j[j.size()-1].x,j[j.size()-1].y);
    cout<<" ";
    oldx=j[0].x;
    oldy=j[0].y;
    j[0].x+=dire[0];
    j[0].y+=dire[1];
    gotoxy(j[0].x,j[0].y);
    cout<<char(219);
    if (j.size()>1)
    {
        for (int i = 1;i<j.size();i++)
        {
            x=j[i].x;
            y=j[i].y;
            j[i].x=oldx;
            j[i].y=oldy;
            oldx=x;
            oldy=y;
        }
    }
    if (checkLose(j[0].x,j[0].y,j))
        return true;
    return false;
}

int main()
{
    bool GameIsRunning=true;
    int GameSpeed=80;
    short dire[2]={0,1};
    vector<Block> j;
    Init(1,1,j);
    drawMap(j);
    while (GameIsRunning)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            if (dire[1]==0)
            {
                dire[1]=-1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (dire[1]==0)
            {
                dire[1]=1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=-1;
            }
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=1;
            }
        }
        if(Move(j,dire))
        {
          system("cls");
          cout<<"Game Over"<<endl;
          system("pause");
          return 0;
        }
        Sleep(GameSpeed);
    }
}
