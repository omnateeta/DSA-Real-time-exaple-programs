//Solving tower of honoi problem with n disks..

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void tower(int n, char from_peg,char aux_peg,char to_peg);
int main()
{
	int n;
	printf("Enter the number of disks:\n");
	scanf("%d",&n);
	tower(n,'A','B','C');
	printf("Total number of moves= %0.0f\n",pow(2,n)-1);
	getch();
}

void tower(int n, char from_peg, char aux_peg,char to_peg)
{
	if(n==1)
	{
		printf("moves Disk %d from %c peg to %c peg\n",n,from_peg,to_peg);
		return;
	}
	tower(n-1,from_peg,to_peg,aux_peg);
	printf("Move disk %d from peg %c to %c peg\n",n,from_peg,to_peg);
	
	tower(n-1,aux_peg,from_peg,to_peg);
}
