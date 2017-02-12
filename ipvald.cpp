#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main(){
char s[17];
int num[4];
int anum[4],j=0,z=1,cnt=0,k;
cout<<"Enter ip address"<<endl;
cin>>s;
cout<<"The entered ip is "<<s<<endl;
for(int i = 0; i<strlen(s); i++){
	if(s[i] == '.')
		z +=1;
}

if (strlen(s)> 6 && strlen(s)<16 && s[0]!='.' && z == 4){
    //printf("The number is %d",a-'0');
    z=0;
    while(j<strlen(s)+1){
            k=j;
          while(!(s[k]== '.' || s[k]== '\0') && k<strlen(s)){
             num[cnt] = s[k]-'0';
	     cnt++;
             k++;
            }
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
            else if(cnt==3){
		anum[z]=num[0]*100+num[1]*10+num[2];
                j+=3;
                z++;
            }
	    else{
		    j++;
	    }

           cnt = 0;
     }
    int z=0,j=0;
    while(z<4){
      if(!(anum[z]<=255 && anum[z]>=0)){
	      cout<<"Error"<<endl;
		      j=1;
		      break;
      }
     z++;
   }
    if(j==0){
	cout<<"You have entered valid ip address which is "<<endl;
	for(int i=0;i<4;i++){
		if(i==3)
			cout<<anum[i]<<endl;
		else
			cout<<anum[i]<<".";
	}
    }
}
else
   cout<<"Invalid address"<<endl;
return 0;
}
                                              

