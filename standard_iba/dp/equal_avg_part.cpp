typedef std::vector<bool> vi;
 
std::vector<int>  _solve(std::vector<int>& A){

    sort(A.rbegin(),A.rend()); //WHY?? THINK
	int n = (int)A.size(); int S = 0;
	for(int i : A) S += i;

	vector<vector<vi> > dp(n+1, vector<vi> ( n+1, vi (S+1, false) ) );
	/*
	    dp[i][j][k]
	    
	    is it possible to make a    sum k
	    using only                  j number of elements
	    considering onLy the        first i elements
	*/

	dp[0][0][0] = 1;
	for(int i = 0; i < n+1; ++i)
		for(int j = 0; j <=i; ++j)dp[i][j][0]=1;
	// it is always possible to make a sum 0 using any number of elements

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			for(int k = 0; k <= S; ++k) {
				dp[i][j][k] = dp[i-1][j][k];
				if(A[i-1]<=k)
					dp[i][j][k] = dp[i][j][k] || dp[i-1][j-1][k-A[i-1]];
			}
		}
	}

	int till=-1, sum=-1, tot = -1;
	for(int k = 1; k <= S; ++k) {
		for(int i = 0; i < n + 1; ++i) {
			for(int j =  0; j < i + 1; ++j) {
				// if(till != -1)continue;
				if(dp[i][j][k] && k*n == j*S) {
				    if(tot == -1) { till = i; sum = k; tot = j; }
				    else if(j <= tot) { till = i; sum = k; tot = j; }
				}
			}
		}
	}
	//select the first set which satisfies the condition

	if(tot == n && till == n && sum == S) return vector<int> ({-1});

	std::vector<int> v;
	while(till>0 && tot>0 && sum>=0) {
		// cout << "tot till sum " << tot << " " << till << " " << sum << endl;
        // enable this to see backtracking
		if(sum >= A[till-1] && dp[till-1][tot-1][sum-A[till-1]]) {
			v.push_back(A[till-1]);
			tot--;till--;sum-=A[till];
			continue;
		}
		till--;
	}
	sort(v.begin(),v.end());
	return v;


}

vector<vector<int> > Solution::avgset(vector<int> &A) {

    vector<int> v1 = _solve(A); sort(v1.begin(), v1.end());
    if(v1[0]==-1) {
        vector<vector<int>>ans;
        return ans;
    }
    map<int,int> S;
    for(int i : A) S[i]++;
    for(int i : v1) S[i]--;
    vector<int> v2;
    for(auto i : S) {
        for(int j = 0; j < i.second; ++j) v2.push_back(i.first);
    }

    if((int)v1.size() == (int)v2.size()) {
        int flag = 1;
        // flag=1 denotes that v1 is lexi smaller than v2
        for(int i = 0; i < (int)v1.size(); ++i) {
            if(v1[i] == v2[i]) continue;
            else if(v1[i] > v2[i]) {
                flag = 0;
                break;
            }
        }
        if(flag) swap(v1,v2);
    }
    vector<vector<int> > ans;
    ans.push_back(v1); ans.push_back(v2);
    return ans;
}

