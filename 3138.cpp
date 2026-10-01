#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string s;
	
	cin >> s;
	
	string M(2 * s.size() + 1, '#');
	
	int n = 0;
	
	for (int i = 0; i < s.size(); i++)
		M[2*i + 1] = s[i];
	
	vector<int> P(M.size(), 0);
	
	int R, C;
	
	R = C = 0;
	
	for (int i = 0; i < M.size(); i++)
	{		
		if (i < R)
			P[i] = min(P[2 * C - i], R-i);
		
		while( (i-P[i]-1 >=0) && (i+P[i]+1 < M.size())
			&& M[i-P[i]-1] == M[i+P[i]+1])			
			P[i]++;
		
		if (i+P[i] > R)
		{
			R = i+P[i];
			C = i;
		}
		
	}
	
	//E[i+P[i]] = max(E[i+P[i]], P[i]);
	
	vector<int> E(s.size(), 1);
	
	for (int i = 0; i < M.size(); i++)
	{
		if (P[i] <=0) continue;
		int fim = (i + P[i])/2-1;
		E[fim] = max(E[fim], P[i]);
	}
	
	
	for (int i = E.size()-1; i >= 1; i--)
	{
		E[i-1] = max(E[i-1], E[i]-2);
	}
	
	for (const auto& e : E)
		cout << e << ' ';
	
	cout << endl;
	
	return 0;
}
