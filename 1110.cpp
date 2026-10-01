#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s += s;
	
	vector<int> tops;

	int i = 0;
	int j = i+1;
	while (i < n && j < n)
	{
		int k = 0;
		while (s[i+k] == s[j+k] && k < n) k++;
		if (k == n) 
            break;
		if (s[i+k] < s[j+k])
			j += k+1;
		else
			i += k+1;
		
		if (i == j)
			j++;
	}
		
	string_view sv{s};
		
cout << sv.substr(min(i,j), n) << '\n';
	return 0;
}