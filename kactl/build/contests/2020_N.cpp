/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2020/N.cpp
 * Problem: Maratona 2020 - N
 * Description:
 *   Implementation for Maratona 2020 - N
 */
// start at 13:45
// finish at 13:59 AC
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string t;
	cin >> t;
	int cents = atoi(&t[t.size()-2]);
	int baddays = 0;
	while (n--)
	{
		string s;
		cin >> s;
		
		cents += atoi(&s[s.size()-2]);
			//+ 10 * (atoi(&s[s.size()-2]));
		
		if ((cents%100) != 0)
			baddays++;
		//cout << cents << '\n';
		
	}
	
	cout << baddays << '\n';
	
	return 0;
}