#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll base = 1e9+7;


int main()
{
	int n;
	cin >> n;
	
	ll D[n+1] = {};
	
	D[0] = 0;
	D[1] = 0;
	D[2] = 1;
	
	
	for (int i = 3; i < n+1; i++)
		D[i] = ((i-1) * (D[i-1] + D[i-2]) ) % base;
	
	
	cout << D[n] << endl;
	
	return 0;
}