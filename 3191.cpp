#include <bits/stdc++.h>

using namespace std;

struct LinBase
{
		int Basis[31] = {0};
		
		void insert(int val)
		{
			int value = val;
			for (int b = 30; b >=0; b--)
			{
				int bit = (value >> b) & 1;
				int& base = Basis[b];
				if (bit == 0) continue;
				if (base == 0) base = value;
				value ^= base;
			}
			
		}
		
		int getMax()
		{
			int value = 0;
			
			for (int b = 30; b >=0; b--)
				value = max(value , value ^ Basis[b]);
			
			return value;
		}
};

LinBase lin;

int main()
{
	int n;
	cin >> n;
	
	
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		lin.insert(j);
	}

	cout << lin.getMax() << '\n';

	return 0;
	
}