#include<iostream>
#include<string.h>
#include<math.h>
#include "Stack.h"
using namespace std;

int priority(char);
void prefix();
void postfix();
void prefixeval();
void postfixeval();
void strrev(char []);


int main()
{
	int choice,result;

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
				prefixeval();
				break;
			case 4:
				postfixeval();
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

void prefixeval()
{
	Stack s;
	char prefix[40];
	int i,j=0,op1,op2,vals[20];
	cin.ignore();
	cout<<"Enter the prefix expression:- ";
	cin.getline(prefix,40);

	for(i=0;prefix[i]!='\0';i++)
	{
		if(isalpha(prefix[i]))
		{
			cout<<"Enter value for operand "<<prefix[i]<<":- ";
			cin>>vals[j];
			j++;
		}
	}
	j--;
	for(i=strlen(prefix)-1;i>=0;i--)
	{
		if (isalpha(prefix[i]))
		{
			s.push(vals[j]);
			j--;
		}
		else
		{
			op1 = s.pop();
			op2 = s.pop();
			if (prefix[i] == '+')
				s.push(op1+op2);
			else if (prefix[i] == '-')
				s.push(op1-op2);
			else if (prefix[i] == '*')
				s.push(op1*op2);
			else if (prefix[i] == '/')
				s.push(op1/op2);
			else if (prefix[i] == '%')
				s.push(op1%op2);
			else
				s.push(pow(op1,op2));
		}
	}
	cout<<"Result of evaluating expression is "<<(int)s.pop()<<endl;
}

void postfixeval()
{
	Stack s;
	char postfix[40];
	int i,op1,op2,val;
	cin.ignore();
	cout<<"Enter the postfix expression:- ";
	cin.getline(postfix,40);

	for(i=0;postfix[i]!='\0';i++)
	{
		if(isalpha(postfix[i]))
		{
			cout<<"Enter value for operand "<<postfix[i]<<":- ";
			cin>>val;
			s.push(val);
		}
		else
		{
			op2 = s.pop();
			op1 = s.pop();
			if (postfix[i] == '+')
				s.push(op1+op2);
			else if (postfix[i] == '-')
				s.push(op1-op2);
			else if (postfix[i] == '*')
				s.push(op1*op2);
			else if (postfix[i] == '/')
				s.push(op1/op2);
			else if (postfix[i] == '%')
				s.push(op1%op2);
			else
				s.push(pow(op1,op2));
		}
	}
	cout<<"Result of evaluating expression is "<<(int)s.pop()<<endl;
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

