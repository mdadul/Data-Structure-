// 04
// Matrix Multiplication 

#include<iostream>
using namespace std;

int main()
{
	int m,p,q,n;
	cin>>m>>p;
	int A[m+10][p+10];
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=p; j++)
		{
			cin>>A[i][j];
		}
	}
	cin>>q>>n;
	int B[n+10][p+10];
	
	for(int i=1; i<=q; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>B[i][j];
		}
	}
	int c[m+10][n+10];
	
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			c[i][j]=0;
			for(int k=1; k<=p; k++)
			{
				c[i][j] = c[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
