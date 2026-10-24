/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: 2023\A.cpp
 * Problem: Maratona 2023 - A
 * Description:
 *   Implementation for Maratona 2023 - A
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;
	int t = 0;
	while (N--)
	{
		int A;
		cin >> A;
		if (H>=A)
			t++;
	}
	
	
	cout << t << endl;
	return 0;
}