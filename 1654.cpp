#include <bits/stdc++.h>

using namespace std;

int B = 20;
int MAX_MASK = 1 << B;

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> sub(MAX_MASK);
	vector<int> super(MAX_MASK);
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sub[a[i]]++;
		super[a[i]]++;
	}
	
	for (int bit = 0; bit < B; bit++)
	{
		for (int i = 0; i < MAX_MASK; i++)
		{
			if (i & (1 << bit))
			{
				 sub[i] += sub[i ^ (1 << bit)];
			}
			else
			{
				 super[i] += super[i ^ (1 << bit)];
			}
		}
	}
	
	for (auto i : a)
	{
		cout << sub[i] << ' ' << super[i] << ' ' << n - sub[(~i) & (MAX_MASK - 1)] << '\n';
	}
	
	
	return 0;
}