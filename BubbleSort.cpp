#include<iostream>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+10];
	for(int i=1; i<=n; i++) cin>>arr[i];
	
	for(int k=1; k<=n-1; k++)
	{
		int ptr = 1;
		while(ptr<=n-k)
		{
			if(arr[ptr]>arr[ptr+1])
			{
				int temp = arr[ptr];
				arr[ptr] = arr[ptr+1];
				arr[ptr+1] = temp;
			}
			ptr+=1;
		}
	}
	for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
	return 0;
}
