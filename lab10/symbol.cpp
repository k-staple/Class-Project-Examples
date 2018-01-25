//Kathryn Stapleton, section 3
#include "gfx.h"
#include <cmath>

void sqr(int xpos, int ypos, int halfLength);
void triangle(int xpos, int ypos, int centerToEdge);
void polygon(int xpos, int ypos, float numSides);

int main(){

  const int xsize= 600, ysize= 600;
  char c;
  int xpos, ypos;
  int go=1;

  //open window
  gfx_open(xsize, ysize, "Symbolic Typewriter");

  while (go==1){
    c = gfx_wait();
    xpos= gfx_xpos();
    ypos=gfx_ypos();
    float numSides;
    switch (c){
      case 1:
        gfx_color(0,0,200);
        sqr(xpos, ypos, 12);
        break;
      case 't':
        gfx_color(0, 200, 0);
        triangle(xpos, ypos, 7);
        break;
      case 'c':
        gfx_color(250,250,250);
        gfx_circle(xpos,ypos,4); //with circ of 25, r ~4
        break;        
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        gfx_color(200,0,200);
        numSides= c-'0';
        polygon(xpos, ypos, numSides); 
        break;
      case 27:
        gfx_clear();
        break;
      case 'q':
        go=0;
        break;
    }
  }
}


void sqr(int xpos, int ypos, int halfLength){
  gfx_line(xpos-halfLength, ypos-halfLength, xpos+halfLength, ypos-halfLength);
  gfx_line(xpos-halfLength, ypos-halfLength, xpos-halfLength, ypos+halfLength);
  gfx_line(xpos+halfLength, ypos-halfLength, xpos+halfLength, ypos+halfLength);
  gfx_line(xpos-halfLength, ypos+halfLength, xpos+halfLength, ypos+halfLength);

}

void triangle(int xpos, int ypos, int centerToEdge){
        gfx_line(xpos, ypos-(2*centerToEdge), xpos+(2*centerToEdge), ypos+centerToEdge);
        gfx_line(xpos+(2*centerToEdge), ypos+centerToEdge, xpos-(2*centerToEdge), ypos+centerToEdge);
        gfx_line(xpos-(2*centerToEdge), ypos+centerToEdge, xpos, ypos-(2*centerToEdge));
}

void polygon(int xpos, int ypos, float numSides){
float theta, radius, secondAngle, drawSides;
theta= 2*3.1415/numSides;
        radius= sqrt(288/(1-cos(theta)))+1; //using law of cosines to get the side of the polygon close to 25. I rounded 25 in 25^2/2 to 24 to get 288. The +1 is round up decimals
        for (drawSides=0; drawSides<numSides; drawSides++){
          secondAngle= theta+ (2*3.1415/numSides);
          gfx_line(xpos+radius*cos(theta), ypos+radius*sin(theta), xpos+radius*cos(secondAngle), ypos+radius*sin(secondAngle));
          theta= secondAngle;
        } 
 }


