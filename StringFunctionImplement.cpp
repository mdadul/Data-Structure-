#include<iostream>
#include<string>

#define nw "\n"

using namespace std;

int SIZE(string s)
{
	int sz=0;
	
	for(int i=0; s[i]!='\0'; i++)
	{
		sz++;
	}
	return sz;
}
string copy(string s1)
{
	int sz = SIZE(s1);
	
	string s2;
	s2.resize(sz);
	
	for(int i=0; i<SIZE(s1); i++)
	{
		s2[i] = s1[i];
	}
	return s2;
}
string concat(string s1, string s2)
{
	int len = SIZE(s1);
	int l2 = SIZE(s2);
	
	s1.resize(len+l2);
	
	int l=0;
	for(int i=len;i<=len+l2; i++)
	{
		s1[i] = s2[l];
		l++;	
	}
	return s1;
}
string comp(string a, string b)
{
	int i=0;
	while(a[i]==b[i] && a[i]!='\0')
	{
		i++;
	}
	if(a[i]>b[i])
	{
		return "STRING 1 IS GREATER THAN STRING 2\n";
	}
	else if(a[i]<b[i])
	{
		return " STRING 2 IS GREATER THAN STRING 1\n";
	}
	else{
		return "STRING  1 & 2 ARE EQUAL \n";
	}
}
string reverse(string s)
{
	int sz = SIZE(s);
	string r;
	r.resize(sz);
	int j=0;
	for(int i=sz-1; i>=0; i--)
	{
		r[j] = s[i];
		j++;
	}
	return r;
}
		
int main()
{
	cout<<"Enter a string s : ";
	string s;
	cin>>s;
	// a -> size 
	cout<<"[A] SIZE OF STRING : "<<SIZE(s)<<nw;
	
	// b -> str copy 
	
	string s2 = copy(s);
	cout<<"[B] STRING S COPY TO S2: "<<s2<<nw;
	
	
	// c -> str concatenate 
	string s3;
	cout<<" Enter string s3 : ";
	cin>>s3;
	cout<<"[C] Concatenate s & s3 : "<<concat(s,s3)<<nw;

	// d -> compare 
	
	cout<<"[D] String Compare : "<< comp("EMDADUL","Islam");
	
	// e -> reverse
	
	cout<<"[E] Reverse : "<<reverse(s)<<nw;
	
	
	return 0;
}
