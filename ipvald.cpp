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
//This checks number of dots in the string.
for(int i = 0; i<strlen(s); i++){
	if(s[i] == '.')
		z +=1;
}

if (strlen(s)> 6 && strlen(s)<16 && s[0]!='.' && z == 4){
    //printf("The number is %d",a-'0');
    z=0;
    //j is the index, which points to current value of array.
    while(j<strlen(s)+1){
            k=j;
          while(!(s[k]== '.' || s[k]== '\0') && k<strlen(s)){
	     //converts char into integer.
             num[cnt] = s[k]-'0';
	     cnt++; //keeps track of digits in a number.
             k++;
            }
	    //For one digit number.
            if(cnt == 1){
               anum[z]=num[0];
               j+= 1;
               z++;
            }
	    //For two digit number.
            else if(cnt==2){
                anum[z]=num[0]*10+num[1];
                j+=2;
                z++;
            }//For three digit number.
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
	cout<<"Now let's find the class to which it belongs"<<endl;
	if(0 <= anum[0] && anum[0]<128)
		cout<<"It's class A"<<endl;
	else if(127<anum[0] && anum[0]<192)
		cout<<"It's class B"<<endl;
	else if(191<anum[0] && anum[0]<224)
		cout<<"It's class C"<<endl;
	else if(223<anum[0] && anum[0]<240)
		cout<<"It's class D"<<endl;
	else if(239<anum[0] && anum[0]<256)
		cout<<"It's class E"<<endl;
	else
		cout<<"Out of range"<<endl;
    }
}
else
   cout<<"Invalid address"<<endl;
return 0;
}
                                              

