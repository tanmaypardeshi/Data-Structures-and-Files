#include "BinaryTree.h"
#define SIZE 50

void BinaryTree::BinaryTree()
{
	root = NULL;
}

int BinaryTree::isempty()
{
	if(root == NULL)
		return 1;
	return 0;
}

void BinaryTree::create(char postfix[])
{
	Node *stack[SIZE];
	int top = -1,i;

	top++;
	for(i=0;postfix[i]!='\0';i++)
	{
		Node *node = new Node();
		node->data = postfix[i];

		switch(postfix[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				stack[top++] = node;
				break;
			default:
				node->right = stack[--top];
				node->left = stack[--top];


		}
	}

}

