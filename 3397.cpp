#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

template <int N>
constexpr array<ll, N> calculateFat()
{
	array<ll, N> fat{};
	fat[0] = 1;
	for (int i = 1; i < N; i++)
		fat[i] = fat[i-1] * i;
	return fat;
}

constexpr array<ll, 21> fat = calculateFat<21>();


void print1(int n, ll k)
{	
	vector<int> disp(n);
	iota(disp.begin(), disp.end(), 1);
	for (int i = 0; i < n; i++)
	{
		int idx = (k / fat[n - 1 - i]);
		cout << disp[idx] << (i == n-1 ? '\n' : ' ');
		k %= fat[n - 1 - i];
		disp.erase(disp.begin() + idx);
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int n;
			ll k;
			cin >> n >> k;
			print1(n, k-1);
		}
		else
		{
			int n;
			cin >> n;
			vector<int> disp(n);
			iota(disp.begin(), disp.end(), 1);
			ll k = 0;
			while (n--)
			{
				int i;
				cin >> i;
				
				auto it = find(disp.begin(), disp.end(), i);
				int idx = distance(disp.begin(), it);
				k += idx*fat[n];
				disp.erase(it);
			}
			
			cout << k+1 << '\n';
		}
		
	}
	
	return 0;
}