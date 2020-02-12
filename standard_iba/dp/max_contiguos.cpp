
// kadane algo without too much variable overhead
// concept is simple best_till_here = max(best_till_prev + curr , curr);


int Solution::maxSubArray(const vector<int> &A) {
    // int z= *max_element(A.begin(), A.end());
    // if(z <= 0 return z;
    int n = (int)A.size();
    vector<int> dp(n,0);
    
    dp[0] = A[0];
    for(int i = 1;i < n; ++i) {
        dp[i] = A[i];
        if(i>0)dp[i] = max(dp[i], dp[i-1]+A[i]);
    }
    return *max_element(dp.begin(), dp.end());
    
    
}

