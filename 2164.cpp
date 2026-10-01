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