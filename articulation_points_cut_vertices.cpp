/*
 * Cut vertex / Articulation points
 * O(n) , DFS
 */
const int maxn = 3e3+7; // number of nodes
vector<int> G[maxn];
int disc[maxn],vis[maxn],parent[maxn]={-1},anode[maxn],low[maxn];
int timer;


inline void clear()
{
	for(int i = 0; i < maxn; i++)
	{
		disc[i] = vis[i] = anode[i] = low[i] = 0;
		parent[i] = -1;
		timer = 0;
		G[i].clear();
	}
}
inline void dfs(int u)
{
	vis[u] = 1;
	disc[u] = low[u] = timer++;
	int child = 0;
	for(int &v: G[u])
	{
		if(!vis[v])
		{
			child++;
			parent[v] = u;
			dfs(v);
			low[u] = min(low[u],low[v]);
			// 2 cases
			if(parent[u] == -1 && child > 1)
				anode[u] = 1;
			if(parent[u] != -1 && low[v] >= disc[u])
				anode[u] = 1;
		}
		else if( parent[u] != v)
		{
			low[u] = min(low[u],disc[v]);  
		}
	}
}
// anode[i] = 1 if , ith node is a cut vertex



