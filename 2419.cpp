#include <bits/stdc++.h>

using namespace std;




int main()
{
	int n;
	cin >> n;
	
	int acc = 0;
	
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		if (((n-1) & i) == i)
			acc ^= val;
	}
	
	cout << acc << endl;
	return 0;
}