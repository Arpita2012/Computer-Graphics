//Drawing line using slope intercept formula
#include<iostream.h>
#include <graphics.h>
#include <conio.h>
#include<process.h>
#include<stdio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
    char msg[80];
   int x1,y1,x2,y2;
   int x_initial,x_end,y_initial,y_end;
   float m,b,z;
   cout<<"Enter coordinates of first point\n";
    cin>>x1>>y1;
   cout<<"Enter coordinates of second point\n";
    cin>>x2>>y2;


   /* initialize graphics, local variables */
   initgraph(&gdriver, &gmode, "c:/TC/BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      cout<<"Graphics error: "<< grapherrormsg(errorcode);
      cout<<"Press any key to halt:";
      getch();
      exit(1);
   /* terminate with an error code */
   }

   if(x2-x1==0)
   {
     if(y2-y1==0)
     { putpixel(x1,y1,202235);
     }
     else{
       if(y1<y2)
       { y_initial = y1;
	 y_end =y2;
       }else{
	 y_initial = y2;
	 y_end =y1;
       }
       // For slope = infinity
       for(int y=y_initial;y<=y_end;y++)
	{ putpixel(x1,y,202235);

	  if(y==y_initial||y==y_end)
	  {  moveto(x1,y);
	    sprintf(msg, " (%d, %d)", getx(), gety());
	    outtextxy(x1, y, msg);
	  }
	}

     }

   }else{

   m=(float)(y2-y1)/(float)(x2-x1);
   b=y1-m*x1;
//   cout<<m;   getch(); cout<<b;   getch();



    if(x1<x2)
       { x_initial = x1;
	 x_end =x2;
    }else{
	 x_initial = x2;
	 x_end =x1;
       }

   for(int x=x_initial;x<=x_end;x++)
   {
   z=m*x+b;
   int y = z;
   putpixel(x,y,202235);
	  if(x==x_initial||x==x_end)
	  {  moveto(x,y);
	    sprintf(msg, " (%d, %d)", getx(), gety());
	    outtextxy(x, y, msg);
	  }


   }
   }

   getch();
   closegraph();
   return 0;
}
