//This page is only for practice the dsa programs its not has specific demonstartation

#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int s[MAX];
int top=-1;

void push(int item);
int pop();
void display();

void push(int item)
{
	if(top==MAX-1)
	{
		printf("\nStack is overflow\n");
	}
	else
	{
		top =top+1;
		s[top]=item;
	}
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("\n Stack if underflow!..");
	}
	else
	{
		item=s[top];
		top=top-1;
		printf("\npoped :%d",item);
		return item;
	}

}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nStack is empty!..");
	}
	else{
		printf("\nStack contents are:");
		for(i=top;i>=0;i--)
		{
			printf("\n|%d|",s[i]);
		}
		}	
}

int main()
{
	int ch,item;
	while(1)
	{
		printf("\nMENU");
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter element to be pushed:");
					scanf("%d",&item);
					push(item);
					break;
			case 2:pop();
					break;
			case 3:display();
					break;
			case 4:exit(0);
					break;
			default:printf("\n please enter valid choice.");								
		}
	}
}
