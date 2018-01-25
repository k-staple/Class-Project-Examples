// Kathryn Stapleton, section 3, lab 7
From the user's perspective, the program will have them import a valid 
file, and display a menu of options. The options will repeat until the 
user quits. 
From the programmer's perspective, main is a driver for the interface 
and implementation files of the State class. It asks for a valid file 
input, reads the lines into a vector using getline, stoi, and push_back. 
Then, a while loop displays options for the user. The chosen option 
indicates a switch case which have functions in them (except for the 
quit case). The functions make use of State methods by getting and 
setting values.
I verified that the program could produce a list of states with a 
mininum number of representatives by choosing just under California's 
number and correctly only California showed up. I then changed 
California's numbers of rep.s and checked the list for the same number 
of rep.s; California correctly did not appear.
