//Kathryn Stapleton, lab 11 fractals
// section 3

#include "gfx.h"
#include <unistd.h>
#include <iostream>
#include <cmath>
using namespace std;

void mytriangledrawingfunction (float x1, float y1, float x2, float y2, float x3, float y3);
void sqr( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void sqrCentered(float xpos, float ypos, float halfLength);
void starLines(float xpos, float ypos, float length, float numLines);
void circularLace (float xCen, float yCen, float radius, float dR);
void sierpinski( float x1, float y1, float x2, float y2, float x3, float y3 );
void shrinking( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float halfL); //will be 1/3 prev side
void spisqr( float xCen, float yCen, float radius, float theta, float halfL, float changeTheta);
void snowflake(float xpos, float ypos, float length, float numLines);

#define PI 3.14159265

int main () {

  float width= 600, height= 600, radius= 200;
  char c;
  float go=1, margin= 20;
  gfx_open(width, height, "Fractals");
  
  while(go==1){
    c=gfx_wait();
    gfx_clear();
    switch (c){
      case '1':
        sierpinski(margin, margin, width-margin, margin, width/2, height-margin); 
        break;
      case '2':
        shrinking(width/4, height/4, 3*width/4, height/4, 3*width/4, 3*height/4, width/4, 3*height/4, width/2 );
        break;
      case '3':
        spisqr(width/2, height/2, 3*width/8, 13*PI/8, width/9, PI/3.5);
        break;
      case '4':
        circularLace(width/2, height/2, 3*width/8, .33);
        break;
      case '5':
        snowflake(width/2, height/2, height*.4, 5);
        break;
      case 'q':
        go=0;
        break;
     } 
   }


}
  
void mytriangledrawingfunction (float x1, float y1, float x2, float y2, float x3, float y3){
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x1, y1);
}

void sqr( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x4, y4);
  gfx_line(x4, y4, x1, y1);
}

void sqrCentered(float xpos, float ypos, float halfLength){
  gfx_line(xpos-halfLength, ypos-halfLength, xpos+halfLength, ypos-halfLength);
  gfx_line(xpos-halfLength, ypos-halfLength, xpos-halfLength, ypos+halfLength);
  gfx_line(xpos+halfLength, ypos-halfLength, xpos+halfLength, ypos+halfLength);
  gfx_line(xpos-halfLength, ypos+halfLength, xpos+halfLength, ypos+halfLength);

}

void starLines(float xpos, float ypos, float length, float numLines)
{ float theta= 2*PI/numLines;
  float curTheta= theta/2;
  gfx_line(xpos, ypos, xpos+length*cos(curTheta), ypos- length*sin(curTheta));
  for (int i= 0; i<numLines-1; i++){
    curTheta+= theta;
    gfx_line(xpos, ypos, xpos+length*cos(curTheta), ypos- length*sin(curTheta));
  }
}

void sierpinski( float x1, float y1, float x2, float y2, float x3, float y3 )
{
   // Base case. 
   if( abs(x2-x1) < 2 ) return;

   // Draw the triangle
   mytriangledrawingfunction( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}  

void circularLace (float xpos, float ypos, float radius, float dR) {
  if (radius<1) return;
  
  gfx_circle(xpos, ypos, radius);

  radius*= dR;

  //Recursive
  circularLace(xpos+radius/dR, ypos, radius, dR);  
  circularLace(xpos+radius*cos(PI/3)/dR, ypos-radius*sin(PI/3)/dR, radius, dR);  
  circularLace(xpos-radius*cos(PI/3)/dR, ypos-radius*sin(PI/3)/dR, radius, dR);  
  circularLace(xpos-radius/dR, ypos, radius, dR);  
  circularLace(xpos-radius*cos(PI/3)/dR, ypos+radius*sin(PI/3)/dR, radius, dR);  
  circularLace(xpos+radius*cos(PI/3)/dR, ypos+radius*sin(PI/3)/dR, radius, dR);  


}

void shrinking( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float halfL){

  if( abs(x2-x1) < 2) return;
 
  sqr( x1, y1,  x2, y2, x3, y3, x4,y4);
  
  //recursive
  halfL /= 3;
  shrinking( x1-halfL, y1-halfL, x1+halfL, y1-halfL, x1+halfL, y1+halfL, x1-halfL, y1+halfL, halfL);
  shrinking( x2-halfL, y2-halfL, x2+halfL, y2-halfL, x2+halfL, y2+halfL, x2-halfL, y2+halfL, halfL);
  shrinking( x3-halfL, y3-halfL, x3+halfL, y3-halfL, x3+halfL, y3+halfL, x3-halfL, y3+halfL, halfL);
  shrinking( x4-halfL, y4-halfL, x4+halfL, y4-halfL, x4+halfL, y4+halfL, x4-halfL, y4+halfL, halfL);


}

void spisqr( float xCen, float yCen, float radius, float theta, float halfL, float changeTheta) {


  if (radius< 5) return; 
  sqrCentered( xCen+radius*cos(theta), yCen-radius*sin(theta), halfL); //minus since y inc downward

  //recursive
  halfL *= .8;
  radius *= .90;
  theta = theta - changeTheta;
  changeTheta *= .9;

  spisqr( xCen, yCen, radius, theta, halfL, changeTheta); //minus since y inc downward
}

void snowflake(float xpos, float ypos, float length, float numLines)
{ if (length< 3) return;

  starLines(xpos, ypos, length, numLines);
  float theta= 2*PI/numLines;
  length*= .7;
  float oldL= length/.7;

  snowflake(xpos + oldL*cos(theta/2), ypos - oldL*sin(theta/2), length, numLines);
  snowflake(xpos + oldL*cos((theta/2)+theta), ypos - oldL*sin((theta/2)+theta), length, numLines);
  snowflake(xpos + oldL*cos((theta/2)+2*theta), ypos - oldL*sin((theta/2)+2*theta), length, numLines);
  snowflake(xpos + oldL*cos((theta/2)+3*theta), ypos - oldL*sin((theta/2)+3*theta), length, numLines);
  snowflake(xpos + oldL*cos((theta/2)+4*theta), ypos - oldL*sin((theta/2)+4*theta), length, numLines);
}
