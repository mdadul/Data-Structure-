#include <iostream>
#include <string>

using namespace std;

// COVID-19 Patient Management System using linkedlist

struct patient
{
	int Id;
	string patientName;
	string patientAddress;
	string lastTestReportDate;
	string mobile;
	string bloodGroup;

	patient *next;
};
typedef patient Covid;

Covid *first, *ptr;
int totalPatient = 0;

void addRecord()
{
	if (totalPatient == 0)
	{
		first = (Covid *)malloc(sizeof(Covid));
		ptr = first;
	}
	else
	{
		ptr->next = (Covid *)malloc(sizeof(Covid));
		ptr = ptr->next;
	}
	cout << "\nEnter Patient Id : ";
	cin >> ptr->Id;
	cout << "Enter Patient Name : ";
	cin >> ptr->patientName;
	cout << "Enter Patient address : ";
	cin >> ptr->patientAddress;
	cout << "Enter covid-19 last test report date : ";
	cin >> ptr->lastTestReportDate;
	cout << "Enter mobile no : ";
	cin >> ptr->mobile;
	cout << "Enter blood group : ";
	cin >> ptr->bloodGroup;

	cout<<"\n\n\tSuccessfully Added \n\n";
	totalPatient++;
}

void Display()
{
	Covid *tmp;
	tmp = (Covid *)malloc(sizeof(Covid));

	tmp = first;
	if (totalPatient == 0)
	{
		cout << "\n\nEmpty Database\n\n";
	}
	else
	{
		for (int i = 1; i <= totalPatient; i++)
		{
			cout<<"\n\t=====================";
			cout<<"\n\t|Patient no :"<<i<<"   |";
			cout<<"\n\t=====================\n";
			
			cout << "\nId\t: " << tmp->Id;
			cout << "\nName\t: " << tmp->patientName;
			cout << "\nAddress : " << tmp->patientAddress;
			cout << "\nLast report date : " << tmp->lastTestReportDate;
			cout << "\nMobile no : " << tmp->mobile;
			cout << "\nBlood Group : " << tmp->bloodGroup;

			tmp = tmp->next;
			cout<<endl<<endl;
		}
	}
}
int menu(void)
{
	int choice;
	do
	{
		cout << "\n 1. Insert\n";
		cout << " 2. Display\n";
		cout << " 0. Exit\n";
		cout << "\nEnter your choice : ";
		cin >> choice;

		if (choice < 0 || choice > 2)
			cout << " Wrong!... choice again\n";
	} while (choice < 0 || choice > 2);
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
			addRecord();
			break;
		case 2:
			Display();
			break;
		case 0:
			printf("\nEnd of operation\n");
			break;
		}
	} while (choice != 0);
}
int main()
{
	OptionMenu();
	return 0;
}
