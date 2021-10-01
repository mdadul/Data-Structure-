#include <iostream>
#include <string>
#define nw "\n"

using namespace std;

int decToanyBase(int num, int base)
{
	int ans = 0, i = 1;
	while (num != 0)
	{
		int r = num % base;
		num /= base;
		ans += r * i;
		i *= 10;
		
	}
	return ans;
}
int anyBaseTodec(int num, int base)
{
	int ans = 0, i = 0;
	while (num != 0)
	{
		int r = num % 10;
		ans += r * pow(base, i);
		num /= 10;
		++i;
	}
	return ans;
}
int BaseConversion(int num, int Base, int d)
{
	if(d<2 || d>10) return 0;
	if(Base!=10)
	{
		int n = anyBaseTodec(num,Base);
		return decToanyBase(n,d);
	}
	else{
		return decToanyBase(num,d);
	}
	
}
int main()
{
	int n, numBase, dec;
	cout << "Enter the number : ";
	cin >> n;
	cout << "Enter the number base : ";
	cin >> numBase;
	cout << "Enter the base to convert : ";
	cin >> dec;

	cout << BaseConversion(n, numBase, dec);

	return 0;
}
