#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name
using namespace std;

constexpr int macs = 1e6+5+5;
int dp[macs-2];

int main()
{
	GET(int, n);
	GET(int, x);
	
	vector<int> C(n);
	
	for (auto& c : C)
		cin >> c;
	
	dp[0] = 0;
	
	for (int i = 1; i <= x; i++)
	{
		dp[i] = macs;
		for (const auto& c : C)
			if (i - c >= 0)
				dp[i] = min(dp[i], dp[i-c] + 1);
		
	}
	
	int& v = dp[x];
	cout << (v == macs ? -1 : v) << '\n';



	return 0;
}