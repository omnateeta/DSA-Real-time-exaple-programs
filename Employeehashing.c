#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int key[20],n,m;
int *ht,index;
int count=0;

void insert(int key)
{
	index=key%m;
	while(ht[index]!=-1)
	{
		index=(index+1)%m;
	}
	ht[index]=key;
	count++;
}

void display()
{
	int i;
	if(count==0)
	{
		printf("Hash table is empty\n");
		return;
	}
	printf("Hash table contents are:\n");
	for(i=0;i<m;i++)
		printf("T[%d]-->%d\n",i,ht[i]);
}

int main()
{
	int i;
	printf("Enter the number of employee records(N)):");
	scanf("%d",&n);
	printf("Enter the two digit memory locations(M):\n");
	scanf("%d",&m);
	ht=(int*)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
	   ht[i]=-1;
		
	printf("Enter the four digit key value(K) for N employee records:");
	for(i=0;i<n;i++)
		scanf("%d",&key[i]);
		
	for(i=0;i<n;i++)
	{
		if(count==m)
		{
			printf("\n~~~Hash table is full.cannot insert the record %d key~~~\n");
			break;
		}
	insert(key[i]);
	}
	display();
}









