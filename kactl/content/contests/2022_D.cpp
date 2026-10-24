/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2022/D.cpp
 * Problem: Maratona 2022 - D
 * Description:
 *   Implementation for Maratona 2022 - D
 */
// start 15:58
// finished 16:14
#include <bits/stdc++.h>

using namespace std;
int n, h, w;

bool simulate(bool rain, bool toWork)
{
	if (rain)
	{
		if (toWork)
		{
			h--;
			w++;
			return true;
		}
		else
		{
			h++;
			w--;
			return true;
		}
	}
	
	if (toWork && w == 0)
	{
		h--;
		w++;
		return true;
	}
	
	if (!toWork && h == 0)
	{
		h++;
		w--;
		return true;		
	}
	
	return false;
}

int main()
{
	cin >> n >> h >> w;
	
	for (int i = 0; i < n; i++)
	{
		pair<char, char> p;
		cin >> p.first >> p.second;
		
		cout << (simulate(p.first == 'Y', true)
			? "Y "
			: "N "
			);
		cout << (simulate(p.second == 'Y', false)
			? "Y\n"
			: "N\n"
			);
	}
	
	return 0;
}