class RollingHash_double
{
public:
    static const int nine_len = 1e9+1;
    vector<int> P0,P1;
    long long prime[2],mod[2];
    vector< pair<int,int>> HashF, HashR;
    string s;
    int len;
    int check_prime(ll n)
    {
        int flag = 0;
        for(int i = 2; i * i < n; i++)
            if(n % i == 0)
                flag = 1;
        if(flag)
            return 0;
        else
            return 1;
    }
    RollingHash_double(string sinp)
    {
        s = sinp;
        len = sinp.size();
        HashR.resize(len+2);
        HashF.resize(len+2);
        P0.resize(len+2);
        P1.resize(len+2);
        prime[0] = 31;
        prime[1] = 37;
        /*long long rand_mod1 = nine_len + rand() % nine_len;
        long long rand_mod2 = nine_len + rand() % nine_len;
        while(!check_prime(rand_mod1))
            rand_mod1++;
        while(!check_prime(rand_mod2))
            rand_mod2++;
        while(rand_mod1 == rand_mod2)
        {
            rand_mod1++;
            while(!check_prime(rand_mod1))
                rand_mod1++;
        }
        mod[0] = rand_mod1;
        mod[1] = rand_mod2;*/
        mod[0] = 1000016863;
        mod[1] = 1282475263;
        P0[0] = P1[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            P0[i] = (1ll * P0[i-1] * prime[0]) % mod[0];
            P1[i] = (1ll * P1[i-1] * prime[1]) % mod[1];
        }
        Construct();
    }
    void Construct()
    {
        HashF[0] = HashR[len+1] = {0,0};
        for(int i = 1; i <= len; i++)
        {
            HashF[i].first = (1ll * HashF[i-1].first * prime[0] + s[i-1] ) % mod[0];
            HashF[i].second = (1ll * HashF[i-1].second * prime[1] + s[i-1] ) % mod[1];

            HashR[len-i+1].first = (1ll * HashR[len-i+2].first * prime[0] + s[len-i] ) % mod[0];
            HashR[len-i+1].second = (1ll * HashR[len-i+2].second * prime[1] + s[len-i]) % mod[1];
        }
    }
    pair<int,int> GetHashValue()
    {
        return {HashF[len].first,HashF[len].second};
    }
    pair<int,int> GetForwardHash(int l ,int r)
    {
        if(l == 1)
            return HashF[r];
        pair<int,int> hashp;

        hashp.first = (HashF[r].first - 1ll * HashF[l-1].first * P0[r-l+1] ) % mod[0];
        if(hashp.first < 0)
            hashp.first += mod[0];

        hashp.second = (HashF[r].second- 1ll * HashF[l-1].second * P1[r-l+1] ) % mod[1];
        if(hashp.second < 0)
            hashp.second += mod[1];
        return hashp;
    }

    pair<int,int> GetReverseHash(int l ,int r)
    {
        if(r == len)
            return HashR[l];
        pair<int,int> hashp;
        hashp.first= (HashR[l].first - 1ll * HashR[r+1].first* P0[r-l+1]) % mod[0];
        if(hashp.first< 0)
            hashp.first+= mod[0];
        hashp.second= (HashR[l].second- 1ll * HashR[r+1].second * P1[r-l+1] ) % mod[1];
        if(hashp.second < 0)
            hashp.second += mod[1];
        return hashp;
    }

    bool IsPalin(int l , int r)
    {
        if( r < l ) return true;
        return (GetForwardHash(l,r) == GetReverseHash(l,r));
    }
};