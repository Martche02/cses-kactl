#include <bits/stdc++.h>
#define maxn 200000

using namespace std;

struct Trie
{
	struct Node
	{
		int to[2];
	};
	
	int building = 1;
	Node tree[maxn*31+5];
	
	void insert(int val)
	{
		int visit = 1;
		
		for (int b = 30; b >= 0; b--)
		{
			int bit = (val >> b) & 1;
			
			int& n = tree[visit].to[bit];
			
			if (n == 0) n = ++building;
			visit = n;		
		}
		
	}
	
	int findxor(int val)
	{
		int best = 0;
		int visit = 1;
		
		for (int b = 30; b >= 0; b--)
		{
			int bit = (val >> b) & 1;
			
			int n = tree[visit].to[bit ^ 1];
			
			if (n == 0) n = tree[visit].to[bit];
			else best += (1 << b);
			
			visit = n;
		}
		
		return best;
		
	}
	
};


Trie tree;
int main()
{
	int n;
	int valores[maxn];
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> valores[i];
	
	
	int xorsum = 0;
	int acxor = 0;
	
	tree.insert(0);
	
	for (int i = 0; i < n; i++)
	{
		int v = valores[i];
		acxor ^= v;
		int xs = tree.findxor(acxor);
		xorsum =  xs > xorsum ? xs : xorsum;
		tree.insert(acxor);
	}
	
	
	cout << xorsum << '\n';
	
	return 0;
}