#include <bits/stdc++.h>

using namespace std;

string s;
long long modulo = 1e9+7;
long long base = 31;

#define MOD(V) (((V) % modulo + modulo) % modulo)

long long getHash(int R, vector<long long>& hash, vector<long long>& pot);
long long getHash(int L, int R, vector<long long>& hash, vector<long long>& pot);

long long getHash(int R, vector<long long>& hash, vector<long long>& pot)
{
	return hash[R];
}

long long getHash(int L, int R, vector<long long>& hash, vector<long long>& pot)
{
	int tam = R - L +1;
	
	long long hL = MOD(hash[L-1] * pot[tam]);
	
	return MOD(hash[R] - hL);
}

int main()
{
	cin >> s;

	int n = s.size();
	vector<long long> hash(n);
	vector<long long> pot(n);
	
	pot[0] = 1;
	for (int i = 1; i < n; i++)
	{
		pot[i] = MOD(pot[i-1] * base);
	}
	
	
	hash[0] = s[0];
	
	for (int i = 1; i < n; i++)
	{
		hash[i] = MOD(hash[i-1] * base + s[i]);
	}
	
	
	for (int i = 1; i < n; i++)
	{
		if (getHash(i-1, hash, pot) == getHash(n-i, n-1, hash, pot))
			cout << i << ' ';
	}
	
	cout << endl;
	
	
	
	return 0;
}