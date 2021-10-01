#include <iostream>
#include <string>
#define nw "\n"
#define SIZE 100
using namespace std;

int stack[SIZE + 1], top = 0;

void push(int x)
{
	if (top == SIZE)
	{
		cout << "Overflow\n";
		return;
	}
	top++;
	stack[top] = x;
}
void pop()
{
	if (top == 0)
	{
		cout << "Underflow\n";
		return;
	}
	top--;
}
int main()
{
	cout << "Enter Expression : ";
	string exp;
	cin >> exp;
	int ans = 0;

	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			push(exp[i] - '0');
		}
		else
		{
			int A = stack[top];
			pop();

			int B = stack[top];
			pop();

			if (exp[i] == '+')
			{
				ans = A + B;
			}
			else if (exp[i] == '-')
			{
				ans = B - A;
			}
			else if (exp[i] == '*')
			{
				ans = A * B;
			}
			else if (exp[i] == '/')
			{
				ans = B / A;
			}
			else if(exp[i] == '^')
			{
				ans = pow(B,A);
			}
			push(ans);
		}
	}
	cout<<"The result of expression is : "<<stack[top];
	return 0;
}
