
/*
 */
const int MAXN = 1e5+7;
string s; 
int len;
int P[MAXN], HashF[MAXN], HashR[MAXN];
class RollingHash {
    public:
        RollingHash() {
            prime = 100001;
            mod1 = 1000000007;
            mod2 = 1897266401;
            P[0] = 1;
            for(int i=1; i<MAXN; i++) {
                P[i] = 1LL * P[i-1] * prime % mod1;
            }
        }

        void Construct() {
            HashF[0] = HashR[ len+1 ] = 0;
            for(int i=1; i<=len; i++) {  // 1 based indexing
                HashF[i] = ( 1LL * HashF[i-1] * prime + s[i-1] ) % mod1;
                HashR[len-i+1] = ( 1LL * HashR[len-i+2] * prime + s[ len - i ] ) % mod1; 
            }
        }

        int GetForwardHash( int l, int r ) {
            if( l == 1 ) return HashF[r];
            int hash = HashF[r] - 1LL * HashF[l-1] * P[ r - l + 1 ] % mod1;
            if( hash < 0 ) hash += mod1;
            return hash;
        }
        int GetBackwardHash( int l, int r ) {
            if( r == len ) return HashR[l];
            int hash = HashR[l] - 1LL * HashR[r+1] * P[ r - l + 1 ] % mod1;
            if( hash < 0 ) hash += mod1;
            return hash;
        }
        bool IsPalin( int l, int r ) {
            if( r < l ) return true;
            return (GetForwardHash(l, r) == GetBackwardHash(l, r));
        }

    private:
        int prime, mod1, mod2;
};
//	RollingHash obj;
//	obj.Construct();

