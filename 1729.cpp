#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	
	cin >> n >> k;
	vector<int> c(k);
	
	for (auto& p : c)
		cin >> p;
	
	vector<bool> vit = {false};
	
	for (int i = 1; i < n+1; i++)
	{
		bool can = false;
		for (const auto p : c)
			if (i-p >=0 && vit[i-p] == false)
			{
				can = true;
				break;
			}
			
		vit.emplace_back(can);
		cout << (vit[i]? 'W' : 'L');
	}
	
	cout << endl;
	return 0;
}