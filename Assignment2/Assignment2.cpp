/* An eg of DESC Priority Queue */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct queue
{
	int data;
	int flag;
};

int front, rear;   /* global decln */

/* fn decls */
void init_q();
void addq(struct queue [],int);
int delq(struct queue []);
void displayq(struct queue []);
int isqempty();
int isqfull();

void main()
{
	struct queue q[SIZE];
	int choice, no;
	init_q();
	while (1)
	{
		clrscr();
		printf("Primitive Operations on Priority Queue\n\n");
		printf("1. Add to Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull())
					printf("Priority Queue is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addq(q,no);
				}
				break;

			case 2:
				if (isqempty())
					printf("Priority Queue is Empty");
				else
					printf("Element deleted is %d",delq(q));

				break;

			case 3:
				if (isqempty())
					printf("Priority Queue is Empty");
				else
					displayq(q);

				break;

			case 4:
				exit();

			default:
				printf("Error in choice. Try again");
		}
		getch();
	}
}
