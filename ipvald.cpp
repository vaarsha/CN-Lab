#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main(){
char s[17];
int num[4];
int anum[4],j=0,z=0,cnt=0,k;
cout<<"Enter ip address"<<endl;
cin>>s;
cout<<"hello"<<endl;
if (strlen(s)> 6 && strlen(s)<16){
    //printf("The number is %d",a-'0');
    while(j<strlen(s)+1){
            k=j;
            cout<<j<<endl;
            while(s[k]!='.' || s[k]!= '\0' && k<strlen(s)){
             cout<<k<<"this is"<<endl;
             num[cnt] = s[k]-'0';
             cnt++;
             k++;
            }
           for(int g =0;g<cnt;g++)
           cout<<num[g]<<endl;
            if(cnt == 1){
               anum[z]=num[0];
               j+= 1;
               z++;
            }
            else if(cnt==2){
                anum[z]=num[0]*10+num[1];
                j+=2;
                z++;
            }
            else{
               anum[z]=num[0]*100+num[1]*10+num[0];
               j+=3;
             z++;
            }

           cnt = 0;
     }
    int z=0;
    while(z<4){
      if(anum[z]>=255 && anum[z]>=0)
       continue;
      else{
        cout<<"Error";
        break;
      }
     z++;
   }
}
else
   cout<<"Invalid address"<<endl;
return 0;
}
                                              

