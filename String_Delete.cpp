#include<iostream>
#include<string>
#define nw "\n"

using namespace std;

string Delete(string text, int len, int pos)
{
	if(len==0) return "Invalid Operation \n";
	for(int i=pos; i<text.size(); i++)
	{
		text[i] = text[i+len];
	}
	return text;
}

int main()
{
	string text;
	cin>>text;
	int len,pos;
	cout<<" Enter length to delete: ";
	cin>>len;
	cout<<" Enter position : ";
	cin>>pos;
	cout<<Delete(text,len,pos);
	return 0;
}
