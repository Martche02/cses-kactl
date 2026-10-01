#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int Basis[31] = {0};
	int tamanho_base = 0;
	
	for (int i = 0; i< n; ++i)
	{
		int val;
		cin >> val;
		for (int b = 30; b >=0; b--)
		{
			int bit = (val >> b) & 1;
			if (bit == 1)
			{
				if (Basis[b] == 0)
				{
					Basis[b] = val;
					tamanho_base++;
					break;
				}
				else
					val ^= Basis[b];
			}
		}
	}
	
	
	for (int b = 30; b>= 0; b--) if (Basis[b])
		for (int j = b-1; j >=0; j--) if ((Basis[b] >> j) & 1)
			Basis[b] ^= Basis[j];
		
	
	vector<int> blimpa;
	for (auto b : Basis) if (b)
		blimpa.emplace_back(b);
	
	
	int d = n- tamanho_base;
	long long d2 = 1;
	for (int i = 0; i < d; ++i) 
	{
	    d2 *= 2;
	    if (d2 >= k) { d2 = k; break; }
	}
	
	int limite_m = (1 << blimpa.size());
	int impressos = 0;
	for (int m =0; m < limite_m && impressos < k; ++m)
	{
		int xor_atual = 0;
		for (int i = 0; i< blimpa.size(); i++)
		{
			if ((m>>i) & 1)
				xor_atual ^= blimpa[i];
		}
		
		for (int r = 0; r < d2 && impressos < k; r++)
		{
			cout << xor_atual << ' ';
			impressos++;	
		}
		
	}
	
	cout << endl;

	return 0;
}