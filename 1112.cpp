#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7;
int main()
{
	
	int n;
	cin >> n;
	string padrao;
	cin >> padrao;
	
	int m = padrao.size();
	
	vector<int> pi(m, 0);
	
	//kpm pi
	for (int i = 1; i < m; i++)
	{
		int j = pi[i-1];
		
		while (j > 0 && padrao[i] != padrao[j])
			j = pi[j-1];
		
		if (padrao[i] == padrao[j])
			j++;
		
		pi[i] = j;
	}
	
	vector<vector<int>> prox_estado(m, vector<int>('z'-'a'+1, 0));
	
	for (int i = 0; i < m; i++)
	{
		for (char c = 'A'; c <= 'Z'; c++)
		{
			
			int j = i;
			
			while (j > 0 && c != padrao[j])
				j = pi[j-1];
			
			if (c == padrao[j])
				j++;
			
			prox_estado[i][c-'A'] = j;
		}
	}
	
	vector<vector<ll>> dp(n+1, vector<ll>(m+1));
	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (char c = 'A'; c <= 'Z'; c++)
			{
				int k = prox_estado[j][c-'A'];
				dp[i+1][k] = (dp[i][j] + dp[i+1][k]) % MOD;
			}			
		}
		
		dp[i+1][m] = (dp[i+1][m] + 26*dp[i][m]) % MOD;
	}
	
	cout << dp[n][m] << endl;

	return 0;
}