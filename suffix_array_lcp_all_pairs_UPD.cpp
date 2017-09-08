/*
    Suffix Arrays implementation
    O(n log n) - Manber and Myers algorithm
    Refer to "Suffix arrays: A new method for on-line texting searches", by Udi Manber and Gene Myers
 */
class suffixArray
{
public:
    string s;
    int len;
    vector<int> iSA,SA;
    vector<int> cnt,next_gen,lcp;
    vector<vector<int>> LCP;
    vector<bool> bh,b2h,m_arr;
    suffixArray(string sinp)
    {
        s = sinp;
        len = sinp.size();
        iSA.resize(len); SA.resize(len);
        cnt.resize(len); next_gen.resize(len); lcp.resize(len);
        LCP.resize(len);
        bh.resize(len); b2h.resize(len); m_arr.resize(len);
        for(int i = 0; i < len; i++)
            LCP[i].resize(22);
    }
    bool smaller_first_char(int a, int b){
        return s[a] < s[b];
    }
    void SuffixSort() {
        for (int i=0; i<len; ++i){
            SA[i] = i;
        }
        vector<pair<char,int> > arrr;
        for(int i = 0; i < len; i++)
            arrr.pb({s[SA[i]],SA[i]});
        sort(arrr.begin(),arrr.end());
        for(int i = 0; i < len; i++)
            SA[i] = arrr[i].ss;

        for (int i=0; i<len; ++i){
            bh[i] = i == 0 || s[SA[i]] != s[SA[i-1]];
            b2h[i] = false;
        }
        for (int h = 1; h < len; h <<= 1){
            int buckets = 0;
            for (int i=0, j; i < len; i = j){
                j = i + 1;
                while (j < len && !bh[j]) j++;
                next_gen[i] = j;
                buckets++;
            }
            if (buckets == len) break;
            for (int i = 0; i < len; i = next_gen[i]){
                cnt[i] = 0;
                for (int j = i; j < next_gen[i]; ++j){
                    iSA[SA[j]] = i;
                }
            }
            cnt[iSA[len - h]]++;
            b2h[iSA[len - h]] = true;
            for (int i = 0; i < len; i = next_gen[i]){
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
            for (int i=0; i<len; ++i){
                SA[iSA[i]] = i;
                bh[i] = bh[i] | b2h[i];
            }
        }
        for (int i=0; i<len; ++i){
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
        InitLCP(len);
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
    void PrintSA()
    {
        for(int i = 0; i < len; i++)
            debug4(i,SA[i],iSA[i],lcp[i]);
    }
    /*string inp; cin >> inp;
    suffixArray sa1(inp);
    sa1.SuffixSort();
    sa1.ConstructLCP();*/
// isA[i] : rank array
// SA[i]  : Suffix array
// lcp[i] : lcp array
// GetLCP(i,j): lcp of any 2 suffixes.
};
























