

int solve(const string& A, const string& B, int i, int j, int n, int m,vector<vector<int> >& dp) {
    
    if(i == n && j == m) return 1;
    if(i == n) {
        if(B[j] == '*')return solve(A,B,i,j+1,n,m,dp);
        else return 0;
    }
    if(j == m) return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    
    if(A[i] == B[j] || B[j] == '?') {
        // cout << A[i] << " ij " << B[j] << endl;
        return dp[i][j]=solve(A,B,i+1,j+1,n,m,dp);
    } 
    
    if(B[j] == '*') {
        int x = solve(A,B,i+1,j,n,m,dp);
        int y = solve(A,B,i+1,j+1,n,m,dp);
        int z = solve(A,B,i,j+1,n,m,dp);
        return dp[i][j]=(x || y || z);
    }
    else return dp[i][j]= 0;
}


int Solution::isMatch(const string A, const string B) {
    int n = (int)A.length(), m = (int)B.length();
    vector<vector<int> >dp(n,vector<int>(m,-1));
    return solve(A,B,0,0,n,m,dp);
}
// THIS is MLE, how to preserve mem
// maybe use stack
