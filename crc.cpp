#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	int dl,div,tn=1,cnt=0;
	string val,dv,nwval;
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
	for(int i=0; i<vlen+dl-1; i++)
		cout<<data[i]; //Output the final data value
	cout<<endl;
	//Xor
	int* nwdata = new int[vlen+dl];
	for(int i = 0; i<dl; i++)
		nwdata[i] = data[i]; //Input values from data array to new data array depending on divisor length.
	int i = dl;
	int z=0;
	while(i<vlen+dl-1){
		if(nwdata[0] == 1){
			//First digit is 1.
			for(int j = 0; j<dl; j++){
				//cout<<"before value of nwdata "<<nwdata[j]<<" value of div "<<pvalue[j]<<endl;
				nwdata[j] = nwdata[j] ^ pvalue[j];
				//cout<<"New value of data "<<nwdata[j]<<endl; 
			}	
		}
		else{
			//First digit is 0.
			for(int j = 0; j<dl;j++){
				//cout<<"old value of nwdata "<<nwdata[j]<<endl;
				nwdata[j] = nwdata[j]^0;
				//cout<<" new value of nwdata is "<<nwdata[j]<<endl;
			}
		}

		for(int j = 0; j<dl-1; j++){
			//cout<<"old value of nwdata "<<nwdata[j]<<" and j value is "<<j<<" and nwdata j+1 value is "<<nwdata[j+1]<<endl;
			nwdata[j] = nwdata[j+1];
			cnt = j;
		}
		nwdata[cnt+1] = data[i];
		/*for(int k =0;k<dl;k++)
			cout<<"The new vaue of nwdata is ->"<<nwdata[k]<<endl;*/
		i++;
	}
	if(nwdata[0] == 1){
		for(int i =0; i<dl; i++)
			nwdata[i] = nwdata[i]^pvalue[i];
	}
	else{
		for(int i = 0; i<dl; i++)
			nwdata[i] = nwdata[i]^0;
	}
	cout<<"The remainder is ";
	for(int i = 1;i<dl;i++)
		cout<<nwdata[i];
	cout<<endl;

	cout<<"Enter receiver data"<<endl;
	cin>>nwval;
	cout<<"Entered received binary data is "<<nwval<<endl;
	int nwl = nwval.length();
	for(int i = 0; i<nwl; i++){
		data[i] = nwval[i] - '0';
		cout<<data[i]<<endl;
	}
	for(int i = 0; i<dl; i++)
		nwdata[i] = data[i]; //Input values from data array to new data array depending on divisor length.
	i = dl;
       	z=0;
	while(i<nwl){
		if(nwdata[0] == 1){
			//First digit is 1.
			for(int j = 0; j<dl; j++){
				//cout<<"before value of nwdata "<<nwdata[j]<<" value of div "<<pvalue[j]<<endl;
				nwdata[j] = nwdata[j] ^ pvalue[j];
				//cout<<"New value of data "<<nwdata[j]<<endl; 
			}	
		}
		else{
			//First digit is 0.
			for(int j = 0; j<dl;j++){
				//cout<<"old value of nwdata "<<nwdata[j]<<endl;
				nwdata[j] = nwdata[j]^0;
				//cout<<" new value of nwdata is "<<nwdata[j]<<endl;
			}
		}

		for(int j = 0; j<dl-1; j++){
			//cout<<"old value of nwdata "<<nwdata[j]<<" and j value is "<<j<<" and nwdata j+1 value is "<<nwdata[j+1]<<endl;
			nwdata[j] = nwdata[j+1];
			cnt = j;
		}
		nwdata[cnt+1] = data[i];
		/*for(int k =0;k<dl;k++)
			cout<<"The new vaue of nwdata is ->"<<nwdata[k]<<endl;*/
		i++;
	}
	if(nwdata[0] == 1){
		for(int i =0; i<dl; i++)
			nwdata[i] = nwdata[i]^pvalue[i];
	}
	else{
		for(int i = 0; i<dl; i++)
			nwdata[i] = nwdata[i]^0;
	}
	cout<<"The remainder is ";
	int res = 1;
	for(int i = 1;i<dl;i++){
		if(nwdata[i] == 1){
			res = 0;
		}
		cout<<nwdata[i];
	}
	cout<<endl;
	if(res == 0)
		cout<<"Received data corrupted"<<endl;

	delete[] nwdata;
	nwdata = 0;
	delete[] data;
	data = 0;
	delete[] pvalue;
	pvalue = 0;
	return 0;
}

