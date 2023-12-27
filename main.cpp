#include<iostream>
#include<conio.h>
#include<windows.h>
#define H 21
#define W 51
using namespace std;
int collection=0;
bool game_end=false;
int py=1,px=1;
int e1y=1,e1x=W-3;
int e2y=H-2,e2x=1;

void draw_playfield(char playfield[][W])
{
    cout<<"\n";
    for(int i=0;i<H;i++)
    {
        cout<<"\t";
        for(int j=0;j<W;j++)
        {
            cout<<playfield[i][j];
        }
        cout<<"\n";
    }
    cout<<"\t ebratul and limon your score is "<<collection<<endl;

}

void setup(char playfield[][W])
           {
            for(int i=0;i<H;i++)
            {
                for(int j=0;j<W;j++)
                {
                    if(playfield[i][j]=='#')
                    {
                        playfield[i][j]=' ';
                    }
                if(playfield[i][j]=='@')
                {
                    playfield[i][j]='.';
                }
            }
    }
           if(playfield[py][px]=='.')
           {
               collection++;
           }
           if(playfield[py][px]=='*')
           {
               py=1;
               px=1;
           }
           playfield[py][px]='#';
           playfield[e1y][e1x]='@';
           playfield[e2y][e2x]='@';

           if(playfield[py][px]=='@')
           {
               game_end= true;
           }
    }

           void result()
           {
               system("cls");
               if(collection ==670)
               {
                   cout<<"\n\n\n\n";
                   cout<<"\t\t\t  congratulation! EBRATUL AND LIMON\n";
                   cout<<"\t\t\t you won the game!\n";
                   cout<<"\t\t\t your total score is:"<<collection<<endl;
               }
               else {
                cout<<"\n\n\n\n\n";
                cout<<"\t\t\t  hello ,Ebratul and Limon ,you lost the game!\n";
                cout<<"\t\t\t your total score is :"<<collection<<endl;
               }
           }

           void enemymove()
           {
               if(e1y==1&&e1x>1)
               {
                   e1x--;
               }
               else if(e1x==1&& e1y<10)
               {
                   e1y++;
               }
               else if(e1y==10 && e1x<W-3)
               {
                   e1x++;
               }
               else if(e1x==W-3 && e1y>1)
               {
                   e1y--;
               }


              if(e2y==H-2&& e2x<W-3)
              {
                  e2x++;
              }
              else if(e2x==W-3&&e2y>10)
              {
                  e2y--;
              }
              else if(e2y==10&&e2x>1)
              {
                  e2x--;
              }
              else if(e2x==1&& e2y<H-2)
              {
                  e2y++;
              }
           }
           void playermove()
           {
               char ch;
               if(kbhit())
               {
                   ch=getch();
                   switch(ch)
                   {
                       case 72:
                       py--;
                       break;

                       case 80:
                        py++;
                        break;

                       case 75:
                        px--;
                        break;

                       case 77:
                        px++;
                        break;
                   }
               }
           }

int main()
{
    char playfield[H][W]={
        "**************************************************",
        "*................................................*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*................................................*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*.....*.....*.....*.....*.....*.....*.....*......*",
        "*................................................*",
        "**************************************************",

        };

        while(!game_end)
        {
            system("cls");
            setup(playfield);
            playermove();
            enemymove();
            draw_playfield(playfield);
            Sleep(20);
        }
        result();

        return 0;
}
