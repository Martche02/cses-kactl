#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;
	int t = 0;
	while (N--)
	{
		int A;
		cin >> A;
		if (H>=A)
			t++;
	}
	
	
	cout << t << endl;
	return 0;
}