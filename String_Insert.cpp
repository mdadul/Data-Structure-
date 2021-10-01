
#include <iostream>
#include <string>
#define nw "\n"

using namespace std;

string insert(string text, string s, int k)
{
	k = k - 1;
	int textSize = text.size();
	int sSize = s.size();

	int j = textSize - 1;

	text.resize(textSize + sSize);

	while (k <= j)
	{
		text[j + sSize] = text[j];
		j--;
	}
	int l = 0;
	for (int i = k; i < k + sSize; i++)
	{
		text[i] = s[l];
		l++;
	}
	return text;
}
int main()
{
	string text, s;
	int k;
	cin >> text >> s >> k;
	cout << insert(text, s, k);
	return 0;
}
