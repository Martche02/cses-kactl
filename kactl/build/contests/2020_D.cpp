/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2020/D.cpp
 * Problem: Maratona 2020 - D
 * Description:
 *   Implementation for Maratona 2020 - D
 */
// start 00:05
// 00:41 WA (aumentar limite)
// finish 00:42 AC
#include <bits/stdc++.h>

using namespace std;

vector<bool> v(1000000+105, false);

void inc(int i)(*@\label{fn87}@*)
{
	v[i] = !v[i];
	if (!v[i])
		inc(i+1);
}


int main()
{
	int n;
	
	cin >> n;
	
	int bitcount = 0;
	int m = n;
	while (n--)
	{
		int i;
		cin >> i;
		inc(i);
	}
	
	for (const int i : views::iota(0,1000000+105))
	{
		bitcount += v[i];
	}
	
	if (bitcount > 2)
	{
		cout << "N\n";
	}
	else if (bitcount == 2)
	{
		cout << "Y\n";
	}
	else
	{
		cout << ((m > 1) ? "Y\n" : "N\n");
	}
	
	
	
	return 0;
}