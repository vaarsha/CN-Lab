#include<iostream>
#include<stdlib.h>
using namespace std;
void outpt(int res[],int val){
  cout<<"The data is ";
  for(int i =0; i<val; i++)
    cout<<res[i];
  cout<<endl;
}
int fmin(int vl){
  int res = 0, i =1;
  while(true){
   if(i>=(vl+1+res)){
     break;
   }
   i *= 2;
   res++;
  }

  return res;
}
int power(int n){
int i =1;
if(n == 0)
 return i;
else{
  while(n>0){
     i *= 2;
     n--;
  }
  return i;
}
}
int fndp(int rs[],int n,int skip){
    int r=0,sk=skip-1,k=0;
    int i =sk;
    //cout<<"The skip value is "<<skip<<endl;
    while(i<n){
	    //cout<<" i value is -->> "<<i<<endl;
	    for(int j = 0; j<skip && i<n; j++){
		    if(rs[i]!=7){ 
			    r += rs[i];
		    }
		    i++;
		    k++;
	    }
	    i = sk +  2*k;
    }
    return r;
}
int main()
{
  int m,r,n,j,k,pw,rsz;
  string rdata;
  cout<<"Enter the number of bits for the message"<<endl;
  cin>>m;
  int*arr = new int[m];
  cout<<"Enter bits into the array"<<endl;
  for(int i = 0; i<m; i++)
      cin>>arr[i];
  outpt(arr,m);
  r = fmin(m);
  cout<<"The minimum value is "<<r<<endl;
  n = m+r;
  int*narr = new int[n];
  j=0;
  k =0;
  for(int i = 0; i<n && k<m;i++){
         pw = power(j);
         if(pw==(i+1)){
            //cout<<"The j value here is "<<j<<endl;
            narr[i] = 7;
            //cout<<"narr[i] is -> "<<narr[i]<<endl;
            j++;
         }
         else{
             //cout<<"the k value is "<<k<<" j value is "<<j<<endl;
             narr[i] = arr[k];
             //cout<<"narr[i] is ==> "<<narr[i]<<endl;
             k++;
          }
  }
  outpt(narr,n);
  for(int i = 0;i<n;i++){
      if(narr[i]==7){
	     // cout<<"The sending i value is "<<i<<endl;
	      narr[i]= (fndp(narr,n,i+1))%2;
	     // cout<<"The new value of narr is "<<narr[i]<<endl;
      }
   }
  outpt(narr,n);
  cout<<"Enter the received data"<<endl;
  cin>>rdata;
  rsz=rdata.length();
  cout<<"The length of received data is "<<rsz<<endl;
  if(rsz!=n)
	  cout<<"Invalid data"<<endl;
  else{
	  int*rarr = new int[rsz];
	  for(int i = 0; i<rsz;i++)
		  rarr[i] = rdata[i]-'0';
	  outpt(rarr,rsz);
	  delete[] rarr;
	  rarr = 0;
  }
  delete[] narr;
  narr = 0;
  delete[] arr;
  arr = 0;
  return 0;
}
