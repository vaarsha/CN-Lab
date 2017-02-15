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
   if(i>(vl+1+res)){
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
    int r=0,sk=skip+1;
    for(int i = skip+1; i<n; i +=sk){
        if(rs[i]==7){
           i+=1;
        }
        r += rs[i];
   }
    return r;
}
int main()
{
  int m,r,n,j,k,pw;
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
      if(narr[i]==7)
         narr[i]= (fndp(narr,n,i))%2;
   }
  outpt(narr,n);
  delete[] narr;
  narr = 0;
  delete[] arr;
  arr = 0;
  return 0;
}
