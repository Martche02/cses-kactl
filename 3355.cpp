#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll top = 1e7+1;
constexpr ll sqr = 3162;
pair<ll,ll> par[top];


int main()
{
	for (auto& i : par)
		i = {sqr+1, sqr+1};
	for (int a = 0; a <= sqr; a++)
		for (int b = 0; b <= sqr; b++)
			if (a*a+b*b < top)
				par[a*a+b*b] = {a, b};
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i <= n; i++)
			if (par[i].first != sqr+1 && par[n-i].first != sqr+1)
			{
				cout << par[i].first << ' ' << par[i].second << ' ' << par[n-i].first << ' ' << par[n-i].second << '\n';
				break;
			}
	}
	

	return 0;
}