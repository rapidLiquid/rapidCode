// longest palindromic subsequence
//
int Solution::solve(string A) {
    string B = A;
    int n = A.length();
    reverse(B.begin(), B.end());
    
    vector<vector<int> > dp(n, vector<int>(n,0));
    
    // find LCS between the two ?? why
    // try to think of the base case from general cases
    if(A[0]==B[0])dp[0][0]=1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i==0&&j==0)continue;
            if(i == 0) {
                if(A[i] == B[j]) dp[i][j]=1;
                else if(j > 0)dp[i][j] = dp[i][j-1];
                continue;
            }
            if(j == 0) {
                if(A[i] == B[j]) dp[i][j]=1;
                else if(i > 0)dp[i][j] = dp[i-1][j];
                continue;
            }
            if(A[i] == B[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n-1][n-1];
    
}

