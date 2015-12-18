
map <ll ,ll > F;
ll f(ll n) 
{
    F[0] = F[1] = 1;
    if (F.count(n))
        return F[n];
    long k=n/2;
    if (n%2==0) 
    { 
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
    } 
    else 
    { 
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
    }
}
// query nth fibonacci number in logn * log(logn) 
// (n == 0 ) ? 0 : f(n-1)


