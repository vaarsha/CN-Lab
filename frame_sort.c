#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsz 21

int main()
{
	int fsz,i,j,k=0,z=0;
	struct frame {
		int id;
		char st[20];
	};
	//Allocate memory and check it's availability.
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
	struct frame fr[fsz];
	if(fsz>strlen(s))
		printf("Invalid frame size\n");
	else
	{
		printf("let's continue\n");
		for(i=0; i<strlen(s) && s[i]!='\n'; i++){
			printf("%c\n", s[i]);
		}
		for(j=0;j<=fsz;j++){
			fr[j].id = j;
			printf("here %d\n",fr[j].id);
			k += fsz;
			for(i=0; i<fsz &&s[z]!='\n'&& z<k;i++, z++){
				fr[j].st[i] = s[z];
			}
			printf("string is %s\n",fr[j].st);
		}

	}
	free(s);
	return 0;
}
