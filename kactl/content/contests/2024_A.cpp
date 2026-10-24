/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2024/A.cpp
 * Problem: Maratona 2024 - A
 * Description:
 *   Implementation for Maratona 2024 - A
 */
// start 21:53
// finished 22:03 AC
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	vector<bool> visited ('Z'-'A'+1, false);
	
	for (const auto& [idx, i] : views::enumerate(views::reverse(s)))
	{
		//cout << idx << ' ' << i << ' ' << endl;
		if (visited[i-'A'])
		{
			cout << s.size() - idx << endl;
			return 0;
		}
		
		visited[i-'A'] = true;
	}
	
	return 0;
}