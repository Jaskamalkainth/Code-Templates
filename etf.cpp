const int maxN = 1e6+7;
vi etf , P;
inline void ETF()
{
    etf.resize(maxN+1);
    P.resize(maxN+1,0);
    for(int i = 1;i <= maxN; i++)
        etf[i] = i;
    for(int i = 2;i <= maxN; i++)
    {
        if (!P[i]) {
            etf[i] -= (etf[i]/i);
			for(int j = 2*i; j < maxN; j += i)
            {
                etf[j] -= (etf[j]/i);
                P[j] = 1;
            }
        }
    }
}


