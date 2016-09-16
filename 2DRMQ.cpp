/*
 * Max 2D RMQ 
 * O(nmlognlogm,1)
 */
const ll  OO = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1e3+7;
const int maxm = 1e3+7;
const int maxlog = 15;
int inp[maxn][maxm]; 
int n , m;
int lg[maxn] , p2[maxn];
int table[maxlog][maxlog][maxn][maxm];


inline void BUILD_twoDimension_RMQ()
{
	// table[jr][ir][jc][ic] contains the minimum element from column ic -> ic + 2^jc - 1 of all rows [ir,ir+2^jr-1]
	 
	for(int i = 2; i < maxn; i++)
		lg[i] = lg[i/2] + 1;
	for(int i = 0; i < maxn; i++)
		p2[i] = (1<<i);

	for(int ir = 0; ir < n; ir++)
		for(int ic = 0; ic < m; ic++)
			table[0][0][ir][ic] = inp[ir][ic];
	// jr = 0 so 1D RMQ for every row.
	for(int ir = 0; ir < n; ir++)
		for(int jc = 1; jc <= lg[m]; jc++)
			for(int ic = 0; ic + (1 << (jc-1)) < m; ic++)
				table[0][jc][ir][ic] = max(table[0][jc-1][ir][ic] , table[0][jc-1][ir][ic + p2[jc-1]]);  
	
	for(int jr = 1; jr <= lg[n]; jr++)
		for(int ir = 0; ir < n; ir++)
			for(int jc = 0; jc <= lg[m]; jc++)
				for(int ic = 0; ic < m; ic++)
					table[jr][jc][ir][ic] = max(table[jr-1][jc][ir][ic] , table[jr-1][jc][ir+ p2[jr-1]][ic]);  
}

inline int QUERY_twoDimension_RMQ(int x1,int y1 , int x2 , int y2)
{
	int lenx = x2-x1+1;
	int leny = y2-y1+1;
	int kx = lg[lenx];
	int ky = lg[leny];
	// Range R1 [x1,x1+2^kx-1] 
	// Range R2 [x2-2^kx+1,x2]
	// may overlap but since we  need min its fine.
	int min_Range1 = max(table[kx][ky][x1][y1] , table[kx][ky][x1][y2+1-p2[ky]]);
	int min_Range2 = max(table[kx][ky][x2+1-p2[kx]][y1] , table[kx][ky][x2+1-p2[kx]][y2+1-p2[ky]]);

	return max(min_Range1,min_Range2);
}
/*
 * int n , m; rows and col declared globally
 * int inp[n][m]  declated globally
 * QUERY_twoDimension_RMQ() tells you the maximum of a rectangle whose lefttop point (x1,y1) and rightbottom point (x2,y2).
 */
