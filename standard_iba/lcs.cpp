int Solution::solve(string A, string B) {
    int n = A.length();
    int m = B.length();
    
    vector<vector<int> > dp(n, vector<int>(m,0));
    // dp[0][0] = A[0] == B[0] ? 1 : 0;
    for(int i = 0; i < n; ++i) {
        dp[i][0] = A[i] == B[0] ? 1 : 0;
        if(i > 0) dp[i][0] = max(dp[i-1][0], dp[i][0]);
    }
    
    for(int i = 0; i < m; ++i) {
        dp[0][i] = A[0] == B[i] ? 1 : 0;
        if(i > 0) dp[0][i] = max(dp[0][i-1], dp[0][i]);
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            int z=0;
            if(A[i]==B[j]) z=1+dp[i-1][j-1];
            dp[i][j] = max(z, max(dp[i-1][j], dp[i][j-1]));
        }
    }
    
    // for(int i = 0; i < n; ++i) {
    //     cout << A[i] << " -> ";
    //     for(int j = 0; j < m; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
    return dp[n-1][m-1];
    
    
    
    
    
}

