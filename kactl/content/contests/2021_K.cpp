/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2021/K.cpp
 * Problem: Maratona 2021 - K
 * Description:
 *   Implementation for Maratona 2021 - K
 */
// start at 14:01
// finished at 14:25 AC
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> init('Z'- 'A' + 1, 0);
	vector<vector<int>> freq(n, vector<int>('Z'- 'A' + 1, 0));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
	//	cout << s[0];
	//	cout << init[s[0]-'A'];
		init[s[0]-'A'] = 1;
		
	//	cout << s[0];
	//	cout << init[s[0]-'A'];
		
		for (const auto& j : s)
			freq[i][j - 'A'] = 1;;		
	}
	/*
	for (int j = 0; j <= 'Z'-'A'; j++)
		if (init[j])
			//cout << 'A' + j << ' ';
		*/
	//cout << '\n';
	//cout << 'A' + 0;
	
	for (int i = 0; i < n; i++)
	{
		bool Y = true;
		
		for (int j = 0; j <= 'Z'-'A'; j++)
		{
			if (freq[i][j] && (!init[j]))
			{
				Y = false;
				break;
			}
		}
		
		if (Y)
		{
			cout << "Y\n";
			return 0;
		}				
	}
	
	cout << "N\n";
	
	return 0;
}