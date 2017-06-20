
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *lptr;
	int key;
	struct node *next;
};
void push(struct node *head, int k,struct node *top);
int pop(struct node *head);
int testempty(struct node*);
int testfull(struct node*,struct node*);
void Free(struct node *head);

/* This is a stack program to implement by using doubly linked list.
*lptr is a variable to store previous node's address.
*next is a variable to store next node's address
If data is empty, you can't delete data anymore and print error message.
And if data is full(ex : memory allocation fail because of no memory space),
You can't store data anymore and print error message.
*/

void main()
{
	struct node* top=(struct node*)malloc(sizeof(struct node));
	struct node* head=(struct node*)malloc(sizeof(struct node));
	struct node* p=(struct node*)malloc(sizeof(struct node));
	int k,n=0;
	head->next=NULL;
	while(1)
	{
		printf("Push(1) or Pop(2) or Show(3) or Exit(4)\n");
		if(testfull(top,head)==1)
			printf("You can insert the data.\n");
		else if(testfull(top,head)==-1)
			printf("Error : Full. You can't insert data.");
		if(testempty(head)==-1)
			printf("You can't delete data.\n");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			scanf("%d",&k);
			push(head,k,top);
			break;

		case 2:
			if(testempty(head)==1)
				pop(head);
			else if(testempty(head)==-1)
				printf("Error -> This queue is empty.So you can't delete data.\n");
			break;

		case 3:
			p=head->next;
			while(p)
			{
				printf("%d ",p->key);

				p=p->next;
			}
			printf("\n");
			break;

		case 4:
			exit(1);
			break;

		default:
			printf("You enter wrong input. Please enter agian.\n");
			scanf("%d",&n);
			break;
		}
	}
	Free(head);
}

/* Function to insert data.
Function type is void.
When you insert data, top goes continuely next step.
*/

void push(struct node *head, int k,struct node *top)
{
	struct node *newnode,*prev=head;
	struct node *p=top->lptr;
	top=head->next;
	while(top)
	{
		prev=top;
		top=top->next;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->key=k;
	prev->next=newnode;
	newnode->lptr=prev;
	newnode->next=top;
	p=newnode;
}

/* Function to delete last node.
Top connects left node (using *lptr). 
And top deletes. The left node is top.
*/

int pop(struct node *head)
{
	struct node *n=head->next,*p=head;
	struct node *tmp;
	while(n)
	{
		p=n;
		n=n->next;
	}
	tmp=p;
	p=p->lptr;
	p->next=NULL;
	free(tmp);

}
/*Function to check empty or not.
If next node isn't exist or can't link some node, return -1 (error message).
Sentence that 'Head->next is no data' means that this stack is empty. 
*/
int testempty(struct node* head)
{
	if(!head->next)
		return -1;
	else
		return 1;
}

/*Function to check full or not.
If you use all memory, return -1(not memory allocation anymore)
When using all memory space in computer, display error message
*/

int testfull(struct node* top,struct node * head)
{
	if(top==NULL)
	{
		return -1;
	}
	else
		return 1;
}

/*Function that free memory space when you do not need it any more.*/

void Free(struct node *head)
{
	struct node *p=head,*prev=NULL;
	while(p)
	{
		prev=p;
		p=p->next;
		free(prev);
	}
}