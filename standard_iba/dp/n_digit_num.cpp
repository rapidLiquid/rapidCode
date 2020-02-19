

/*Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.*/



int _go(int n, int S, vector<vector<int> >& dp) {
    if(n == 0&&S==0) return 1;
    if(n==0) return 0;
    if(S<0) return 0;

    if(dp[n][S]!=-1) return dp[n][S];
    int tot=0;
    const int mod = 1000000007;
    for(int d = 0; d < 10; ++d) {
        if(d==0 && n == 1) continue;
        tot += _go(n-1,S-d,dp);
        tot %= mod;
    }
    return dp[n][S]=tot;
}

int Solution::solve(int A, int B) {
    vector<vector<int> >dp(A+1,vector<int> (B+1,-1));
    return _go(A,B,dp);
}

