/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2023/D.cpp
 * Problem: Maratona 2023 - D
 * Description:
 *   Implementation for Maratona 2023 - D
 */
// start 16:29
// finished 21:51 AC de segunda
// com empecilhos
#include <bits/stdc++.h>

using namespace std;
string key;

string match(const string& s)
{
	string p = "";
	for (const int i : views::iota(0,5))
	{
			
		if (s[i] == key[i])
		{
			p += '*';
			continue;
		}
		
		bool quase = false;
		for (const int j : views::iota(0,5))
		{
			if (j != i && s[i] == key[j])
			{
				quase = true;
				p += '!';
				break;
			}
		}
		
		if (quase)
			continue;
				
		p += 'X';
	}
	
	return p;
}

int main()
{
	int n;
	cin >> n;
	
	vector<string> p (n);
	vector<string> rgx (n);
	
	for (const int i : views::iota(0,n))
	{
		cin >> p[i];
		if (i == 0)
			key = p[i];
		
		rgx[i] = match(p[i]);
		//cout << rgx[i] << endl << endl;
	}
	
	int x;
	cin >> x;
	
	for (const int i : views::iota(0,x)) // 10
	{
		string t;
		cin >> t;
		int m = 0;
		
		for (const auto& r : rgx)
			if (t == r)
				m++;
			
		cout << m << endl;
	}	
	return 0;
}