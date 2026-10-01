#include <bits/stdc++.h>
using namespace std;

constexpr int top = 1e2+5;

double dp[top][6*top];

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	
	dp[0][0] = 1.0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6*i; j++)
			for (int k = 1; k <7; k++)
				if (j-k >= 0)
					dp[i][j] += dp[i-1][j-k] / 6.0;
			
			
	double ans = 0.0;
	for (int j = a; j<=b; j++)
		ans += dp[n][j];
	
	cout << fixed << setprecision(6) << ans << '\n';



	return 0;
}