
/*
Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.
*/

int Solution::minCut(string A) {
    
    
    int n = A.length();
    // is palindrome
    vector<vector<int> > ip(n,vector<int> (n,0));
    
    // min cut till position j where j < n
    for(int k = 1; k <= n; ++k) {
        for(int i = 0; i + k < n + 1; ++i) {
            ip[i][i+k-1] = A[i]==A[i+k-1];
            if(k>2) ip[i][i+k-1] &= ip[i+1][i+k-2];
        }
    }
    const int inf = 1e9;
    vector<int> dp(n,inf);
    for(int i = 0; i < n; ++i) {
        int cost = inf;
        for(int j = 0; j <= i; ++j) {
            if(ip[j][i]) cost = min(cost,(j==0?0:1+dp[j-1]));
        }
        dp[i]=cost;
    }
    return dp[n-1];
}

