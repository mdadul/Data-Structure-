/// Emdadul Islam
/// Algorithm : Pattern Matching Algorithm
/// Naive Pattern Searching

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define pi acos(-1)
#define ll long long
#define ull unsigned long long

int main()
{
	string p, t;
	cin >> p >> t;

	int r = p.size(); // pattern size
	int s = t.size(); // text size

	int k = 0, Max = s - r;

	int index = 0;
	bool found = false;
	while (k <= Max)
	{
		int l;
		for (l = 0; l < r; l++)
		{
			if (p[l] != t[k + l])
			{
				k = k + 1;
				break;
			}
		}
		if (l == r)
		{
			found = true;
			index = k + 1; // +1 for one base indexing.
			break;		   // to find first occurrence
		}
	}
	if (!found)
	{
		index = 0;
	}
	cout << "Index : " << index << endl;
	return 0;
}
