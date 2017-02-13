#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	int dl,div,tn=1;
	string val,dv;
	cout<<"Enter binary data"<<endl;
	cin>>val;
	cout<<"Entered value is "<<val<<endl;
	cout<<"The entered divisor value is "<<endl;
	cin>>dv;
	dl = dv.length();
	int* pvalue  = new int[dl];
	for(int i=0; i<dl; i++)
		pvalue[i]=dv[i]-'0';
	int vlen = val.length();
	cout<<"String length "<<vlen<<endl;
	int* data = new int[vlen+dl];
	for(int i = 0; i<vlen; i++)
		data[i] = val[i]-'0';
	for(int i = vlen; i<vlen+dl-1; i++)
		data[i] = 0;
	for(int i=0; i<vlen+dl-1; i++)
		cout<<data[i];
	//Xor
	int* nwdata = new int[vlen+dl];
	for(int i = 0; i<dl; i++)
		nwdata[i] = data[i];
	int i = dl;
	int z=0;
	do{
		if(nwdata[0] == 1){
			for(int j = 0; j<dl; j++)
				nwdata[j] = nwdata[j] ^ pvalue[j];
		}
		else{
			for(int j = 0; j<dl;j++)
				nwdata[j] = nwdata[j]^0;
		}
		for(int j = 0; j<dl-1; j++)
			nwdata[j] = nwdata[j+1];
		nwdata[dl] = data[i];
		i++;
	}while(i<vlen+dl-1);
	for(int i = 0;i<dl;i++)
		cout<<nwdata[i]<<endl;
	delete[] nwdata;
	nwdata = 0;
	delete[] data;
	data = 0;
	delete[] pvalue;
	pvalue = 0;
	return 0;
}

