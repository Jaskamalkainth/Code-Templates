/*
 * O<nlogn,logn>
 */
const int MAXN = 1e6+7; 
const int MAXLOG = 20; 
int par[MAXN][MAXLOG]; 
vector<int> G[MAXN];
int depth[MAXN];

void dfs_lca(int v,int p = -1)
{
    par[v][0] = p;
    if(p + 1)
        depth[v] = depth[p] + 1;
    for(int i = 1;i < MAXLOG;i ++)
        if(par[v][i-1] + 1)
            par[v][i] = par[par[v][i-1]][i-1];
    for(auto u : G[v])
        if(p - u)
            dfs_lca(u,v);
}
inline int lca(int v,int u)
{
    if(depth[v] < depth[u])
        swap(v,u);
    for(int i = MAXLOG - 1;i >= 0; i--)
        if(par[v][i] + 1 and depth[par[v][i]] >= depth[u])
            v = par[v][i];
    if(v == u)
        return v;
    for(int i = MAXLOG - 1;i >= 0; i--)
        if(par[v][i] - par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}
inline int dist(int u , int  v)
{
    int l = lca( u , v);
    return ( depth[u] + depth[v] - 2 * depth[l] );
}
inline int kth(int u , int k)
{
	if(k > depth[u])  
		return -1;
	for(int i = MAXLOG-1; i >= 0; i--)
		if((1 << i) & k)
			u = par[u][i];
	return u;
}


