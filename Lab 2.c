/*Q-2:Develop a program on c for the following operation on strings.
a.Read a main String(STR),a pattern string(PAT) and a Replacing String(Rep)
b.Perform pattern matching operation Find and replace all occurancecess of PAt 
  in SAT with REP if PAT exist in STR.Support the program with functions for 
  each of the above operations Don't use Built-in funtions*/
#include<stdio.h>
#include<stdlib.h>
char str[50],pat[20],rep[20],ans[50];
int c=0,m=0,i=0,j=0,k,flag=0;
void stringmatch()
{
	while(str[c]!='\0')
	{
		if(str[m]==pat[i])
		{
			i++;
			m++;
			if(pat[i]=='\0')
			{
				flag=1;
				for(k=0;rep[k]!='\0';k++,j++)
				{
					ans[j]=rep[k];
				}
				i=0;
				c=m;
			}
		}
		else{
			ans[j]=str[c];
			j++;
			c++;
			m=c;
			i=0;
		}
	}
	ans[j]='\0';
}

void main()
{
	printf("\nEnter the main string:");
	gets(str);
	printf("\nEnter the past string:");
	gets(pat);
	printf("\nEnter the replace string:");
	gets(rep);
	stringmatch();
	if(flag==1)
	printf("\nResultant string is %s ",ans);
	else
	printf("\nPatter string is not found");
}