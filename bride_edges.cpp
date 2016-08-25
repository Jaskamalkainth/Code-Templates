/*
 * Bridge edges in the graph
 * O(n) , DFS
 */
const int maxn = 1e5+7;
vector<int> G[maxn];
int low[maxn], disc[maxn] , parent[maxn] , vis[maxn];
vector<pair<int,int> > bedge; // all bridge edges 
int timer;

inline void clear()
{
	timer = 0;
	for(int i = 0; i < maxn; i++)
	{
		low[i] = disc[i] = vis[i] = 0;
		parent[i] = -1;
		G[i].clear();
	}
}
inline void dfs(int u)
{
	vis[u] = 1;
	disc[u] = low[u] = timer++;
	for(int &v: G[u])
	{
		if(!vis[v])
		{
			parent[v] = u;
			dfs(v);
			low[u] = min(low[u],low[v]);
			if(low[v] > disc[u])
			{
				// u-v is a bridge edge
				bedge.push_back(mp(u,v));
			}
		}
		else if(parent[u] != v)
		{
			low[u] = min(low[u],disc[v]);
		}
	}
}

