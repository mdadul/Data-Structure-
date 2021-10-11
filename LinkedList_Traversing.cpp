#include<stdio.h>
#include<stdlib.h>
#define nw "\n"
#define NULL 0

struct Linked_list
{
	int num;
	struct Linked_list *next;
};
typedef Linked_list node;

int main()
{
	int n,i,item;
	node *start, *ptr;
	
	start = (node*) malloc(sizeof(node));
	
	ptr = start;
	
	printf("How many elements : ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		printf("Input a number : ");
		scanf("%d",&ptr->num);
		
		if(i!=n)
		{
			ptr->next = (node*) malloc(sizeof(node));
			ptr = ptr->next;
		}
	}
	ptr->next = NULL;
	
	printf("Elements in the linked list are : \n");
	ptr = start;
	
	while(ptr!=NULL)
	{
		printf("%d ",ptr->num);
		ptr = ptr->next;
	}
	return 0;
}
