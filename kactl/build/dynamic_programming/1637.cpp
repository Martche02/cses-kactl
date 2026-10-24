/**
 * Author: Team KACTL / Marce
 * Category: dynamic_programming
 * Source: 1637.cpp
 * CSES Task ID: 1637
 * CSES Problem: Removing Digits
 * Link: https://cses.fi/problemset/task/1637
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
 *   You are given an integer n. On each step, you may subtract one of the digits from the number.
 *   How many steps are required to make the number equal to 0?
 *   Input
 *   The only input line has an integer n.
 *   Output
 *   Print one integer: the minimum number of steps.
 *   Constraints
 *   1 \le n \le 10^6
 *   Example
 *   Input:
 *   27
 *   Output:
 *   5
 *   Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.
 */
#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name(*@\label{fn12}@*)

using namespace std;

vector<int> adj(int u)(*@\label{fn13}@*)
{
	vector<int> sol;
	for (int a = 1; a < 10; a++)
	{
		int b = u + a;
		while (((u+a) - b%10) != u)
		{
			if (b == 0)
				break;
			else
				b /= 10;
		}
			
		if (b != 0)
			sol.push_back(u+a);
	}
	
	return sol;
}

int main()
{
	GET(int, n);
	vector<int> dist(2*n+1, -1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == n)
		{
			cout << dist[u] << '\n';
			break;
		}
		
		for (auto i : adj(u))
			if (dist[i] == -1)
			{
				dist[i] = dist[u]+1;
				q.push(i);
			}
		
	}
	
	return 0;
}