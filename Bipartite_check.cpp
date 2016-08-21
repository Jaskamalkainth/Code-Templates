/*
 * O(n)
 * Bipartite check
 */
const int maxN = 1e5+7;
vector<int> G[maxN];
int num_vertices;
int vis[maxN];
int color[maxN];
vector<int> red,blue;
#define RED 1
#define BLUE 2
bool check_Bipartite_flag = true;

inline void dfs(int u, int c)
{
	color[u] = c;
	vis[u] = 1;
	if(c == RED)
		red.push_back(u);
	else
		blue.push_back(u);
	for(auto &v: G[u])
	{
		if(!vis[v])
			dfs(v,(c==RED)?BLUE:RED);
		if(c == color[v])
			check_Bipartite_flag = false;
	}
}
inline bool isBipartite()
{
	for(int i = 1; i <= num_vertices; i++)
		if(!vis[i])
			dfs(i,RED);
	if(check_Bipartite_flag)
		return 1;
	else
		return 0;
	//vi red, blue contains 2 set of vertices
}



