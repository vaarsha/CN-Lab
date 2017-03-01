#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define bsize 512
using namespace std;
void sent(int bz){
unsigned int microseconds = 2000;
while(bz>0){
     cout<<"the sent packet size"<<100<<endl;
     usleep(microseconds*1000);
     bz -= 100;
   }
}
int packets(){
  srand(time(NULL));
  int bz = rand()%1000;
  cout<<"The packet size is "<<bz<<endl;
  return bz;
}
void lpak(int bzt){
int b;
  b = bzt%100;
  bzt -= b;
  sent(bzt);
  cout<<" The last packet sent is "<<b<<endl;
}
int buffempt(){
int ipt,bz,b;

   //cout<<"Enter bucket size"<<endl;
   //cin>>bz;
   bz = packets();
   if(bz>bsize)
      return -1;
   lpak(bz);
   return 0;
}


int buf(){
int bufsz,rs,bz;
 srand(time(NULL));
   bufsz = rand()%bsize;
   cout<<"current buffer size is "<<bufsz<<endl;
   bz = packets();
   rs = bufsz + bz;
   if(bz>bsize || rs>bsize){
     return -1;
   }
   lpak(bz);
   return 0;
}
int main(){
int ipt,i;
while(1){
cout<<"Enter 1:empty buffer 2:buffer with some value 3: exit"<<endl;
cin>>i;
if(i == 3)
 break;
switch(i){
 case 1: while(1){
   cout<<"Enter 1:allow packets 2:exit"<<endl;
   cin>>ipt;
   if(ipt == 2)
      break;
    if(buffempt()== -1)
       cout<<"Error with empty"<<endl;
  }
 break;
 case 2: while(1){
   cout<<"Enter 1:allow packets 2:exit"<<endl;
   cin>>ipt;
   if(ipt == 2)
      break;
   if(buf() == -1)
     cout<<"Error"<<endl;
  }
  break;
 default: cout<<"Invalid input"<<endl;
}
}
return 0;
}
