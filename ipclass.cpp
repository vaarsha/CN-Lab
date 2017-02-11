#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
using namespace std;
int binry(int nm){
int rm,bnum=0,i=1;
while(nm!=0){
rm = nm%2;
nm /= 2;
bnum +=rm*i;
i *= 10;
}
return bnum;
}
int decm(long long nm){
int rm,dm=0,i=0;
while(nm!=0){
rm = nm%10;
nm /=10;
for(int j = 0;j<9;j
decm += rm*((int)pow(2,i));
++i;

decm += rm*((int)pow(2,i));
++i;
}
return dm;
}

int main(){
string ip;
int ln,num=0,h,pw=1,cnt=0,ten=1;
long long mn=0;
cout<<"Enter IP address"<<endl;
cin>>ip;
cout<<"Your entered ip is "<<ip<<endl;
ln=ip.length();
for(int i = ln-1;i>=0&&ip[i]!='/' ;i--){
     num +=(ip.at(i)-'0')*ten;
     ten *= 10;
}
cout<<"The number of bits reserved for network are "<<num<<endl;
h=32-num;
cout<<"The number of bits reserved for host are "<<h<<endl;
/*for(int i = 0;i<h;i++){
   pw=pw*2;
}*/
pw = pow(2,h);
pw = pw-2;
cout<<"The number of networks and hosts possible are "<<pw<<endl;
cout<<"Masking"<<endl;
int * m = NULL;
m = new int(32);
for(int i=0;i<num;i++,cnt++){
 m[i] = 1;
 cout<<m[i]<<"and"<<cnt<<endl;
}
for(int i = cnt+1;i<32;i++){
m[i] = 0;
}
int o=0;
for(int i = 0; i<32;i++){
cout<<m[i];
if(m[i] == 1){
o++;
}
}
cout<<endl<<o;

cout<<"Converting to binary"<<endl;
cout<<binry(32)<<endl;
cout<<"Converting to decimal"<<endl;
mn = 1111;
cout<<decm(mn)<<endl;
return 0;
}

