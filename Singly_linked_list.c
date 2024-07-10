#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
int main()
{
	int choice=0;
	while (choice!=9)
	{
		printf("\n\n\n****SINGLE LINKED LIST MAIN MENU****\n");
		printf("Choose an option from following list.\n");
		printf("--------------------------------------\n");
		printf("1.Insert at begining.\n2.Insert at last.\n3.Insert at any random location.\n4.Delete from begining.\n5.Delete from last.\n6.Delete at specific loaction.\n7.Search for an element.\n8.Show.\n9.EXIT.");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:begin_insert();
					break;
			case 2:last_insert();
					break;
			case 3:random_insert();
					break;
			case 4:begin_delete();
					break;
			case 5:last_delete();
					break;
			case 6:random_delete();
					break;
			case 7:search();
					break;
			case 8:display();
					break;
			case 9:exit(0);
					break;
			default:printf("Please enter a valid choice!");
		}
	}
}

void begin_insert()
{
	struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	
	if(ptr==NULL)
	{
		printf("OVER FLOW!");
	}
	else
	{
		printf("Enter value:");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("Node Inserted.");
	}
}

void last_insert()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	if(ptr==NULL)
	{
		printf("OVER FLOW.");
	}
	else
	{
		printf("Enter value:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("Node inserted.");
		}
		else
		{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;		
		}
		temp->next=ptr;
		ptr->next=NULL;
		printf("Node inserted.");
		}
	}
}

void random_insert()
{
	int i,loc,item;
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node *));
	if(ptr==NULL)
	{
		printf("OVER FLOW!");
	}
	else
	{
	
		printf("Enter the location after which you want to insert:");
		scanf("%d",&loc);
		temp=head;
		for(i=1 ; i<loc ; i++)
		{	
			if(temp==NULL)
			{
				printf("Can't Insert.");
				return;
			}
			temp=temp->next;
		}
		printf("Enter value:");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=temp->next;
		temp->next=ptr;
		printf("Node inserted.");
	}
}

void begin_delete()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is empty! Can't Delete.");
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("Node deleted from the begining.\n");
	}
}

void last_delete()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is empty! Can't Delete.");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("Last node of the list is deleted.\n");
	}
	else
	{
		ptr=head;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		free(ptr->next);
		ptr->next=NULL;
		printf("Last node of the list is deleted.\n");
	}
}
void random_delete()
{  
	struct node *ptr,*ptr1;
	int loc,i;
	ptr=head;
	if(head==NULL)
	{
		printf("List is empty! Can't Delete.");
		return;
	}
	printf("Enter the location of the node after which you want to perform deletion:");
	scanf("%d",&loc);
	for(i=0 ; i<loc ; i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("Can't delete.");
			return;
		}
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("Deleted node at location %d",loc+1);
}

void search()
{
	struct node *ptr;
	int item,i=0,flag=0;
	ptr=head;
	if(ptr==NULL)
	{
		printf("List is Empty!");
	}
	else
	{
		printf("Enter element which you want to search:");
		scanf("%d",&item);
		
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("Element found at location %d. \n",i+1);
				flag=1;
			}
		ptr=ptr->next;
		i++;
		}	
		if(flag==0)
		{
				printf("Element not found.\n");
		}
	}
}

void display()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Nothing to display.List is Empty!");
	}
	else
	{
		printf("Data in Linked List:\n");
		while(ptr->next!=NULL)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->next;
		}
			printf("%d",ptr->data);
	}
}

