#include <iostream>             //text in/output
#include <fstream>              //file in/output
#include <cstdlib>
#include <algorithm>            //?swap? and merge
#include <future>               //threads
#include <stdint.h>             //usefull integer names
#include <limits.h>
#include <string.h>
#include <math.h>               //quberoot, redundant now?

//Number of centerpieces to use, 8,12 or 24 considerable memory use implications
#define centercount 12
//Number of cornerpieces to use, 8,9 (or 12)
#define cornercount  8
//Utilise rotation/mirror symmetrie to reduce position count
#define symred 0
//Whether to use additive tables or plain maximum ones
#define addtables 0
//How to compress the tables in memory, 0: nibbles, 1: 2bit + lookup tree, 2: mod 3
#define tablecompression 0
//How to use the disk during table creation, 0: don't, 1: 2bit in memory, 2: memory cached bfs
#define disktablegen 0
//how many threads to use to generate the tables
#define corecount 4

using namespace std;

//the cube structure stores at which position the indexed part is.
typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

#include "tablecount.cpp"
const char* tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
const char* tablename[3] = {"edge","center","corner"};

uint8_t solution[36][20];               //TODO: this is most ugly, fix it!

#include "arrays.cpp"

#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"				    	//un/ranking of the permutations for table lookup
#include "create.cpp"					//creates the various pattern databases
#include "solve.cpp"					//the actual search algorithms to solve a given cube

int main(int argc, char** argv) {

for(uint8_t i=0;i<10;i++)
    solution[0][i]=i;

cout << *((uint64_t*) solution+0)+0 << "\n";

/*
  for(uint8_t i=0;i<3;i++)                //generate the tables, one after another
    gentable(i);
  
  //the following are example positions for testing purposes
  
  uint8_t n = 15;
  
  //cube Cube=goal();
  //Cube.corner[4]=5;
  //Cube.corner[5]=4;
  
  cube Cube=goal();
  uint8_t moves[15]={29, 3, 33, 21, 10, 34, 1, 35, 11, 25, 16, 5, 35, 16, 0};
  for(uint8_t i=0;i<n;i++) Cube=movecube(Cube,moves[i]);
  //printcube(Cube);
  
  cout << minDepth(goal())+0 << "\n";
  
  cout << minDepth(Cube)+0 << "\n";
  
  for(uint8_t i=minDepth(Cube);i<=n&&(!solve(Cube,i));i++)
    cout << "finished depth " << i+0 << "\n";
  for(uint8_t j=0;j<36;j++){
    for(uint8_t i=0;i<n;i++)
      cout << solution[j][i]+0 << ";"; 
    cout << "\n";
  }
*/
}
