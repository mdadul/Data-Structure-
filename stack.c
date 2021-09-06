#include<stdio.h>
#define SIZE 5

int stack[SIZE+1],top=0;


int menu(void)
{
    int choice;
    do
    {
        printf("\n1-push\n2-pop\n0-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice<0||choice>2)
            printf("\nWrong...Choice again...\n");
    }
    while(choice<0||choice>2);
    return (choice);
}

void push()
{
    if(top==SIZE)
    {
    	printf("Overflow\n ");
    	return ;
    }
    top = top+1;
    int item;
    printf("Enter Item : ");
    scanf("%d",&item);
    stack[top] = item;
    
}
void pop()
{
    if(top==0)
    {
    	printf("Underflow\n");
    	return;
    }
    int item = stack[top];
    printf("Deleted item %d\n", item);
    top= top-1;
    
}

void display()
{
    for(int i=1; i<=top; i++)
    {
    	printf("%d ",stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 0:
            printf("End of operation\n");
            break;
        }
    }
    while(choice!=0);
    return 0;
}
