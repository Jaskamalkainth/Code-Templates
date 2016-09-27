/*
 *
 * all toposorts recursiong + backtracking
 *
 */
const int maxn  =1e5+7;
vi G[maxn];
int indegree[maxn];
int n , m; 
inline void all_topo_sorts(vector<int> res,int vis[maxn])
{
	int flag = 0;
	for(int i = 1; i <= n; i++)
	{
		if(indegree[i] == 0 && !vis[i])
		{
			res.push_back(i);
			for(auto &v: G[i])
				indegree[v]--;
			vis[i] = 1;
			all_topo_sorts(res,vis);

			res.pop_back();
			for(auto &v: G[i])
				indegree[v]++;
			vis[i] = 0;
			flag = 1;
		}
	}
	if(!flag)
		cout << res << "\n";
}
/*
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u , v; cin >> u >> v;
		G[u].pb(v);
		indegree[v]++;
	}
	vi res;
	int vis[maxn];
	m0(vis);
	all_topo_sorts(res,vis);
*/


