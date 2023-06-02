//Program to implement circular queue

#include<stdio.h>
#define MAX 5
void insert(int Q[MAX],int *rear,int elem,int *count)
{
	if(*count==MAX)
		printf("Element cannot be inserted\n");
	else
	{
		(*rear)=((*rear)+1)%MAX;
		Q[*rear]=elem;
		(*count)++;
	}
}

void delete(int Q[MAX],int *front,int *count)
{
	if(*count == 0)
		printf("There are no elements in the queue\n");
	else
	{
		printf("The deleted element is %d\n",Q[*front]);
		(*front)=((*front)+1)%MAX;
		(*count)--;
	}
}

void display(int Q[MAX],int front,int count)
{
	if(count ==0)
		printf("No elements in the queue\n");
	else
	{
		printf("Displaying the elements of the queue\n");
		while(count!=0)
		{
			printf("%d\t",Q[front]);
			front=(front+1)%MAX;
			count--;
		}
		printf("\n");
	}
}

int main()
{
	int rear=MAX-1,front =0,count=0,elem,choice,Q[MAX];
	while(1)
	{
		printf("Enter\n1-Insert\n2-Delte\n3-Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted\n");
				 scanf("%d",&elem);
				 insert(Q,&rear,elem,&count);
				 break;
			case 2: delete(Q,&front,&count);
				 break;
			case 3: display(Q,front,count);
				 break;
			default: printf("Invalid choice\n");
				  return 0;
		}
	}
	return 0;
}