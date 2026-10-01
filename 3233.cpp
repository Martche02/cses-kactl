#include <bits/stdc++.h>

using namespace std;


const int SZ = 1 << 20;

void fwht(vector<long long>&a, bool invert)
{
	int s = a.size();
	for (int len = 1; len < s; len *= 2)
		for (int i = 0; i < s; i += 2 * len)
			for (int j = i; j < i + len; j++)
			{
				long long u = a[j];
				long long v = a[j + len];
				
				a[j] = u + v;
				a[j+len] = u - v;
				
			}
			
	
	if (invert)
		for (auto& i : a)
			i/=s;
}



int main()
{
	int n;
	cin >> n;
	
	//obtem as freq
	vector<long long> freq(SZ, 0);
	
	int acc = 0;
	
	freq[acc]++;
	for (int i =0; i < n; i++)
	{
		int p;
		cin >> p;
		acc ^= p;
		freq[acc]++;
		
		//algo com o freq[0]
		
	}
	
	fwht(freq, false);
	
	for (auto& i : freq)
		i *= i;
	
	fwht(freq, true);
	int nonZero = 0;
	vector<long long> r;
	
	if (freq[0] > n + 1) 
	{
		nonZero++;
		r.push_back(0);
	}
	
	for (int i = 1; i < freq.size(); i++) if (freq[i] != 0) 
	{
		nonZero++;
		r.push_back(i);
	}
	
	cout << nonZero << '\n';
	
	for (auto i : r)
		cout << i << ' ';
	cout << endl;
	return 0;
}