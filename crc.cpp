#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	int dl,div,tn=1,cnt=0;
	string val,dv;
	cout<<"Enter binary data"<<endl;
	cin>>val;
	cout<<"Entered value is "<<val<<endl;
	cout<<"The enter divisor value is "<<endl;
	cin>>dv;

	dl = dv.length(); //divisor length.
	int* pvalue  = new int[dl];
	for(int i=0; i<dl; i++)
		pvalue[i]=dv[i]-'0';  //divisor value from string stored in integer array.

	int vlen = val.length();
	cout<<"String length "<<vlen<<endl;
	int* data = new int[vlen+dl-1];
	for(int i = 0; i<vlen; i++)
		data[i] = val[i]-'0'; //binary data stored in integer array.
	for(int i = vlen; i<vlen+dl-1; i++)
		data[i] = 0; // appended divisor length -1  zeroes to integer array.
	for(int i=0; i<vlen+dl-1; i++){
		cout<<data[i];
		cout<<"The value in data is "<<data[i]<<" and i value is "<<i<<endl;
		cnt += 1;
	}
	cout<<"count is "<<cnt<<endl;
	//Xor
	int* nwdata = new int[vlen+dl];
	for(int i = 0; i<dl; i++){
		nwdata[i] = data[i];
		cout<<"data in nw to be "<<nwdata[i]<<endl;
	}
	int i = dl;
	int z=0;
	while(i<vlen+dl-1){
		if(nwdata[0] == 1){
			cout<<" first digit is 1"<<endl;
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
	}
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

