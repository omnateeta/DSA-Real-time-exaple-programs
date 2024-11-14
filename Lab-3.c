#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 3


int s[MAX];
int top=-1;

void push(int item);
int pop();
void palindrome();
void display();

void main()
{
	int choice,item;
	while(1);
	{
	printf("\n\n\n~~~~MENU~~~~");
	printf("\n=>1.push an element from to stack and overflow demo");
	printf("\n=>2.pop an element from stack and underflow demo");
	printf("\n=>3.Palindrom demo");
	printf("\n=>4.Display");
	printf("\n=>5.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:printf("\nEnter an element to be pushed:");
	       	scanf("%d",&item);
		    push(item);
			break;
		
		case 2:item=pop();
			    if(item!=-1)
				printf("\nElement popped is %d",item);
				break;
		
		case 3:palidrome();
				break;
		
		case 4:exit(1);
			printf("\nPlease enter valid choice.");
			break;
		}
	}
}

void push(int item)
{
	if(top==MAX-1)
	{
		printf("\n~~Stack overflow~~");
		return;
	}
	top=top+1;
	s[top]=item;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("\n~~ Stack underflow~~");
		return item;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n ~~ Stack is empty ~~");
		return;
	}
	printf("\nStack element are:\n");
	for(i=top;i>=0;i--)
	printf("|%d|\n",s[i]);
}
void palindrome()
{
	int flag=1,i;
	printf("Stack content are :\n");
	for(i=top;i>=0;i--)
	printf("|%d|\n",s[i]);
	
	printf("\nReverse of stack content are:\n");
	for(i=0;i<=top;i++)
	printf("|%d|\n",s[i]);
	
	for(i=0;i<=top;i++)
	{
		if(s[i]!=s[top-i])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nIt is palindrome number");
	}
	else
	{
		printf("\nIt is not a palindrom number");
	}
}
