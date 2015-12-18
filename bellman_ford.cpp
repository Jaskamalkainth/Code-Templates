/*
 * O(VE)
 *
 */
vector<int> d ;
struct edge
{
	int a , b ,cost;  
};
vector<edge> e; 
bool neg_cycle = false;
void bellman_ford(int source , int n , int m )
{
	d.resize(n,mx_int);
	d[source] = 0;

	vector<int> p (n, -1);
	int x;
	for (int i=0; i<n; ++i) {
		x = -1;
		for (int j=0; j<m; ++j)
			if (d[e[j].a] < mx_int)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = max (-mx_int, d[e[j].a] + e[j].cost);
					p[e[j].b] = e[j].a;
					x = e[j].b;
				}
	}

	if (x == -1)
	//	cout << "No negative cycle from " << v;
	else {
		neg_cycle = true;
		int y = x;
		for (int i=0; i<n; ++i)
			y = p[y];

		vector<int> path;
		for (int cur=y; ; cur=p[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)  break;
		}
		reverse (path.begin(), path.end());

	//	cout << "Negative cycle: ";
	//	for (size_t i=0; i<path.size(); ++i)
	//		cout << path[i] << ' ';
	}
}

