/*
 *
 * DSU Union by rank and path compression
 * 
 * O(a(n)) almost constant
 */

int int maxn = 1e5+7;
int rankN[maxn];
int parentN[maxn];
int n; // number of nodes
inline void make_set()
{
	for(int i = 0; i < n; i++)
		parentN[i] = rankN[i] = i;  
}
inline int find_set(int u)
{
	if(parentN[u] != u )
		parentN[u] = find_set(parentN[u]);
	return parentN[u];
}
inline void union_set(int u,int v)
{
	int pu = find_set(u);
	int pv = find_set(v);
	if(pu == pv)
		return ;
	if(rankN[pu] > rankN[pv])
	{
		parentN[pv] = pu;  
	}
	else
	{
		parentN[pu] = pv;
		if(rankN[pu] == rankN[pv])
			rankN[pv]++;
	}
}

