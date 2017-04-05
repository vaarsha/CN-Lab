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

for(int u = 0; u < n; u++){
	for(int v = 0; v < n ; v++){
		if(u != v) {
			int w = cmat[u][v];
			if(d[u] != 999 && d[u]+w <= d[v])
				d[v] = d[u] + w;
		}
	}
}
//Check for negative weight cycles.
for(int u = 0; u < n; u++){
	for(int v = 0; v < n; v++){
		if(d[u] != 999 && d[u] + cmat[u][v] < d[v])
			cout<<"Error graph contains negative weight cycle"<<endl;
	}
}

delete [] d;
for(int i = 0; i < n; ++i) {
    delete [] cmat[i];
}
delete [] cmat;
return 0;
}
