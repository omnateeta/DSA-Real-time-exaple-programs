//Devolp a program in c for the following stac application a evaluation of suffix expression with single digit operands & oprators:+,-,*,/,%,^ etc
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int i,top=-1;
int op1,op2,res,s[20];
char postfix[90],symb;

void push(int item)
{
	top=top+1;
	s[top]=item;
}
int pop()
{
	int item;
	item=s[top];
	top=top-1;
	return item;
}

void main()
{
	printf("Enter the valid postfix expression:");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		symb=postfix[i];
		if(isdigit(symb))
		{
			push(symb-'0');
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(symb)
			{
				case '+':push(op1+op2);
						break;
				case '-':push(op1-op2);
						break;
				case '*':push(op1*op2);
						break;
				case '/':push(op1/op2);
						break;
				case '%':push(op1%op2);
						break;
				case '$':
				case '^':push(pow(op1,op2));
						break;
				default:push(0);
							
			}
		}
	}
	res=pop();
	printf("\n Result = %d",res);
}
