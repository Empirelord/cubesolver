#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define centercount 8
#define cornercount 8

using namespace std;

typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

uint8_t *table[3];
const int64_t tablesize[3] = {
#if centercount==8
25741485,
#else
46849502700,
#endif
#if cornercount==6
48454560,
#else
14827095360,
#endif
44089920};

const char* tablepath[3] = {"centers.bin","corners.bin","edges.bin"};
const char* comppath[2]  = {"centers.cmp","corners.cmp2"};
const char* tablename[3] = {"center","corner","edge"};
//const uint8_t  elemsize [3] = {7,8,6};
//const uint8_t  elemsol[3][8]= {{0,3,6,9,12,15,18,0},{0,1,2,3,8,9,10,11},{0,1,2,3,4,5,0,0}};

uint8_t solution[20];

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "ifshit.cpp"
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "prefixcode.cpp"
#include "solve.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

//thread t1(gentable[0]);					//parallel creation and loading of the tables
//thread t2(gentable[1]);
//thread t3(gentable[2]); 
//t1.join();
//t2.join();
//t3.join();

gentable(0);
gentable(1);
gentable(2);

//convert(1);

uint8_t n = 12;

//cube Cube=goal();
//Cube.corner[4]=5;
//Cube.corner[5]=4;

cube Cube=goal();
uint8_t moves[15]={29, 3, 33, 21, 10, 34, 1, 35, 11, 25, 16, 5, 35, 16, 0};
for(uint8_t i=0;i<n;i++) Cube=movecube(Cube,moves[i]);
printcube(Cube);

cout << minDepth(Cube)+0 << "\n";

for(uint8_t i=minDepth(Cube);i<=n&&(!solve(Cube,i));i++)
  cout << "finished depth " << i+0 << "\n";
//solve(Cube,7);
for(uint8_t i=0;i<n;i++)cout << solution[i]+0 << ";"; cout << "\n";

}
