/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2025/H.cpp
 * Problem: Maratona 2025 - H
 * Description:
 *   Implementation for Maratona 2025 - H
 */
//start 23:05
//finished 23:14
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int days = 0;
	int top = 0;
	
	for (const int i : views::iota(0,n))
	{
		int t;
		cin >> t;
		
		if (t > top)
		{
			top = t;
			days++;
		}
		
	}
	
	cout << days << endl;
	
	return 0;
}