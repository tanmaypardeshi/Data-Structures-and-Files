#include<iostream>
#include "Stack.h"
using namespace std;

int priority(char);

int main()
{
	char infix[20], postfix[20], ch;
	Stack s;
	int i, j = 0;
	printf("Enter the infix expression :- ");
	cin.getline(infix,20);

	for (i=0; infix[i] != '\0'; i++)
	{
		switch (infix[i])
		{
			case '(':
				s.push('(');
				break;
			case '+':
			case '-':
			case '/':
			case '*':
			case '%':
			case '$':
				while (!s.isempty() && priority(s.topelement()) >= priority(infix[i]))
				{
					postfix[j] = s.pop();
					j++;
			   	}
		   		s.push(infix[i]);
			   	break;

			case ')':
				ch = s.pop();
				while (ch != '(')
				{
					postfix[j] = ch;
					j++;
					ch = s.pop();
				}
				break;

			default:
				postfix[j] = infix[i];
				j++;
		}
	}
	while (!s.isempty())
	{
		postfix[j] = s.pop();
		j++;
	}
	postfix[j] = '\0';

	cout<<"Postfix expression is "<<postfix;
	return 0;
}

int priority(char ch)
{
	if (ch == '^' || ch == '$')
		return 3;
	if (ch == '/' || ch == '*' || ch == '%')
		return 2;
	if (ch == '+' || ch == '-')
		return 1;
	return 0;
}
