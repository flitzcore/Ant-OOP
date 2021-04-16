#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <time.h>


class Ant
{
   public:
    int x,y,randX,randY,sA=1,sB=0,sa,sb;

    Ant(int xIn,int yIn)
    {
        this->x=xIn;
        this->y=yIn;

        randX=rand()%500;
        randY=rand()%500;
    }
    //initiate rand
    void SetNewPoint()
    {
        randX=rand()%500;
        randY=rand()%500;
    }
    //process
    void Process()
    {
        //Walking

        if(x<randX)x+=2;
        if(y<randY)y+=2;
        if(x>randX)x-=2;
        if(y>randY)y-=2;
    }
    void Draw()
    {
        float s=1.2;
        //Gambar badan semut
        int badan[]=
        {
            x,y,
            x+(2*s),y,
            x+(3*s),y+(2*s),
            x+(2*s),y+(3*s),
            x+(3*s),y+(4*s),
            x+(3*s),y+(5*s),
            x+(2*s),y+(7*s),
            x+(3*s),y+(8*s),
            x+(3*s),y+(10*s),
            x+(2*s),y+(12*s),
            x,y+(12*s),
            x-s,y+(10*s),
            x-s,y+(8*s),
            x,y+(7*s),
            x-s,y+(5*s),
            x-s,y+(4*s),
            x,y+(3*s),
            x-s,y+(2*s),
            x,y
        };
            fillpoly(18,badan);

        //kaki
           sa=(sA%2)*s;
           sb=(sB%2)*s;
        //kaki atas
           line(x+(3*sa),y+(4*sa),x+(6*sa),y-sa);
           line(x-sa,y+(4*sa),x-(4*sa),y-sa);
        //kaki bawah
           line(x+(3*sa),y+(8*sa),x+(6*sa),y+(12*sa));
           line(x-sa,y+(8*sa),x-(4*sa),y+(12*sa));
        //kaki tengah
           line(x+(2*sb),y+(6*sb),x+(6*sb),y+(6*sb));
           line(x,y+(6*sb),x-(4*sb),y+(6*sb));


           sA++;
           sB++;

           delay(7);
    }
};



int main()
{
    initwindow(500,500);
    int h=0,i;
    //generate ant

    Ant ants[]={
        Ant(rand()%500,rand()%500),
        Ant(rand()%500,rand()%500),
        Ant(rand()%500,rand()%500),
        Ant(rand()%500,rand()%500)
            };

    //executor

    while(1)
    {
       h++;
        ;
       if(h==100)
       {
           delay(50);
           for(i=0;i<4;i++)
            {
                ants[i].SetNewPoint();
            }

           h=0;
       }

       for(i=0;i<4;i++)
       {
           ants[i].Process();
           ants[i].Draw();
       }


       delay(10);
       cleardevice();
    }


    getch();
}
