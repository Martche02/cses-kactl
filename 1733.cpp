#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string& s)
{
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0; // l e r formam a "janela" do match mais a direita que já achamos
    
    for (int i = 1; i < n; i++)
	{
        // Se o i tá dentro da janela, a gente copia o valor que já calculamos no passado!
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        // Tenta expandir o match letra por letra
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
            z[i]++;
		
        // Se o nosso match ultrapassou a janela, a gente atualiza a janela
        if (i + z[i] > r)
		{
            l = i;
            r = i + z[i];
        }
    }
	
    return z;
}

int main()
{
	string s;
	cin >> s;
	vector<int> z = z_function(s);
	
	int n = s.length();
	
	for (int i = 1; i < n; i++)
	{
		if (z[i] == n - i)
			cout << i << ' ';
	}
	
	cout << n;
	
	cout << endl;

	return 0;
}