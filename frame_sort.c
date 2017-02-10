#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsz 21

int main()
{
	int fsz,i,j,k=0,z=0,p,q,tmp,ln,h,cm;
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
	printf("The entered string is %s",s);
	printf("Enter frame size:");
	scanf("%d",&fsz);
	cm = strlen(s)-1;
	ln = (cm)/fsz;
	h = (cm)%fsz;
	//printf("String length is = %d and h value is %d= ",strlen(s)-1,h);
	if(h!=0)
		ln +=1;

	struct frame fr[ln];
	if(fsz>=cm || fsz<=0)
		printf("Invalid frame size\n");
	else
	{
		printf("let's continue\n");
		/*for(i=0; i<strlen(s) && s[i]!='\n'; i++){
			printf("%c\n", s[i]);
		}*/
		printf("Before sorting\n");
		printf("Frame no.\tData\n");
		for(j=0;j<ln;j++){
			fr[j].id = j;
			//printf("here %d\n",fr[j].id);
			k += fsz;
			for(i=0; i<fsz &&s[z]!='\n'&& z<k;i++, z++){
				fr[j].st[i] = s[z];
			}
			printf("%d\t\t%s\n",fr[j].id,fr[j].st);
		}
		printf("After shuffling\n");
		for(i = 0;i<ln;i++){
			p = rand()%(ln);
			q = rand()%(ln);
			tmp = fr[p].id;
			fr[p].id = fr[q].id;
			fr[q].id = tmp;
		}
		for(i=0; i<ln; i++)
			printf("%d \t %s\n",fr[i].id,fr[i].st);
		//sorting
		for(i=0; i<ln;i++){
			for(j=0; j<ln-i-1;j++){
				if(fr[j].id>fr[j+1].id){
					tmp = fr[j].id;
					fr[j].id = fr[j+1].id;
					fr[j+1].id = tmp;
				}
			}
		}
		printf("After sorting \n");
		for(i=0; i<ln; i++)
			printf("%d \t %s\n",fr[i].id,fr[i].st);

	}
	free(s);
	return 0;
}
