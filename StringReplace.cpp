
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define nw "\n"

using namespace std;

#define pi acos(-1)
#define ll long long
#define ull unsigned long long

string Replace(string text, string pattern, string Q)
{
	int textSize = text.size();
	int ptrSize = pattern.size();
	int Qsize = Q.size();
	int Max = textSize - ptrSize;

	bool found = false;

	int k = 0, index = -1;
	while (k <= Max)
	{
		int i = 0;
		for (i = 0; i < ptrSize; i++)
		{
			if (text[k + i] != pattern[i])
			{
				k++;
				break;
			}
		}
		if (i == ptrSize)
		{
			found = true;
			index = k;
			break;
		}
	}
	if (found)
	{
		if (ptrSize > Qsize)
		{
			int l = 0, idx = 0;
			for (int i = index; i < index + Qsize; i++)
			{
				text[i] = Q[l];
				l++;
				idx = i;
			}
			int space = ptrSize - Qsize;

			for (int i = idx; i < textSize - 1; i++)
			{
				text[i + space] = text[i + 1 + space];
			}
		}
		else if (ptrSize < Qsize)
		{
			int dis = Qsize - ptrSize;

			int i = textSize - 1;
			int idx = index + Qsize;
			text.resize(textSize + dis);
			while (i >= idx)
			{
				text[i + dis] = text[i];
				i--;
			}
			int l = 0;
			for (int i = index; i < index + Qsize; i++)
			{
				text[i] = Q[l];
				l++;
			}
		}
		else
		{
			int l = 0;
			for (int j = index; j < index + Qsize; j++)
			{
				text[j] = Q[l];
				l++;
			}
		}

		return text;
	}
	else
	{
		return "Pattern not found in this text,  so Replace impossible\n";
	}
}
int main()
{
	string text, pattern, Q;
	cin >> text >> pattern >> Q;

	cout << Replace(text, pattern, Q);

	return 0;
}
