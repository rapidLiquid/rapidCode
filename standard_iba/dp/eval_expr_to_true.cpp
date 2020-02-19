

/*
 * Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 1e3 + 3
 *
 * */




/*
 *this kind of approach is miexed dp approach
 * similar in burst balloon, matrix mult, stones etc etc
 *
 *
 * */



bool _sign(char x) {
    return x == '|' || x == '&' || x == '^';
}
typedef vector<int> vi;
int _go(string A, int i, int j, int v, vector<vector<vi>>& dp) {
    // v can be 1 for true and 0 for false
    if(i == j) return A[i] == 'T' ? (v == 1 ? 1 : 0) : (v == 0 ? 1 : 0);
    if(dp[i][j][v]!=-1) return dp[i][j][v];
    int tot = 0;
    const int mod = 1e3+3;
    for(int k = i; k <= j; ++k) {
        if(_sign(A[k])) {
            if(A[k] == '|') {
                if(v) {
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,0,dp);
                    tot %= mod;
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,1,dp);
                    tot %= mod;
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,1,dp);
                    tot %= mod;
                } else {
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,0,dp);
                }
            } else if(A[k] == '&') {
                if(v == 1)
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,1,dp);
                else {
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,0,dp);
                    tot %= mod;
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,1,dp);
                    tot %= mod;
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,0,dp);
                    tot %= mod;
                }
            } else if(A[k] == '^') {
                if(v==1){
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,1,dp);
                    tot%=mod;
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,0,dp);
                    tot%=mod;
                } else {
                    tot += _go(A,i,k-1,0,dp) * _go(A,k+1,j,0,dp);
                    tot%=mod;
                    tot += _go(A,i,k-1,1,dp) * _go(A,k+1,j,1,dp);
                    tot%=mod;
                }
            }
        }
    }
    return dp[i][j][v]=tot%=mod;;
    
}



int Solution::cnttrue(string A) {
    int n = A.length();
    
    vector< vector < vi > >  dp(n+1,
        vector<vi> (n+1, vi(2,-1))
        );
    return _go(A,0,n-1,1,dp);
}

