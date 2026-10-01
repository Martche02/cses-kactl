/**
 * Author: Team KACTL / Marce
 * Category: Mathematics
 * CSES Task ID: 2164
 * CSES Problem: Josephus Queries
 * Link: https://cses.fi/problemset/task/2164
 * Description:
 *   addEventListener("DOMContentLoaded", function (e) {
 *   const mathElements = document.getElementsByClassName("math");
 *   const macros = {};
 *   for (let element of mathElements) {
 *   katex.render(element.textContent, element, {
 *   displayMode: element.classList.contains("math-display"),
 *   throwOnError: false,
 *   globalGroup: true,
 *   macros,
 *   });
 *   }
 *   });
 *   .katex .base:last-child {
 *   display: inline;
 *   }
 *   Time limit: 1.00 s
 *   Memory limit: 512 MB
 *   Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During the game, every second child is removed from the circle, until there are no children left.
 *   Your task is to process q queries of the form: "when there are n children, who is the kth child that will be removed?"
 *   Input
 *   The first input line has an integer q: the number of queries.
 *   After this, there are q lines that describe the queries. Each line has two integers n and k: the number of children and the position of the child.
 *   Output
 *   Print q integers: the answer for each query.
 *   Constraints
 *   1 \le q \le 10^5
 *   1 \le k \le n \le 10^9
 *   Example
 *   Input:
 *   4
 *   7 1
 *   7 3
 *   2 2
 *   1337 1313
 *   Output:
 *   2
 *   6
 *   1
 *   1107
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll solve (ll n, ll k)
{
	if (n == 1) 
		return 1;
	
	// n/2 cabem na primeira rodada, antes de repetir
	// se n par, isso se reduz a solve(n/2, k-n/2)
	// se n impar sobra um cara, e se reduz a solve(n - n/2, k - n/2), que é o caso generico
	
	if (k > n/2)
	{
		ll s = solve(n - n/2, k - n/2);
		
		if (n%2 == 0)
		{
			return s*2 - 1;
		}
		else
		{
			if (s == 1) return n;
			else return s*2-3;
		}
	}
	// caso nao, podemos consideirar linear
	// dai podemos ignorar o n
	// se k=1, temos 1, k=2 temos 3, k = k, temos 2k+1
	
	return 2*k;
	
}


int main()
{
	int q;
	cin >> q;
	
	vector<pair<ll, ll>> aws;
	while (q--)
	{
		ll n, k;
		cin >> n >> k;
		
		aws.emplace_back(n,k);
	}
	
	for (auto& [n,k] : aws)
		cout << solve(n,k) << '\n';

	return 0;
}