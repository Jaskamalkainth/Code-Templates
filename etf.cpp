
const int maxN = 1e+7;
vi etf , P;
void ETF()
{
    etf.resize(maxN+1);
    P.resize(maxN+1,0);
    for(int i=1;i<=maxN;i++)
        etf[i]=i;
    for(int i=2;i<=maxN;i++)
    {
        if(!P[i])
        {
            etf[i]-=(etf[i]/i);
            int j=2*i;
            while( j <= maxN)
            {
                etf[j]-=(etf[j]/i);
                P[j]=1;
                j+=i;
            }
        }
    }
}


