/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: 2021\G.cpp
 * Problem: Maratona 2021 - G
 * Description:
 *   Implementation for Maratona 2021 - G
 */
#include <bits/stdc++.h>
#define fori(i, n) for(int i=0; i<n; i++)(*@\label{fn35}@*)
using namespace std;
using ll = long long;
constexpr ll MAX_VAL = 100;
ll fib[MAX_VAL];

vector<int> candidates;
bool dfs(ll n, int id)(*@\label{fn36}@*)
{
	if(n == 1) return true;
	if(id <= 1) return false;
	
	if(n % fib[id] == 0){
		candidates.push_back(id);
		if(dfs(n/fib[id], id)) return true;
		candidates.pop_back();
	}
	return dfs(n, id-1);
}

int main()
{
	int i = 1;
	fib[0] = 1;
	fib[1] = 1;
	while (fib[i] <= 1e15)
	{
		fib[i+1] = fib[i] + fib[i-1];
		i += 1;
	}
	ll n;
	cin >> n;
	
	i--;
	
	if(dfs(n, i)){
		string s;
		for (auto& i : candidates)
		{
			fori(j, i-1)
			{
				s += 'A';
			}
			s += 'B';
		}
		
		cout << s 	<< '\n';
	}
	else
	{
		cout << "IMPOSSIBLE\n";
	}
	
	
	
	return 0;
}