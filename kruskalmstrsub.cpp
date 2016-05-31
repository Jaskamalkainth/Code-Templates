const int maxN = 1e4+6;
vector<pair<int,pii >  > G, MST;
int parent[maxN];
int n , m;
void printgraph()
{
	for(auto x: G)
		cout << x.ff << "(" << x.ss.ff << "," << x.ss.ss << ")" << "\n";
}

int findset(int x,int *parent)
{
	if(x != parent[x])
		parent[x] = findset(parent[x],parent);
	return parent[x];
}
int kruskal()
{
	for(int i = 1;i <= n; i++)
		parent[i] = i;
	int ans = 0;
	sort(all(G));
	for(auto &x: G)
	{
		int u = x.ss.ff;
		int v = x.ss.ss;
		int pu = findset(u,parent);
		int pv = findset(v,parent);
		if(pu!=pv)
		{
			MST.pb(x);
			ans += x.ff;
			parent[pu] = parent[pv];
		}
	}
	return ans;

}
//			G.pb(pair<int,pii>(wt,mp(u,v)));  

