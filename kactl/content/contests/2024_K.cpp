/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: 2024\K.cpp
 * Problem: Maratona 2024 - K
 * Description:
 *   Implementation for Maratona 2024 - K
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int acc = 0;
	
	char atual = s[0];
	int changes = 0;
	
	int idx = 0;
	for (auto& c : s)
	{
		
		if (c != atual)
		{
			acc = 0;
			atual = c;
			idx++;
			continue;
		}
		
		acc++;
		if (acc >= n) // intervir
		{
			if (idx == s.size()-1 || s[idx+1] == c) // nao tem alternancia
			{
				c = (c == '1')
					? '0'
					: '1';
			}
			else
			{
				s[idx-1] = (c == '1')
					? '0'
					: '1';
			}
			
			changes++;
		}
		
		idx++;
		
	}
	
	cout << changes << ' ' << s << '\n';
	
	
	return 0;	
}