#include <bits/stdc++.h>
#define GET(type, name) type name; cin >> name

using namespace std;

vector<int> adj(int u)
{
	vector<int> sol;
	for (int a = 1; a < 10; a++)
	{
		int b = u + a;
		while (((u+a) - b%10) != u)
		{
			if (b == 0)
				break;
			else
				b /= 10;
		}
			
		if (b != 0)
			sol.push_back(u+a);
	}
	
	return sol;
}

int main()
{
	GET(int, n);
	vector<int> dist(2*n+1, -1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == n)
		{
			cout << dist[u] << '\n';
			break;
		}
		
		for (auto i : adj(u))
			if (dist[i] == -1)
			{
				dist[i] = dist[u]+1;
				q.push(i);
			}
		
	}
	
	return 0;
}