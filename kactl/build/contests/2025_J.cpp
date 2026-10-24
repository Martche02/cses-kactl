/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2025/J.cpp
 * Problem: Maratona 2025 - J
 * Description:
 *   Implementation for Maratona 2025 - J
 */
// start 22:07
// WA em 22:20
// finished em 22:29 com WA

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	
	cin >> s;
	
	pair<string, int> ha;
	ha.first = "ha";
	ha.second = 1;
	pair<string, int> boooo;
	boooo.first = "boooo";
	boooo.second = -1;
	pair<string, int> bravo;
	bravo.first = "bravo";
	bravo.second = 3;
	
	int h, bo, br;
	h = 0;
	bo = 0;
	br = 0;
	
	int r = 0;
	for (const auto& i : s)
	{
		if (ha.first[h] == i)
		{
			if (h == ha.first.size() - 1)
			{
				h = 0;
				r += ha.second;
			}
			else
			{
				h++;
			}
		}
		else
		{
			h = 0;
			
			if (ha.first[h] == i)
				h++;
		}
		
		
		if (boooo.first[bo] == i)
		{
			if (bo == boooo.first.size() - 1)
			{
				bo = 0;
				r += boooo.second;
			}
			else
			{
				bo++;
			}
		}
		else
		{
			bo = 0;
			
			if (boooo.first[bo] == i)
				bo++;
		}
		
			//cout << br << ' ' << bravo.first.size() << ' ' << bravo.first << ' ' << i << ' ' << bravo.first[br] << endl;
		
		
		if (bravo.first[br] == i)
		{
			
			if (br == bravo.first.size() - 1)
			{
				//cout << "AQUI"<< endl;
				br = 0;
				r += bravo.second;
			}
			else
			{
				br++;
			}
		}
		else
		{
			br = 0;
			
			if (bravo.first[br] == i)
				br++;
		}
	}
	
	cout << r << endl;
	
	return 0;
}