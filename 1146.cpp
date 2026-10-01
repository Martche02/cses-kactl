#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long n, sum = 0;
	int k;
	cin >> n;
	
	while (n)
	{
		// se n = 2 ^ k
		// cout << (n)*k/2 + 1
		k = bit_width(n) - 1;
		n ^= (1LL << k);
		
		sum += (((1LL << k)*k) >>1) + 1;
		sum += n;
	}
	cout << sum << endl;
	
	return 0;
}