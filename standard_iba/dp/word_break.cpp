
// given words in a dictionary, need to find whether the complete sentence can be formed or not

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.length();
    set<string>S(B.begin(),B.end());
    vector<bool> dp(n,false);
    for(int i = 0; i < n; ++i) {
        string tmp = "";
        for(int j = i; j >= max(0,i-20); --j) { // optimisation , because given that dict words have mx len as 20
            tmp += A[j];
            
            reverse(tmp.begin(),tmp.end());
            if(S.find(tmp)!=S.end()) {
                bool x = j>0?dp[j-1]:true;
                dp[i] =dp[i] || x;
            }
            reverse(tmp.begin(),tmp.end()); // needed to append in correct order
        }
    }
    return dp[n-1];
    
}
