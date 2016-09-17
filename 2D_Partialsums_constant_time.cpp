const int maxn = 1e3+7;
int arr[maxn][maxn];
int sum[maxn][maxn];
int n , m;

inline void BUILD_partial_sum()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}
inline int QUERY_partial_sum(int x1, int y1 ,int x2, int y2)
{
	return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];  
}
/*
 * BUILD_partial_sum()
 * QUERY_partial_sum(a,b,c,d) returns sum of sub matrix with lefttop point = [a,b] and righbottom = [c,d]
 * 0-based indexing.
 */

