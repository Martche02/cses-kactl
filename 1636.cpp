#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name
using namespace std;

constexpr int macs = 1e6+5+5;
int dp[macs-2];
constexpr int MOD = 1e9+7;

int main()
{
	GET(int, n);
	GET(int, x);
	
	vector<int> C(n);
	
	for (auto& c : C)
		cin >> c;
	
	for (const auto& c : C)
	{
		dp[c]++;
		for (int i = 1; i <= x; i++)
			if (i-c >= 0)
				dp[i] = (dp[i] + dp[i-c])%MOD;
	}
			
	cout << dp[x] << '\n';



	return 0;
}