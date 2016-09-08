const int MAXN = 1e5+6;
/*
 * Suffix Array
 */
// isA[i] : rank array
// SA[i]  : Suffix array
// lcp[i] : lcp array
// GetLCP(i,j): lcp of any 2 suffixes.
string s;
int len;
int iSA[MAXN], SA[MAXN];
int cnt[MAXN], next_gen[MAXN], lcp[ MAXN ], LCP[MAXN][22]; //internal
bool bh[MAXN], b2h[MAXN],m_arr[MAXN];

inline void init_SA()
{
	for(int i = 0; i < MAXN; i++)
	{
		iSA[i] = SA[i] = cnt[i] = next_gen[i] = lcp[i] = 0;
		bh[i] = b2h[i] = m_arr[i] = 0;
		for(int j = 0; j < 22; j++)
			LCP[i][j] = 0;
	}
}

bool smaller_first_char(int a, int b){
	return s[a] < s[b];
}

void SuffixSort(int n) {
	for (int i=0; i<n; ++i){
		SA[i] = i;
	}
	sort(SA, SA + n, smaller_first_char);
	for (int i=0; i<n; ++i){
		bh[i] = i == 0 || s[SA[i]] != s[SA[i-1]];
		b2h[i] = false;
	}
	for (int h = 1; h < n; h <<= 1){
		int buckets = 0;
		for (int i=0, j; i < n; i = j){
			j = i + 1;
			while (j < n && !bh[j]) j++;
			next_gen[i] = j;
			buckets++;
		}
		if (buckets == n) break;
		for (int i = 0; i < n; i = next_gen[i]){
			cnt[i] = 0;
			for (int j = i; j < next_gen[i]; ++j){
				iSA[SA[j]] = i;
			}
		}
		cnt[iSA[n - h]]++;
		b2h[iSA[n - h]] = true;
		for (int i = 0; i < n; i = next_gen[i]){
			for (int j = i; j < next_gen[i]; ++j){
				int s = SA[j] - h;
				if (s >= 0){
					int head = iSA[s];
					iSA[s] = head + cnt[head]++;
					b2h[iSA[s]] = true;
				}
			}
			for (int j = i; j < next_gen[i]; ++j){
				int s = SA[j] - h;
				if (s >= 0 && b2h[iSA[s]]){
					for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i=0; i<n; ++i){
			SA[iSA[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i=0; i<n; ++i){
		iSA[SA[i]] = i;
	}
}

void InitLCP(int n) {
	for (int i=0; i<n; ++i) 
		iSA[SA[i]] = i;
	lcp[0] = 0;
	for (int i=0, h=0; i<n; ++i) {
		if (iSA[i] > 0) {
			int j = SA[iSA[i]-1];
			while (i + h < n && j + h < n && s[i+h] == s[j+h]) 
				h++;
			lcp[iSA[i]] = h;
			if (h > 0) 
				h--;
		}
	}
}

void ConstructLCP() {
	InitLCP( len );
	for(int i = 0;i<len;++i)
		LCP[i][0] = lcp[i];
	for(int j = 1;(1<<j)<=len;++j){
		for(int i = 0;i+(1<<j)-1<len;++i){
			if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
				LCP[i][j] = LCP[i][j-1];
			else
				LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
		}
	}
}

int GetLCP(int x, int y) {
	if(x == y) return len-SA[x];
	if(x > y) swap(x,y);
	int log = 0;
	while((1<<log)<=(y-x)) ++log;
	--log;
	return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
}
/*
 * SA END/
 *
 */
//	SuffixSort(len);
//	ConstructLCP();
//	string s, int len; defined globally on top

