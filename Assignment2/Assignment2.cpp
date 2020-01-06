
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

void init_q()
{
	front = rear = -1;
}

void addq(struct queue q[],int no)
{
	rear++;
	q[rear].data = no;
	q[rear].flag = 0;  /* imp  */
	/* check whether if it is 1st element. If so, increment front also */
	if (front == -1)
		front = 0;
}

void displayq(struct queue q[ ])
{
	int i;
	for (i=front;i<=rear;i++)
	{
		if (q[i].flag == 0)
			printf("%d ",q[i].data);
	}
}

int delq(struct queue q[])
{
	int i, max, pos;
	/* 1st find the undeleted element */
	for (i=0;i<=rear;i++)
	{
		if (q[i].flag == 0)
		{
			max = q[i].data;
			pos = i;
			break;
		}
	}
	/* search begins for max undeleted element */
	for (i=pos+1;i<=rear;i++)
	{
		if (q[i].flag == 0 && max < q[i].data)
		{
			max = q[i].data;
			pos = i;
			/* no break bcoz the search continues */
		}
	}
	q[pos].flag = 1;  /* logical deletion of element */
	/* just check whether the element deleted now is last element or
	   not. If so, queue is empty */
	pos = -1;
	for (i=front;i<=rear;i++)
	{
		if (q[i].flag == 0)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
		front = rear = -1;  /* reset the queue to accept a fresh
					batch of elements */
	return max;
}

int isqempty()
{
	if (front == -1)
		return 1;

	return 0;
}

int isqfull()
{
	if (rear == SIZE-1)
		return 1;

	return 0;
}
















