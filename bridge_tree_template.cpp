/*
 *
 * Bridge tree.
 * using DSU ( union by rank and path compression )
 * mark all the bridges first then do DSU .
 */
const int maxn = 3e5+7;
int n; // number of nodes

vector<int> G[maxn];
int low[maxn], disc[maxn] , parent[maxn] , vis[maxn];
vector<pair<int,int> > bedge; // all bridge edges 
int timer;
vector<int> Btree[maxn]; 

/******** DSU part *********/
int rankN[maxn];
int parentN[maxn];
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
/* */
/********* Bridge tree ********/
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
/* Mark all the bridges */
inline void mark_bridges(int u)
{
	vis[u] = 1;
	disc[u] = low[u] = timer++;
	for(int &v: G[u])
	{
		if(!vis[v])
		{
			parent[v] = u;
			mark_bridges(v);
			low[u] = min(low[u],low[v]);
			if(low[v] > disc[u])
			{
				// u-v is a bridge edge
				bedge.push_back(mp(u,v));
			}
			else
			{
				union_set(u,v);
			}
		}
		else if(parent[u] != v)
		{
			low[u] = min(low[u],disc[v]);
		}
	}
}
inline void make_tree()
{
	make_set();
	clear();
	mark_bridges(0); // mark all the bridges
	for(auto &i: bedge) // atmose n-1 bridge edges.
	{
		int pu = find_set(i.ff);
		int pv = find_set(i.ss);
		if(pu != pv)
		{
			Btree[pu].push_back(pv);
			Btree[pv].push_back(pu);
		}
	}
}
/**** Bridge tree Ends ****/

