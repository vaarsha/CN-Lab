#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char ip[100];
	int i = 0, s =0;
	printf("Enter ip\n");
	scanf("%s",ip);
	while(ip[i++]!='/');
	while(ip[i]!='\0')
		s = s*10 + (ip[i++] - '0');
	int k = ~(~0 << (32-s)) + 1;
	printf("The address block is %d\n",k);

	int j = ~0;
	j = j << (32-s);

	i=0, s=0;
	int a[4],c =0;
	while(ip[i]!='/'){
		if(ip[i]!='.')
			s = s*10 + (ip[i] - '0');
		else{
			a[c++] = s;
			s = 0;
		}
		i++;
	}
	a[c] = s;

	printf("First address is %d.",a[0] & ( j>>24));
	printf("%d.",a[1]&((j>>16)&255));
	printf("%d.",a[2]&((j>>8)&255));
	printf("%d\n",a[3]&(j&255));

	j=~j;
        
	printf("Last address is %d.",a[0] | ( j>>24));
	printf("%d.",a[1]|((j>>16)&255));
	printf("%d.",a[2]|((j>>8)&255));
	printf("%d\n",a[3]|(j&255));

	return 0;
}

