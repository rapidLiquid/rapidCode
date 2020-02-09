

int solve(const string& A, const string& B, int i, int j, int n, int m, vector<vector<int> >& dp) {
    // if(i == n && j == m) return 0;
    if(i == n){
        return m-j;
    }
    if(j == m) {
        return n-i;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    // int tt;
    if(A[i] == B[j]) {
        dp[i][j] = solve(A,B,i+1,j+1,n,m,dp);
    }
    else {
        int x = 1 + solve(A,B,i+1,j+1,n,m,dp);//insert or replace
        int y = min(1 + solve(A,B,i+1,j,n,m,dp) , 1 + solve(A,B,i,j+1,n,m,dp));//delete either
        // int z = 1 + solve();
        dp[i][j] = min(x, y);
    }
    return dp[i][j];
}


int doBU(const string& A, const string& B) {
    int n = A.length();
    int m = B.length();
    vector<vector<int> > dp(n, vector<int>(m,0));
    /*
    clearly if i and j are equal then no problem
    
    dp[i][j] = dp[i-1][j-1]; //same so no op required if they are equal
    dp[i][j] = 1 + dp[i-1][j-1] // replace
    dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]) // delete
    dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]) // insert

    */
    
    
    //base cases
    dp[0][0] = A[0] == B[0] ? 0 : 1;
    for(int i = 1; i < m; ++i) {
        // dp[0][i] = A[0] == B[i] ? i : i+1;
        if(A[0] == B[i]) {
            dp[0][i] = i;
        } else {
            //delete
            dp[0][i] = 1 + dp[0][i-1];
            //replace - the current and remove the rest
            dp[0][i] = min(dp[0][i], i+1);
            //insert same as delete
            // dp[0][i] = min();
        }
    }
    for(int i = 1; i < n; ++i) {
        if(A[i] == B[0]) {
            dp[i][0] = i;
        } else {
            dp[i][0] = 1 + dp[i-1][0];
            dp[i][0] = min(dp[i][0],i+1);
        }
    }
    
    //
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(A[i] == B[j]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
            }
        }
    }

    return dp[n-1][m-1];
}

int Solution::minDistance(string A, string B) {
    // vector<vector<int> >dp((int)A.length(), vector<int>((int)B.length(), -1));
    // return solve(A,B,0,0,(int)A.length(), (int)B.length(), dp);
    return doBU(A,B);
}

