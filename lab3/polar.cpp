// Lab 3, Part 2 Quadrants. Section 3
// Kathryn Stapleton Sept 14, 2017

#include <iostream>
#include <cmath>
using namespace std;

float polarRad (float a, float b);

// returns angle in degrees; CITE: to review how to find polar coord: tutorial.math.lamar.edu/Classes/CalcII/PolarCoordinates.aspx
float polarAng (float a, float b);

// finds quadrant, axis, or origin
string location (float a, float b);

int main () {

   // initialize
   float x=0;
   float y=0;

   // ask for input
   cout << "For which coordinate (x,y) would you like the polar coordinates and location? \nPress enter after each number. \nx:   " << endl;
   cin >> x;
   cout << "y: " << endl;
   cin >> y;

   // display polar coord and location
   cout << "The polar coordinates are (" << polarRad (x, y) << ", " << polarAng (x,y) 
   <<  " degrees)." << endl;
   cout << "The point's location is " << location(x,y) << endl;

   return 0;
}

float polarRad (float a, float b) {
   float rad=0;
   rad= sqrt( (pow(a,2)) + (pow(b,2)) );

   return rad;
}

float polarAng (float a, float b) {
   float ang= (atan(b/a))*360/6.2832;                
  /*CITE: Tommy Clare said he used atan and one line not atan2 and two lines for declaring the variable
   and assigning arctan(y/x) to that variable */

   //modify angle, x less than 0 need +180, 0<=x and y<0 need +360
   if (a==0 && b==0){
      ang= 0;
   } else if (a<0){
      ang= ang +180;
   } else if (a>= 0 && b<0){
      ang= ang +360;
   }
  
   
   return ang;
}

string location (float a, float b) {
   string loc = "";

   // if axis or origin
   if (a==0 && b==0){
      loc= "at the origin.";
   } else if (a== 0) {
      loc= "on the x-axis.";
   } else if (b== 0) {
      loc= "on the y-axis.";
   } else if (a>0 && b>0) {
      loc= "in the first quadrant.";
   } else if (a<0 && b>0) {
      loc= "in the second quadrant.";
   } else if (a<0 && b<0) {
      loc= "in the third quadrant.";
   } else {
      loc= "in the fourth quadrant.";
   }


   return loc;
}
