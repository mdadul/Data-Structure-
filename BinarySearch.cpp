#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int DATA[n+10];
	for(int i=1; i<=n; i++) cin>>DATA[i];
	int item;
	cin>>item;
	
	int Beg = 1;
	int End = n;
	int Mid = (Beg+End)/2;
	
	while(Beg<=End && DATA[Mid]!=item)
	{
		if(item<DATA[Mid])
		{
			End = Mid-1;
		}
		else{
			Beg = Mid + 1;
		}
		Mid = (Beg+End)/2;
	}
	if(DATA[Mid]==item)
	{
		cout<<"Item found in location : "<< Mid<<endl;
	}
	else{
		cout<<"Item not found\n";
	}
	
	return 0;
}
