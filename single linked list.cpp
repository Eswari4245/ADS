#include<stdio.h>
#include<stdlib.h>
struct node*insertatbegin(struct node*head);
struct node*insertatend(struct node*head);
struct node*insert_after_node(struct node*head);
void display(struct node*head);
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL,*temp,*newnode;
int main()
{
	printf("enter -1 to exit!!!\n");
	int val;
	while(1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%i",&val);
		if(val==-1)
		break;
		newnode->data=val;
		newnode->next=NULL;
		if(head==NULL)
		head=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	printf("linked list is created successfully\n");
	printf("\n created list is:\n");
	display(head);
	head=insertatbegin(head);
	printf("\n list after insertion at beginning:");
	display(head);
	head=insertatend(head);
	printf("\n list after at end");
	display(head);
	head=insert_after_node(head);
	printf("\nlist after insertion after given node:\n");
	display(head);
}
struct node*insertatbegin(struct node*head)
{
	printf("\n enter data to insert at beginning:");
	newnode=(struct node*)malloc(sizeof(struct node));
	scanf("%i",&newnode->data);
	newnode->next=head;
	head=newnode;
	return head;
}
struct node*insertatend(struct node*head)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter value to insert at end:");
	scanf("%i",&newnode->data);
	temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	newnode->next=NULL;
	temp->next=newnode;
	return head;
}
struct node*insert_after_node(struct node*head)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data to insert:");
	scanf("%i",&newnode->data);
	int val;
	printf("\n enter value of the node to insert after it");
	scanf("%i",&val);
	temp=head;
	while(temp->data!=val)
	temp=temp->next;
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
void display(struct node*head)
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%i->",temp->data);
		temp=temp->next;
	}
}
	
	
	



