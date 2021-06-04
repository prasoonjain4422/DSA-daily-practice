#include<bits/stdc++.h>
using namespace std;

int timer=0;
void dfs(int i, vector<bool> &vis, vector<int> adj[], vector<int> &st, vector<int> &et)
{
	vis[i] = true;
	st[i] = timer++;

	for(auto x: adj[i])
	{
		if(!vis[x])
		{
			dfs(x, vis, adj, st, et);
		}
	}

	et[i] = timer++;
}

int main()
{
	int n, q, i, u, v, j;
	cin>>n;

	vector<int> adj[n+1];
	for(i=0; i<n-1; i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> st(n);
	vector<int> et(n);
	vector<bool> vis(n, false);

	vis[1] = true;
	dfs(1, vis, adj, st, et);

	cin>>q;
	while(q--)
	{
		cin>>j>>u>>v;

		if(j == 0)
		{
			if((st[u] <= st[v])&&(et[u] >= st[v]))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			if((st[v] <= st[u])&&(et[v] >= st[u]))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
