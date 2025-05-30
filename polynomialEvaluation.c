/*Develop a program in c for te following operation singly circular list with header nodes. (A)Represent and evaluate a polynomial p(x,y,z)
=6xy-4yz5+3x3yx+2xy5z-2xyz3. (B)Find the sum of two poly1(x,y,z) poly2(x,y,z) and and store the result in polysym(x,y,z) support the program with
appropriate functions for each of the above operations.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define COMPARE(x,y) ((x==y)?0:(x>y)? 1:-1)
struct node{
	int coef;
	int xexp,yexp,zexp;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Running out of memory\n");
		return NULL;
	}
	return x;
}
NODE attach(int coef,int xexp,int yexp,int zexp, NODE head)
{
	NODE temp,cur;
	temp = getnode();
	temp->coef=coef;
	temp->xexp=xexp;
	temp->yexp=yexp;
	temp->zexp=zexp;
	cur=head->link;
	while(cur->link!=head)
	{
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=head;
	return head;
}

NODE read_poly(NODE head)
{
	int i,j,coef,xexp,yexp,zexp,n;
	printf("\n Enter the no of terms in the polymial:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n\tEnter the %d term:",i);
		printf("\n\tcoef =");
		scanf("%d",&coef);
		printf("\tEnter pow(X), Pow(Y) and pow(Z):");
		scanf("%d%d%d",&xexp,&yexp,&zexp);
		head = attach(coef,xexp,yexp,zexp,head);
	}
	return head;
}
void display(NODE head)
{
	NODE temp;
	if(head->link==head)
	{
		printf("polynomial does not exist.");
		return ;
	}
	temp=head->link;
	while(temp!=head)
	{
		printf("%dx^%dy^%dz^",temp->coef,temp->xexp,temp->yexp,temp->zexp);
		temp=temp->link;
		if(temp!=head)
		printf("+");
	}
}
int poly_evaluate(NODE head)
{
	int x,y,z, sum=0;
	NODE poly;
	printf("\nEnter the value of x,y, and z:");
	scanf("%d%d%d",&x,&y,&z);
	poly=head->link;
	while(poly!=head)
	{
		sum+=poly->coef * pow(x,poly->xexp) * pow(y,poly->yexp) * pow(z,poly->zexp);
		poly=poly->link;
	}
	return sum;
}

void main()
{
	NODE head,head1,head2,head3;
	int res;
	head = getnode();
	head1 = getnode();
	head3 = getnode();
	head->link=head;
	head1->link=head1;
	head3->link=head3;
	printf("\n1.Reprasent and Evaluate a polynomial p(x,y,z)");
	printf("\n~~~Polynimal evaluation p(x,y,z)~~~\n");
	head = read_poly(head);
	printf("Reprasentarion of polynomial for evaluation:\n");
	display(head);
	res=poly_evaluate(head);
	printf("\n Result of polynomial evaluation is :%d\n",res);
	getch();	
}
