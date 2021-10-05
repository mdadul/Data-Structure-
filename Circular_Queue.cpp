#include <iostream>
#include <string>
#define nw "\n"

using namespace std;

#define n 100

int Queue[n+10];
int front = 0;
int rear = 0;

int menu(void)
{
	int choice;
	do
	{
		printf("\n1-QInsert\n2-QDelete\n0-Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 2)
			printf("\nWrong...Choice again...\n");
	} while (choice < 0 || choice > 2);
	return (choice);
}

void Qinsert()
{
	
	if ((front == 1 && rear == n) || (front == (rear + 1)))
	{
		cout << "\n\nOverflow\n";
		return;
	}
	
	int item;
	cout << "Enter a number : ";
	cin >> item;
	
	if (front == 0)
	{
		front = 1;
		rear = 1;
	}
	else if (rear == n)
	{
		rear = 1;
	}
	else
	{
		rear = rear + 1;
	}

	Queue[rear] = item;

	return;
}
void Qdelete()
{
	if (front == 0)
	{
		cout << "\n\nUnderflow\n";
		return;
	}
	int item = Queue[front];

	cout << "\nDelete Item : " << item << nw;

	if (front == rear)
	{
		front = 0;
		rear = 0;
	}
	else if (front == n)
	{
		front = 1;
	}
	else
	{
		front = front + 1;
	}
	return;
}
void display()
{
	if (front == 0)
	{
		cout<<"\nQueue is Empty";
		return;
	}
	cout<<"\nElements in Circular Queue are: ";
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout << Queue[i] << " ";
	}
	else
	{
		for (int i = front; i <= n; i++)
		{
			cout << Queue[i] << " ";
		}

		for (int i = 1; i <= rear; i++)
		{
			cout << Queue[i] << " ";
		}
	}
}
int main()
{
	int choice;

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			Qinsert();
			display();
			break;
		case 2:
			Qdelete();
			display();
			break;
		case 0:
			printf("End of operation\n");
			break;
		}
	} while (choice != 0);
	return 0;
}
