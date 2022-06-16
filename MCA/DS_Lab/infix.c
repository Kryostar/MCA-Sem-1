#include <stdio.h>
#include <ctype.h>

#define SIZE 50            

char stack[SIZE];
int top = -1;

push(char ele)
{
	stack[++top] = ele;
}

char pop()
{
	return(stack[top--]);
}

int precedence(char symbol)
{
	if (symbol == '^')
	{
		return(3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if (symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void main()
{
	char infix[50], postfix[50], ch, ele;
	int i = 0, k = 0;
	system("cls");
	printf("Enter Infix Expression : ");
	scanf("%s", infix);
	push('$');
	while ((ch = infix[i++]) != '\0')
	{
		if (ch == '(')
			push(ch);
		if (ch == ')')
		{
			while (stack[top] != '(')
				postfix[k++] = pop();
			ele = pop();
		}
		else
		{
			while (precedence(stack[top]) >= precedence(ch))
				postfix[k++] = pop();
			push(ch);
		}
		if (isalnum(ch))
			postfix[k++] = ch;
	}
	while (stack[top] != '$')
		postfix[k++] = pop();
	postfix[k] = '\0';
	printf("\nPostfix Expression =  %s\n", postfix);
}