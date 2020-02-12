/*
 * Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

 * Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*/






int Solution::numDistinct(string A, string B) {
    // dp i,j -> number of ways to make sequence till j in B using til i in A
    int n = A.length(); int m = B.length();
    vector<vector<int> > dp(n, vector<int> (m, 0));

    // dp[i,j] = dp[i-1, j] + (A[i] == B[j] ? dp[i-1,j-1] : 0) // recursive case now think base case

    for(int i = 0; i < n; ++i) {
        if(A[i] == B[0]) dp[i][0] = 1;
        if(i > 0) dp[i][0] += dp[i-1][0];
    }

    // for(int i = 0; i < m; ++i) {
    //     if(B[i] == A[0]) dp[0][i] = 1;
    //     else if(i > 0) dp[0][i] += dp[0][i-1];
    // } // this doesn't work why becoz length is fixed -> 1 of the second string


    for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
            dp[i][j] = dp[i-1][j] + (A[i] == B[j] ? dp[i-1][j-1] : 0);


    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < m; ++j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[n-1][m-1];
}

