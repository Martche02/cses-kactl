/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2024/B.cpp
 * Problem: Maratona 2024 - B
 * Description:
 *   Implementation for Maratona 2024 - B
 */
// start 23:15
// finished 23:40 AC
#include <bits/stdc++.h>

using namespace std;

int dp[200000+5];

int main()
{
	int n;
	cin >> n;
	
	for (auto& i : dp)
		i = 0;
	
	for (const auto& i : views::iota(0,3*n))
	{
		int b;
		cin >> b;
		
		dp[100000+b]++;
	}
	
	
	for (const auto& i : dp)
	{
		if (i%3 != 0)
		{
			cout << "Y\n";
			return 0;
		}
	}
	
	cout << "N\n";
	
	
	return 0;
}