// Kathryn Stapleton, section 3, 11/29
// Lab 10

#include "gfx.h"
#include <cstdlib>  //srand(), rand()
#include <unistd.h> //usleep
#include <cmath>
#include<iostream>

void sqr(int xpos, int ypos, int halfLength); 

int main () {

  const int xsize = 600, ysize = 600, radius= 10;
  char c; //for gfx_wait()
  gfx_open(xsize, ysize, "Animate");
  int halfLength= 10, xpos=10,ypos=halfLength, vx= 40, dt= 1;
  int dred=0, dgreen=120, dblue=90, circRadius=15, pathRadius= ysize/4; //set default colors
  int red=dred, green=dgreen, blue=dblue;
  float theta=0, darc= .1;
  int noColor=0; 
  int xcirc= xsize/2, ycirc= ysize/2; 
  int dColor= 50;
  while(true){
    
   if ((xpos-halfLength)<=0 || (xpos + halfLength) >= xsize ) {
      xpos=(xpos-halfLength<=0)? halfLength: xsize-halfLength;
      vx= -vx;
    }
    
  

    gfx_color(red, green, blue);
    sqr(xpos, ypos, halfLength);
    gfx_circle(xcirc+pathRadius*cos(theta), ycirc+pathRadius*sin(theta), circRadius);
    gfx_flush();
    usleep(100000);
    gfx_clear();

    xpos+= vx*dt;
    theta=theta+darc;

    if (gfx_event_waiting()) {
      c= gfx_wait();
      //noColor= ((red==0 || red >= 250-dColor)&&(blue==0||blue>=250-dColor)&&(green==0||green>=250-dColor))? 1:0;
      switch (c){
        case 'r':
           red+= dColor;
           if (red<20&&blue<20&&green<20)
              red= dred, green=dgreen, blue= dblue; //default colors to prevent black
            break;
        case 'b':
             blue+= dColor;
             if (red<20&&blue<20&&green<20)
               red= dred, green=dgreen, blue= dblue; //default colors to prevent blackreak;
             break;
        case 'g':
          green+= dColor;
          if (red<20&&blue<20&&green<20)
            red= dred, green=dgreen, blue= dblue; //default colors to prevent blackreak;
          break;
        case 1: 
          if (circRadius+7 < pathRadius && circRadius+pathRadius + 2*halfLength < ycirc){
            circRadius+=5;
          }
          break;
        case 's':
          if (circRadius >=10){
            circRadius-=5;
          }break;             
      }
      if (red<10&&blue<10&&green==0)
        red= dred, green=dgreen, blue= dblue; //default colors to prevent black
   }

  }

}


void sqr(int xpos, int ypos, int halfLength){
  gfx_line(xpos-halfLength, ypos-halfLength, xpos+halfLength, ypos-halfLength);
  gfx_line(xpos-halfLength, ypos-halfLength, xpos-halfLength, ypos+halfLength);
  gfx_line(xpos+halfLength, ypos-halfLength, xpos+halfLength, ypos+halfLength);
  gfx_line(xpos-halfLength, ypos+halfLength, xpos+halfLength, ypos+halfLength);
}



