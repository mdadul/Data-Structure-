#include<iostream>
#include<string>
#include<cstdlib>
#define nw "\n"
#define NULL 0
using namespace std;

struct Linked_list
{
	int num;
	struct Linked_list *next;
};
typedef Linked_list node;

int main()
{
	int n,i,item;
	node *start, *ptr,*loc;
	
	start = (node*) malloc(sizeof(node));
	
	ptr = start;
	
	printf("How many elements : ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		printf(" Input a number : ");
		scanf("%d",&ptr->num);
		
		if(i!=n)
		{
			ptr->next = (node*) malloc(sizeof(node));
			ptr = ptr->next;
		}
	}
	ptr->next = NULL;
	
	ptr = start;
	
	printf("Enter a number to search :");
	scanf("%d",&item);
	
	int cnt=1; 
	while(ptr!=NULL)
	{
		if(item == ptr->num)
		{
			break;
		}
		else{
		    ptr = ptr->next;
		}
		cnt++;
	}
	if(ptr!=NULL)
	{
		cout<<"\nItem found in position : "<<cnt<<"\nMemory Address : "<<ptr;
	}
	else{
		cout<<"\nItem not found\n";
	}
	return 0;
}
