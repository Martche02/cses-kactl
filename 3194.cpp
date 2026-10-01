#include <bits/stdc++.h>

using namespace std;

int a[2'000'000];
int dp[2'000'000];
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[i] = a[i];		
	}
	
	
	for (int j = 0; j < 18; j++)
		for (int i = 0; i < n; i++)
			if ((i >> j) & 1)
				dp[i] ^= dp[i ^ (1 << j)];
	
	for (int i = 0; i < n; i++)
		cout << dp[i] << ' ';
	
	cout << endl;
	
	return 0;
}