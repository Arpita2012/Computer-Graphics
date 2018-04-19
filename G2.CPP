//Drawing line using DDA algorithm
#include<iostream.h>
#include<math.h>
#include <graphics.h>
#include <conio.h>
#include<process.h>
#include<stdio.h>

void lineDDA(int x1, int y1, int x2, int y2){
	char msg[50];
	int dx = x2-x1, dy = y2 - y1, steps , k;
	float xIncrement, yIncrement, x= x1, y=y1;

	if(abs(dx) > abs(dy))
	  { steps = abs(dx);  /*  cout<<"Steps"<<steps;*/ }
	else
	   steps = abs(dy);

	xIncrement = dx / (float)steps;  // cout<<"xInc"<<xIncrement;
	yIncrement = dy / (float) steps; // cout<<"yInc"<<yIncrement;

	//plot first pixel
	putpixel(x1,y1,1245);
	moveto(x1,y1);
	sprintf(msg, " (%d, %d)", getx(), gety());
	outtextxy(x1, y1, msg);

	for(k=0; k<steps ; k++){

	   x+= xIncrement;    // cout<<"\nx= "<<x;
	   int x_ = (x+0.5);        //  cout<<"\nx_= "<<x_;
	   y+= yIncrement;    // cout<<"\ny= "<<y;
	   int y_ =(y+0.5);         // cout<<"\ny_= "<<y_;
	   putpixel(x_,y_,1245);
	  if(k==steps-1)
	  { moveto(x_,y_);
	    sprintf(msg, " (%d, %d)", getx(), gety());
	    outtextxy(x_, y_, msg);
	  }

	}
}

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
   lineDDA(x1,y1,x2,y2);

   getch();
   closegraph();
   return 0;
}