#include <iostream>
#include <string>
#include <fstream>
#define nw "\n"

using namespace std;

int n;			// array size
int arr[10000]; // store the value

// sorting function
void sort()
{
	for (int k = 1; k <= n - 1; k++)
	{
		int ptr = 1;
		while (ptr <= n - k)
		{
			if (arr[ptr] > arr[ptr + 1])
			{
				int temp = arr[ptr];
				arr[ptr] = arr[ptr + 1];
				arr[ptr + 1] = temp;
			}
			ptr += 1;
		}
	}
}

// Insert element in an array
void Insert()
{
	cout << "\nEnter the number :  ";
	int j = n;
	int item;
	cin >> item;
	while (arr[j] > item)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = item;
	n = n + 1;

	cout << "\v\tSuccessfully Insert\v";
}

int lower_bound(int item)
{
	int Beg = 0;	 
	int End = n + 1; 

	while (Beg + 1 < End)
	{
		int Mid = (Beg + End) / 2;
		if (arr[Mid] >= item)
		{
			End = Mid;
		}
		else
		{
			Beg = Mid;
		}
	}

	return End;
}

// search function
void Search()
{
	cout << "\nEnter the number : ";
	int item;
	cin >> item;

	int pos = lower_bound(item);
	if (pos > n || pos < 0)
	{
		cout << "\nItem not found!\n";
	}
	else
	{
		cout << "\n\nItem found in position : " << pos << nw;
	}
}

// array's element delete function
void Delete()
{
	cout << "\nEnter the number : ";
	int item;
	cin >> item;

	int pos = lower_bound(item);
	if (pos > n || pos < 0)
	{
		cout << "\n\n\tItem not found!";
	}
	else
	{
		for (int j = pos; j <= n - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		n = n - 1;

		//cout<<"Deleted Item: "<<item<<endl;
		cout << "\v\tSuccessfully Deleted\n";
	}
}

// array display function
void Display()
{
	cout << "\n\n";
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << nw;
}

// array creator function
void Create()
{
	cout << "\n\nEnter the size of array : ";
	cin >> n;

	cout << "\vThis array genarate with random value.\nAre you want to set the range of value? [Y/N] :  ";
	char ch;
	cin >> ch;
	int mod_value;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "Enter the range of value : ";
		cin >> mod_value;
		mod_value += 1;
	}
	else
	{
		cout << "\n\n\tDefault  Range : 100\n";
		mod_value = 101;
	}

	ofstream out("Array.txt"); // write file
	if (!out)
	{
		cout << "◇◇◇Can’t open file◇◇◇\n";
		exit(1);
	}
	for (int i = 1; i <= n; i++)
	{
		out << rand() % mod_value << endl;
	}
	out.close();

	ifstream in("Array.txt"); // read file
	if (!in)
	{
		cout << "◇◇◇Can't open file◇◇◇\n";
		exit(1);
	}
	int x, i = 1;
	while (in >> x)
	{
		arr[i] = x;
		i++;
	}
	cout << "\n\n\t\t■■■Array created successfully■■■\n";

	cout << "\n\n\tBefore Sort\n";
	Display();
	sort(); // to sort the array,
	cout << "\n\n\tAfter Sort\n";
	Display(); // display array all element

	in.close();
}

int menu(void)
{
	int choice;
	do
	{
		printf("\n1-Insert\n2-Delete\n3-Search\n4-Display\n0-Exit\n");
		printf("\n\n•••••Enter your choice••••••• ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 5)
			printf("\n■■■Wrong...Choice again...■■■\n");
	} while (choice < 0 || choice > 5);
	return (choice);
}

void OptionMenu()
{
	int choice;

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Search();
			break;
		case 4:
			Display();
			break;
		case 0:
			printf("\n♧♧♧End of operation♧♧♧\n");
			break;
		}
	} while (choice != 0);
}
int main()
{
	cout << "\t==================================\n";
	cout << "\t  Data Structure CRUD Project     \n";
	cout << "\t==================================\n";
	cout << "\n●Do You Want To Create An Array? [Y/N] ● ";
	char ch;
	cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		Create(); // array create function
		OptionMenu();
	}
	else
	{
		cout << "\n\n☆☆☆Sorry! If you don't want to create an array , we will not go to the next steps. Change your decision☆☆☆ " << nw;
	}

	return 0;
}
