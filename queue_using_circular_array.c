#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert();
void delete();
void display();
int queue[max];
int rear=-1;
int front=-1;
int main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("\n\n\n______QUEUE MENU_______");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display all elements.\n4.Exit.\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}

void insert()
{

    if(rear==-1 && front==-1)
    {
        rear=0;
        front=0;
        printf("Enter the element:");
        scanf("%d",&queue[rear]);
        printf("Enqueued.");
    }

    else if((rear+1)%max==front)
    {
        printf("OVER FLOW!");
    }
    else
    {
        rear=(rear+1)%max;
        printf("Enter the element:");
        scanf("%d",&queue[rear]);
        printf("Enqueued.");
    }

}



void delete()
{

    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow!\n");

    }
    else if(front==rear)
    {
        printf("%d is deleted.",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("%d deleted from queue.\n",queue[front]);
        front=(front+1)%max;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty!");
    }
    else
    {
        printf("Elements in queue:");

        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%max;
          
        }
        printf("%d",queue[rear]);
        
    }
}













