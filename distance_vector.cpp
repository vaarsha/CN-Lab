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
int n, src;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
int** cmat = new int*[n];
for(int i = 0; i < n; ++i)
    cmat[i] = new int[n];
cout<<"Enter values into cost matrix, 999 for infinity"<<endl;
for(int i =0; i<n; i++){
  for(int j =0; j<n; j++){
    if(i ==j)
      cmat[i][j] = 0;
    else
      cin>>cmat[i][j];
  }
}
cout<<"Enter source vertex"<<endl;
cin>>src;

output(cmat,n);
cout<<"The source vertex is "<<src<<endl;

//Bellman-Ford algorithm.
int *d = new int[n];
for(int i = 0; i < n; i++) {
	if(i == src)
		d[i] = 0;
	d[i] = 999;
}

delete [] d;
for(int i = 0; i < n; ++i) {
    delete [] cmat[i];
}
delete [] cmat;
return 0;
}
