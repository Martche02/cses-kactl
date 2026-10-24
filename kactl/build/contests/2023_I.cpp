/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: 2023\I.cpp
 * Problem: Maratona 2023 - I
 * Description:
 *   Implementation for Maratona 2023 - I
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dp
{
	bool parity = 0;
	array<int, 2> startwith{1, 0};
	ll acc = 0;
	
	void update(bool bit)(*@\label{fn37}@*)
	{
		parity ^= bit;
		startwith[parity]++;
		acc += startwith[!parity];
	}
};

int main()
{
	int n;
	cin >> n;
	
	dp e;
	//cout << 0 << ' ' << e.parity << ' ' << e.startwith[1] << ' ' << e.startwith[0] << ' ' << e.acc << '\n';
	
	while(n--)
	{
		bool b;
		cin >> b;
		e.update(b);
		//cout << b << ' ' << e.parity << ' ' << e.startwith[1] << ' ' << e.startwith[0] << ' ' << e.acc << '\n';
	}
	
	cout << e.acc << endl;
	
	return 0;
}