//Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A
//
//

int _go(int st, int en, vector<vector<int> >& dp) {
    if(st >= en) return 1;
    if(dp[st][en]!=-1) return dp[st][en];
    int ans = 0;
    for(int r = st; r < en + 1; ++r) ans += _go(st,r-1,dp) * _go(r+1,en,dp);
    return dp[st][en]=ans;
}


int Solution::numTrees(int A) {
    vector<vector<int> > dp( A+1, vector<int> (A+1,-1) );
    return _go(1,A,dp);
}
// in range s to e consider some root c , now bst possible will be possible with this root value
