#define matrix vector< vector<ll> >

matrix matmul(matrix &a, matrix &b)
{
    int n = a.size();
    matrix ans (n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++)
		{
            ll temp = 0;
            for(int k = 0; k < n;k++)  
				temp = (temp + a[i][k] * b[k][j]) % mod;
            ans[i][j] = temp;
        }

    return ans;
}
matrix matpwr(matrix &a, ll p){
    int n = a.size();
    matrix ans(n, vector<ll> (n));
    for(int i = 0;i < n; i++)    
		ans[i][i] = 1;
    while(p)
	{
        if(p&1) 
			ans = matmul(ans, a);
        a = matmul(a, a);
        p >>= 1;
    }
    return ans;
}
/*
	matrix a = {{1,1},{1,0}};
	matrix mm = matpwr(a,n);
	*/

