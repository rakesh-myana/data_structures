#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size],top=-1;
void push();
void pop();
void display();
void main()
{
	int choice=0;
	while(choice!=4)
	{
		printf("\n\n\n______STACK MENU______\n");
		printf("1.PUSH.\n2.POP.\n3.Display.\n4.Exit.\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:printf("WRONG CHOICE!");
		}
	}
}

void push()
{
	if(top==size-1)
		printf("OVER FLOW!");
	else
	{ 
		int value;
		printf("Enter value to be inserted:");
		scanf("%d",&value);
		top++;
		stack[top]=value;
		printf("Insertion Successful.");
	}
}

void pop()
{
	if(top==-1)
		printf("UNDERFLOW!Stack is EMPTY!");
	else
	{
		printf("Deleted:%d",stack[top]);
		top--;
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack is EMPTY!");
	}
	else
	{
		int i;
		printf("Stack elements:\n");
		for(i=top ; i>=0 ; i--)
			printf("%d\n",stack[i]);
	}
}
