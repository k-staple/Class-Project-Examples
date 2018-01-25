// Kathryn Stapleton, section 3, 11/29
// Lab 10

#include "gfx.h"
#include <cstdlib>  //srand(), rand()
#include <unistd.h> //usleep
#include<ctime>
#include <cmath>
#include<iostream>
using namespace std;

int main () {

  const int xsize = 600, ysize = 600, radius= 10;
  char c; //for gfx_wait()
  int xpos= radius;
  int ypos= radius;
  int vx= 50, vy= 60, deltat=1;  //need to have change in v >1 or use floats
  int counter=0;

  gfx_open(xsize, ysize, "Bounce");
  while(true){
    xpos+= vx*deltat;
    ypos+= vy*deltat;
    if ((xpos-radius)<=0 || (xpos + radius) >= xsize ) {
      xpos=(xpos-radius<=0)? radius: xsize-radius;
      vx= -vx;
    }
    if ((ypos-radius)<= 0 || ypos+radius >= ysize ) {
      ypos=(ypos-radius<=0)? radius: ysize-radius;
      vy= -vy;
    }
    gfx_circle(xpos, ypos, radius);
    gfx_flush();
    usleep(100000);
    gfx_clear();

    if (gfx_event_waiting()) {
      c= gfx_wait();
      if (c==1){
        srand(time(NULL)); //initialize random seed
        vx= rand()%160 -80;  // random numbers -80 to 159
        vy= rand()%160 -80; // random numbers -80 to 159
        xpos= gfx_xpos()-vx*deltat; //lab says to put loop at end but new coords were clicked
        ypos= gfx_ypos()-vy*deltat;
      }
   }

  }

}
