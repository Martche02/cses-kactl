#include <bits/stdc++.h>

using namespace std;

int main ()
{
	string s, p;
	
	cin >> s >> p;
	
	string z = p + "#" + s;
	
	int L = 0, R = 0;
	
	vector<int> pre(z.size(), 0);
	int rep = 0;
	
	for (int i = 1; i < z.size(); i++)
	{
		if (i <= R)
			pre[i] = min(pre[i-L], R-i+1);
		
		while (i + pre[i] < z.size() && z[i + pre[i]] == z[pre[i]])
			pre[i]++;
		
		if (i + pre[i] > R + 1)
		{
			L = i;
			R = i + pre[i] - 1;
		}
		
		
		if (pre[i] == p.size())
			rep++;
	}
	
	cout << rep << '\n';
	
	return 0;
}