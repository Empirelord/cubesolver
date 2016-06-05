#include "arrays.cpp"       //All the nasty long, soon autogenerated, movement tables

//the turn* functions mutate the data at the first argument in place
//maybe unify all these into one function?

void turnedges(uint8_t* addr,const uint8_t move,const uint8_t n=7){
  if(move<18)       //moves >=18 are inner moves and therefore don't affect the edges
    for(uint8_t i=0;i<n;i++)
      addr[i]=edgemove[move][addr[i]];
}

void turncenters(uint8_t* addr,const uint8_t move,const uint8_t n=24){
  for(uint8_t i=0;i<n;i++)
    addr[i]=centermove[move][addr[i]];
}

void turncorners(uint8_t* addr,const uint8_t move,const uint8_t n=24){
  for(uint8_t i=0;i<n;i++)
    addr[i]=cornermove[move][addr[i]];
}

cube turncube(cube Cube,const uint8_t move){        //this should implicitly use a copy
  turnedges(Cube.edge,move);
  turncenters(Cube.center,move);
  turncorners(Cube.corner,move);
  return Cube;
}

void rotateedges(uint8_t* addr,const uint8_t move){}

void rotatecenters(uint8_t* addr,const uint8_t move,const uint8_t n=24){}

void rotatecorners(uint8_t* addr,const uint8_t move,const uint8_t n=24){}

cube rotatecube(cube Cube,const uint8_t move){
  rotateedges(Cube.edge,move);
  rotatecenters(Cube.center,move);
  rotatecorners(Cube.corner,move);
  return Cube;
}

#if symred==1
void symcenters(uint8_t* addr,const uint8_t move){
  for(uint8_t i=0;i<12;i++)
    addr[i]=centersym[move][addr[i]];
  //addr[centersym[move][i]]=centersym[move][addr[i]];??? sym^-1 * addr * sym ???
  if(move==1||move==3)
    for(uint8_t i=4;i<8;i++)      //4Byte in one?
        swap(addr[i],addr[i+4]);  //Adjust for colorswap;
}

void symcorners(uint8_t* addr,const uint8_t move){
  for(uint8_t i=0;i<8;i++)
    addr[i]=cornersym[move][addr[i]];
}
#endif

uint8_t setnibble(const uint8_t &a/*Original*/,const uint8_t &b/*Modifikation*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));          //returns the upper part of the byte when c==1 otherwise the lower part
}

uint8_t readnibble(const uint8_t &a/*Original*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;                       //sets the upper part of the byte when c==1 otherwise the lower part
}

#if tablecompression==1 || disktablegen==1
inline uint8_t set2bit(uint8_t a/*Original*/,uint8_t b/*Modifikation*/,uint8_t c/*which 2bit*/){
      return (b<<2*c)|(a&(255-(3<<2*c)));
}

inline uint8_t read2bit(uint8_t a/*Original*/, uint8_t c/*which 2bit*/){
      return (a>>2*c)&3;
}
#endif

#if tablecompression==2
const uint8_t powersof3[5]={1,3,9,27,81};   //try some optimisations if this is performance relevant
uint8_t settrit(const uint_t &a/*Eingangsbyte*/,const uint8_t &b/*Modifikation*/,uint8_t c/*which trit*/){
    return a-powerof3[c]*readtrit(a,c)+powerof3[c]*b;
}

uint8_t readtrit(const uint_t &a/*Eingangsbyte*/,uint8_t c/*which trit*/){
    return (a/powersof3[c])%3;
}

#endif

#if tablecompression==1
uint64_t nextfree(uint8_t k,uint64_t addr,uint64_t pos = 0,uint8_t ch = 0){
  uint64_t noln = addr;
  if(2*pos+1<cotabsize[k]){
    const uint8_t h[3] = {3,26,25}; //lb(cotabsize)
    uint64_t lb = 2*pos+1,rb = 2*pos+1;
    for(uint8_t i=ch+1;i<h[k];i++){
      lb=2*lb+1;
      rb=2*rb+2;
    }
    noln = (1<<(h[k]-ch-1))+min(rb,cotabsize[k])-min(lb,cotabsize[k]+1);
   }
  if(noln>=addr)
    if(noln==addr)
      return pos;
    else
      return nextfree(k,addr,2*pos+1,ch+1);
  else
    return nextfree(k,addr-noln-1,2*pos+2,ch+1);
}

uint8_t colookup(uint8_t k,uint64_t key,uint64_t addr = 0){
  if(addr>cotabsize[k])
    return 7;
  uint64_t node = (((uint64_t) cotab[k][5*addr])<<29)+(((uint64_t) cotab[k][5*addr+1])<<21)+(((uint64_t) cotab[k][5*addr+2])<<13)
                    +(((uint64_t) cotab[k][5*addr+3])<<5)+(cotab[k][5*addr+4]>>3);
  if(node==key){
    uint8_t res = cotab[k][5*addr+4]%8;
    return res+4*(res==7);
  }else
    return colookup(k,key,2*addr+1+(key>node));
}
#endif

uint8_t readtabval(uint8_t k,uint64_t pos){
#if tablecompression==0
  return readnibble(~table[k][pos/2],pos%2);
#elif tablecompression==1

#else

#endif
}

void settabval(uint8_t k,uint64_t pos,uint8_t mod){
#if tablecompression==0
  table[k][pos/2]=~setnibble(~table[k][pos/2],mod,pos%2);
#elif tablecompression==1

#else

#endif
}

bool solved(cube Cube){
  for(int i=0;i<7;i++)
    if(Cube.edge[i]!=3*i) return false;
  for(int i=0;i<24;i++)
    if(Cube.center[i]!=i || Cube.corner[i]!=i) return false;
  
  return true;
}

cube goal(void){
  cube Cube;
  for(int i=0;i<7;i++)
    Cube.edge[i]=3*i;
  for(int i=0;i<24;i++){
    Cube.center[i]=i/6;     //there are only 6 colours
    Cube.corner[i]=i;
  }
  return Cube;
}

//cube inverse(cube Cube){}   //TODO: implement for DIDA*

void printcube(cube Cube){
  cout << "edges: " ;
  for(int i=0;i<7;i++)cout << Cube.edge[i]+0 << ";";
  cout << "\ncenters: ";
  for(int i=0;i<24;i++)cout << Cube.center[i]+0 << ";";
  cout << "\ncorners: ";
  for(int i=0;i<24;i++)cout << Cube.corner[i]+0 << ";";
  cout << "\n" ;
}
