#include <bits/stdc++.h>
using namespace std;

int main()
{
	int d, c, r;
	cin >> d >> c >> r;
	
	vector<int> C(c);
	
	for (auto& i : C)
		cin >> i;

	vector<int> R(r);
	
	for (auto& i : R)
		cin >> i;
	
	int i, j, k;
	i = j = k = 0;
	
		
	while ( (d != 0 || j < r) && ( i < c || j < r))
	{
		if (i < c && C[i] <= d)
		{
			d -= C[i++];
			//cout << "Cansou com "<< C[i-1] << endl;
		}
		else if (j < r)
		{
			d += R[j++];
			//cout << "Revigorou com "<< R[j-1] << endl;
		}
		else
			break;
		
		k++;
	}

	cout << k << endl;
	
	return 0;
}