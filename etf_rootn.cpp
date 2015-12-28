/*
 * Euler Totient function
 *
 * O(roo(n)) complexity
 *
 */
int phi(int n)
{
    int i,res=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            res-=res/i;
        while(n%i == 0)
            n/=i;
    }
    if(n>1)
        res-=res/n;
    return res;
}
