#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsz 21
int main()
{
	//Allocate memory and check it's availability.
	int fsz,i;
	char *s = malloc(maxsz);
	if(s == NULL){
		printf("Not enough memory\n");
		return 1;
	}	
	printf("Enter a String\n");
	fgets(s,maxsz,stdin);
	printf("it is %s",s);
	printf("Enter frame size:");
	scanf("%d",&fsz);
	if(fsz>strlen(s))
		printf("Invalid frame size\n");
	else
	{
		printf("let's continue\n");
		for(i=0; i<strlen(s) && s[i]!='\n'; i++){
			printf("%c\n", s[i]);
		}
	}
	free(s);
	return 0;
}
