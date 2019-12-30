#include<iostream>
#include<string.h>
#include "Stack.h"
using namespace std;

int priority(char);
void prefix();
void postfix();
float prefixeval();
float postfixeval();
void strrev(char []);


int main()
{
	int choice;

	while(1)
	{
		cout<<"\nConversion and Evaluation of Expressions"<<endl;
		cout<<"1. Conversion of infix expression to prefix expression"<<endl;
		cout<<"2. Conversion of infix expression to postfix expression"<<endl;
		cout<<"3. Evaluation of prefix expression"<<endl;
		cout<<"4. Evaluation of postfix expression"<<endl;
		cout<<"5. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				prefix();
				break;
			case 2:
				postfix();
				break;
			case 3:
				//float=prefixeval();
				break;
			case 4:
				//float=postfixeval();
				break;
			case 5:
				return 0;
			default:
				cout<<"\nError in choice, try again"<<endl;
		}
	}
	return 0;
}

void prefix()
{
	char infix[20], prefix[20], ch;
	Stack s;
	int i, j = 0;
	cout<<"Enter the infix expression :- ";
	cin.ignore();
	cin.getline(infix,20);

	for (i=strlen(infix)-1;i>=0;i--)
	{
		switch (infix[i])
		{
			case ')':
				s.push(')');
				break;
			case '+':
			case '-':
			case '/':
			case '*':
			case '%':
			case '$':
			case '&&':
			case '||':
			case '!':
				while (!s.isempty() && priority(s.topelement()) > priority(infix[i]))
				{
					prefix[j] = s.pop();
					j++;
				}
				s.push(infix[i]);
				break;

			case '^':
				while (!s.isempty() && priority(s.topelement()) > priority(infix[i]))
				{
					prefix[j] = s.pop();
					j++;
				}
				s.push(infix[i]);
				break;
			case '(':
				ch = s.pop();
				while (ch != ')')
				{
					prefix[j] = ch;
					j++;
					ch = s.pop();
				}
				break;
			default:
				prefix[j] = infix[i];
				j++;
		}
	}
	while (!s.isempty())
	{
		prefix[j] = s.pop();
		j++;
	}
	prefix[j] = '\0';
	strrev(prefix);
	cout<<"Prefix expression is "<<prefix<<endl;
}


void postfix()
{
	char infix[20], postfix[20], ch;
	Stack s;
	int i, j = 0;
	cin.ignore();
	cout<<"Enter the infix expression :- ";
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
			case '&&':
			case '||':
			case '!':
				while (!s.isempty() && priority(s.topelement()) >= priority(infix[i]))
				{
					postfix[j] = s.pop();
					j++;
				}
				s.push(infix[i]);
				break;

			case '^':
				while (!s.isempty() && priority(s.topelement()) > priority(infix[i]))
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

	cout<<"Postfix expression is "<<postfix<<endl;
}

int priority(char ch)
{
	if (ch == '^' || ch == '$')
		return 6;
	if (ch == '/' || ch == '*' || ch == '%')
		return 5;
	if (ch == '+' || ch == '-')
		return 4;
	if(ch=='&&')
		return 3;
	if(ch=='||')
		return 2;
	if(ch=='!')
		return 1;
	return 0;
}

void strrev(char prefix[])
{
	Stack s;
	int i;
	for(i=0;i<strlen(prefix);i++)
		s.push(prefix[i]);
	for(i=0;i<strlen(prefix);i++)
		prefix[i]=s.pop();
	prefix[i]='\0';
}


float prefixeval(){return 0.0;}

float postfixeval(){return 0.0;}

