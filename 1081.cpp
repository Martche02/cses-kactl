#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1000005;


int mdc2(vector<int>& x)
{
	int maxmdc = 1;
	
	for (int i = 1; i < MAXM; i++)
	{
		int j = i;
		int mults = 0;
		while (j < MAXM)
		{
			if (x[j])
			{
				mults += x[j];
				//cout << "incrementou mults, valores: \n  i=" << i << "\n  j=" << j << "\n  mults = " << mults;
			}
			j += i;
		}
		
		if (mults >= 2)
			maxmdc = max(i, maxmdc);
		
	}
	
	return maxmdc;
}


int main()
{
	int n;
	cin >> n;
	vector<int> x(MAXM);
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		
		x[j]++;
	}
	
	cout << mdc2(x) << endl;

	return 0;
}