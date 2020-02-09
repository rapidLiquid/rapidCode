

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
        // cout << "called " << i << " " <<j<<endl;
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
    dp[i][j] = dp[i-1][j-1];
    
    dp[i][j] = 1 + dp[i-1][j-1] // replace
    dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]) // delete
    dp[i][j] = 1 + 
    how to handle inserts -> todo
    
    */
}

int Solution::minDistance(string A, string B) {
    // vector<vector<int> >dp((int)A.length(), vector<int>((int)B.length(), -1));
    // return solve(A,B,0,0,(int)A.length(), (int)B.length(), dp);
    return doBU(A,B);
}

