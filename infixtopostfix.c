#include <stdio.h>
#include <stdlib.h>

void evaluate();
void push(char);
char pop();
int prec(char symb);
int val();

char infix[30], postfix[30], s[30]; // Changed to char arrays
int top = -1;

int main() {
	int res;
	nxt:  
    printf("\n Enter a valid infix expression:\t");
    scanf("%s", infix); // Read the infix expression as a string
    res=val();
 	if(res==1)
 		evaluate();
 	else
	 {
	 	printf("Invalid expression\n");
	 	goto nxt;
		 }	
    printf("Entered infix expression is: %s\n", infix);
    printf("And the corresponding postfix expression is: %s\n", postfix);

    return 0; // Exit properly
}

int val()
{
	int opnd=0,oper=0,i=0;
	while(infix[i]!='\0')
	{
		if(isalpha(infix[i]))
			opnd++;
		else  if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'
		||infix[i]=='^'||infix[i]=='^')
			oper++;
			i++;
	}
	if(opnd>=oper)
		return 1;
	else
	 	return -1;	
}

// Evaluate infix to postfix
void evaluate() {
    int i = 0, j = 0;
    char symb, temp;

    push('#'); // Sentinel value for precedence

    for(i=0;infix[i] != '\0';i++) {
        symb = infix[i];
        switch (symb) {
            case '(':
                push(symb);
                break;

            case ')':
                temp = pop();
                while (temp != '(') {
                    postfix[j] = temp;
                    j++;
                    temp = pop();
                }
                break;

            case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%': 
			case '^':
                while (prec(s[top]) >= prec(symb)) {
                    temp = pop();
                    postfix[j] = temp;
                    j++;
                }
                push(symb);
                break;

            default: // For operands
                postfix[j] = symb;
                j++;
        }
        
    }

    // Pop remaining operators in the stack
    while (top > 0) {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Push an element onto the stack
void push(char item) {
    if (top >= 29) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    top = top + 1;
    s[top] = item;
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    char item = s[top];
    top = top - 1;
    return item;
}

// Get precedence of an operator
int prec(char symb) {
	int p;
    switch (symb) {
        case '#': p=-1;
					break; // Sentinel value
        case '(':
        case ')': p=0;
        			break;
        case '+':
        case '-': p=1;
        			break;
        case '*':
        case '/':
        case '%': 
        case '^': p=2;
        			break;
         // Invalid operator
    }
    return p;
}

