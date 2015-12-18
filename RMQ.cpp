/*
 *
 * Range Minimum Query 
 *
 * Preprocessing O(n * logn ) 
 *
 * Query Time O(1)
 *
 */


const int MAX=1e6+7;
const int LMAX=20;
ll A[MAX];
//const int LMAX=(int)ceil(log(MAX)) = 14 ;
ll M[MAX][LMAX];
void process(int n)
{
    for(int i=0;i<n;i++)
        M[i][0]=i;
    for(int j=1; 1<<j <= n; j++)
        for(int i=0;i+(1<<j) -1 < n;i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int RMQ(int i,int j)
{
    int k=(log2(j-i+1));
    if (A[M[i][k]] <= A[M[j-(1 << k)+1][k]])
        return(M[i][k]);
    else
        return(M[j - (1 << k)+1][k]);
} 
//process(n); //nlogn pre processing
// A[RMQ(x,y)]  min in x and y
