#include<iostream>

#define nw "\n"

using namespace std;

bool prime[100000];
void seive(int n)
{
	memset(prime,1,sizeof(prime));
	
	prime[0]=0,prime[1]=0;
	
	for(int i=2; i*i<=n; i++)
	{
		if(prime[i])
		{
			for(int j=i*i; j<=n; j+=i){
				prime[j]=0;
			}
		}
	}
}

int main()
{
	seive(100000);
	int n;
	cin>>n;
	if(prime[n])
	{
		cout<<n<<" is a prime number\n";
	}
	else
	{
		 cout<<n<<" isn't a prime number\n";
	}
	return 0;
}
