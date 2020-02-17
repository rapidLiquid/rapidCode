
int _solve(string A) {
    int n = A.length();
    vector<vector<int>> dp(26, vector<int> (n,0));
    const int mod = 1e9+7;
    vector<int> _last(26,-1);


    
    for(int i = 0; i < n; ++i) {
        char c = A[i];
        int last = _last[c-'a'];
        
        vector<int> extra;
        for(int j = 1+last; j <= i; ++j) {
            if(j == 0) { extra.push_back(1); }
            else {
                int tmp = 0;
                for(char x = 'a'; x <= 'z'; ++x) {
                    // if(x == c) continue;
                    tmp += dp[x-'a'][j-1];
                    tmp %= mod;
                }
                int z = extra.empty() ? 0 : extra.back();
                extra.push_back( ( tmp  )%mod );
                // dp[c-'a'][j] += tmp;
                // dp[c-'a'][j] %= mod;
            }
        }
        for(int j = 1+last; j <= i; ++j) dp[c-'a'][j] = (dp[c-'a'][j]+extra[j-last-1])%mod;
        _last[c-'a'] = i;
        
        
        
         for(int i = 0; i < n ;++i) {
            for(char c = 'a'; c <= 'c'; ++c)cout << c << "-"<<dp[c-'a'][i] << "  ";
            cout << endl;
        }
        cout << endl;
        //  for(char c = 'a'; c <= 'c'; ++c)cout << c << "-"<<dp[c-'a'][i] << "  ";
        // cout << endl;
        cout <<endl;
        
    }
    
    
    
    // for(int i = 0; i < n ;++i) {
    //     for(char c = 'a'; c <= 'c'; ++c)cout << c << "-"<<dp[c-'a'][i] << "  ";
    //     cout << endl;
    // }
    
    
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(char c = 'a'; c <= 'z'; ++c) ans = (ans + dp[c-'a'][i])%mod;
    return ans;
    
}

//TODO
// int solve3(string A ) {
//     vector<int> dp(26,0);
//     for(int i = 0; i < n; ++i) {
//         for(char c = 'a'; c <= 'z'; ++c) {
//             tmp += dp[c-'a'];
//         }
//     }
// }

int solve2(string A) {
    int n = A.length();
    vector<int> last(26,-1);
    vector<int> dp(n+1,0);
    const int mod = 1e9+7;
    dp[0]=1; //last[A[0]-'a'] = 0;
    for(int i  = 1; i <= n; ++i) {
        char c = A[i-1];
        int rep = last[c-'a'] == -1 ? 0 : dp[last[c-'a']];
        if(i>0) dp[i] = dp[i-1]*2 - rep;
        dp[i] %= mod; dp[i] += mod; dp[i] %= mod;
        last[c-'a'] = i-1;
    }
    dp[n]--; dp[n] += mod; dp[n]%=mod; // excluding nil subsequence
    return dp[n];
}


int Solution::solve(string A) {

    // return _solve(A);
    cout << _solve(A) << " " << solve2(A) << endl;
    return solve2(A);

}

