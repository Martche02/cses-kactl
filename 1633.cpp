#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr int top = 1e6+5;

ll dp[top];

int main()
{
	int n;
	cin >> n;
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int k = 1; k < 7; k++)
			if (i-k >= 0)
				dp[i] = (dp[i] + dp[i-k]) % MOD;
			
			
	cout << dp[n] << '\n';



	return 0;
}