#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *top,*top1,*temp;
void push(int);
void pop();
void display();

void main()
{
	int d,c,e;
	while(1)
	{
		printf("\n\n\nSTACK MENU");
		printf("\n1.Push.\n2.Pop.\n3.Display.\n4.Exit.");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
					 printf("Enter data:");
					 scanf("%d",&d);
					 push(d);
					 break;
			case 2:
					 pop();
					 break;
			case 3:
					 display();
					 break;
			case 4:
					 exit(0);
					 break;
			default:printf("Wrong Choice!"); 
		}
	}
}

void push(int d)
{
	if(top==NULL)
	{
		top=(struct node*)malloc(1*sizeof(struct node));
		top->next=NULL;
		top->data=d;
	}
	else
	{
		temp=(struct node*)malloc(1*sizeof(struct node));
		temp->next=top;
		temp->data=d;
		top=temp;
	}
	printf("Pushing of data is completed.");
}

void display()
{
	top1=top;
	if(top1==NULL)
	{
		printf("Stack is Empty!");
		return;
	}
	printf("Data in Stack:\n");
	while(top1!=NULL)
	{
		printf("%d\n",top1->data);
		top1=top1->next;
	}
}

void pop()
{
	top1=top;
	if(top1==NULL)
	{
		printf("Stack is Empty!Unable to pop.");
	}
	else
	{
		top=top1->next;
		printf("Popped value=%d",top1->data);
		free(top1);
	}
}
