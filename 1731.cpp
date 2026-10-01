#include <bits/stdc++.h>
using namespace std;


struct Node
{
	bool fim;
	int filhos[26];
	
	Node ()
		: fim(false)
	{
		fill(filhos, filhos + 26, -1);
	}
};

vector<Node> trie;

void insert(string& s)
{
	int u = 0;
	
	for (auto c : s)
	{
		int id = c - 'a';
		
		if (trie[u].filhos[id] == -1)
		{
			trie[u].filhos[id] = trie.size();
			trie.emplace_back();
		}

		u = trie[u].filhos[id];		
	}
	
	trie[u].fim = true;	
}

int main()
{
	string s;
	int k;
	cin >> s >> k;
	
	trie.emplace_back();
	
	while(k--)
	{
		string palavra;
		cin >> palavra;
		insert(palavra);
	}
	
	
	int n = s.size();
	
	long long MOD = 1e9+7;
	
	vector<long long> dp(n+1, 0);
	
	dp[n] = 1;
	
	for (int i = n-1; i >= 0; i--)
	{
		int u = 0;
		
		for (int j = i; j < n; j++)
		{
			int id = s[j] - 'a';
			
			if (trie[u].filhos[id] == -1)
				break;
			
			u = trie[u].filhos[id];
			
			if (trie[u].fim)
				dp[i] = (dp[i] + dp[j+1])%MOD;
		}
	}
	
	cout << dp[0] << endl;

	return 0;
}
