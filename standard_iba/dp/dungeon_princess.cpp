int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = (int)A.size();
    int m = (int)A[0].size();
    vector<vector<int> > dp(n,vector<int> (m,1));
    dp[n-1][m-1] = A[n-1][m-1] >= 0 ? 1 : -A[n-1][m-1] + 1;
    
    for(int i = n-1; i >= 0; --i) {
        for(int j = m-1; j >= 0; --j) {
            if(i == n-1 && j == m-1) continue;
            int hn = INT_MAX;
            int curr = A[i][j];
            if(j < m-1) hn = min(hn, dp[i][j+1]);
            if(i < n-1) hn = min(hn, dp[i+1][j]);
        
            int req = 0;
            curr -= hn;
            req += (curr<0?-curr:1);
            dp[i][j] = req;
        }
    }
    // for(int i = 0 ; i< n;++i){
    //     for(int j = 0; j < m; ++j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[0][0];
}
// the beauty is to start from bottom right becauase that will give a possible optimal soln
// starting from top corner wont give answer
