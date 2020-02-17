bool _go(const string& s, const string& p, int i, int j, map<pair<int,int>,bool>& dp) {
        
    if(i == s.length() && j == p.length()) return true;
    if(j == p.length()) return false;
    if(i == s.length()) {
        if(p[j] == '*') return _go(s,p,i,j+1,dp);
        else return false;
        // ----b ----b*  should give tru
    }
    
    // int& X = dp[i][j];
    if(dp.find({i,j})!=dp.end())return dp[{i,j}];
    
    if(s[i] == p[j] || p[j] == '?') {//cout << "ij " << i << " " << j << endl;
    return dp[{i,j}]=_go(s,p,i+1,j+1,dp);
}
    if(p[j] == '*') {
        bool x = _go(s,p,i+1,j,dp); //match more
        bool y = _go(s,p,i+1,j+1,dp); // match the one 
        bool z = _go(s,p,i,j+1,dp); // match blank
        return dp[{i,j}]=x||y||z;
    }

    return dp[{i,j}]=false;
    
}
int Solution::isMatch(const string A, const string B) {
    string Bb = "";
    for(char x : B) if(x == '*') {
        if(Bb!="" && Bb[Bb.length()-1]=='*') continue;
        Bb+=x;
    } else Bb+=x;
    // vector<vector<int> > dp(A.length(), vector<int> (Bb.length(), -1));
    map<pair<int,int>,bool> dp;
    return _go(A,Bb,0,0,dp);
}

// MLE error
// optimisation idea is to see that we dont process suffixes that are not needed
// also instead of vector, map usage is better to store the minimal possible indexes pair
