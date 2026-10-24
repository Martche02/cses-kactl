/**
 * Author: Team KACTL / Marce
 * Category: mathematics
 * Source: 1095.cpp
 * CSES Task ID: 1095
 * CSES Problem: Exponentiation
 * Link: https://cses.fi/problemset/task/1095
 * Description:
 *   Time limit: 1.00 s
 *   Memory limit: 512 MB
 *   Your task is to efficiently calculate values a^b modulo 10^9+7.
 *   Note that in this task we assume that 0^0=1.
 *   Input
 *   The first input line contains an integer n: the number of calculations.
 *   After this, there are n lines, each containing two integers a and b.
 *   Output
 *   Print each value a^b modulo 10^9+7.
 *   Constraints
 *   1 \le n \le 2 \cdot 10^5
 *   0 \le a,b \le 10^9
 *   Example
 *   Input:
 *   3
 *   3 4
 *   2 8
 *   123 123
 *   Output:
 *   81
 *   256
 *   921450052
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll base = 1e9+7;

#define MOD(v) ( ((v%base) + base)%base )

ll exp(ll a, ll b)
{
	ll res = 1;
	while (b > 0)
	{
		if (b&1)
			res = MOD(a*res);
		
		a = MOD(a*a);
		
		b >>= 1;
	}
	
	return res;
}


int main()
{
	ll q;
	cin >> q;
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << exp(a, b) << '\n';
	}
	
	return 0;
}