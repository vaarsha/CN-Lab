#include<iostream>
using namespace std;
void output(int **a,int m)
{
 cout<<"The output is "<<endl;
 for(int i =0; i<m; i++){
  for(int j =0; j<m; j++){
    cout<<a[i][j]<<"\t";
  }
  cout<<endl;
}
}
int main(){
int n;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
int** cmat = new int*[n];
for(int i = 0; i < n; ++i)
    cmat[i] = new int[n];
cout<<"Enter values into cost matrix"<<endl;
for(int i =0; i<n; i++){
  for(int j =0; j<n; j++){
    if(i ==j)
      cmat[i][j] = 0;
    else
      cin>>cmat[i][j];
  }
}
output(cmat,n);
for(int i = 0; i < n; ++i) {
    delete [] cmat[i];
}
delete [] cmat;
return 0;
}
