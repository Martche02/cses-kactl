#include <bits/stdc++.h>

using namespace std;

int a[2'000'000];
int dp[2'000'000];
int main()
{
	int n, k, p;
	cin >> n >> k;
	p = n - k;
	
	int len = n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int bit = 0; (1 << bit) <= p; bit++)
	{
		if ((p >> bit) & 1)
		{
			int jump = 1 << bit;
			len -= jump;
			for (int i = 0; i < len; i++)
				a[i] ^= a[i + jump];		
		}		
	}
	
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	
	cout << endl;
	
	return 0;
}
