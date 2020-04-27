#include <bits/stdc++.h>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define pb push_back
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;

typedef pair< LL, LL> ll;
typedef vector< LL> vl;
typedef vector< ll> vll;
typedef vector< vl> vvl;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

std::vector<string> dmap({"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"});

int can(int d, string& s) {
	// min sticks to turn on for getting d
	string s2 = dmap[d];
	int cnt = 0;
	fr(i,0,7) {
		if(s2[i]=='1' && s[i]=='0') ++cnt;
		else if(s2[i]=='0' && s[i]=='1') return -1;
	}
	return cnt;

}
int n;
vi sol;
int solve(int idx, int k, vvi& poss, vvi& dp) {

	if(idx == n && k == 0) return 1;
	else if(idx == n) return 0;
	if(dp[idx][k]!=-1)return dp[idx][k];
	for(int d = 9; d >= 0; --d) {
		if(poss[idx][d] > -1 && poss[idx][d]<=k) {
			sol[idx]=d;
			int x = solve(idx+1,k-poss[idx][d],poss,dp);
			if(x) return dp[idx][k] = 1;
			sol[idx]=-1;
		}
	}
	return dp[idx][k] = 0;

}


int main(int argc, char const *argv[])
{
	fastio;
	
	int k;cin >> n >> k;
	std::vector<string> s(n);
	sol=vi (n,-1);
	fr(i,0,n) cin >> s[i];
	string ans = "";

	vector<vector<int> > poss(n, vector<int> (10,-1));
	fr(i,0,n)
		fr(d,0,10)
			poss[i][d] = can(d,s[i]);

	vvi dp(n+1, vi (k+1,-1));
	int x = solve(0,k,poss,dp);
	// cout << x << endl;
	if(!x) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i) cout << sol[i];
	cout << endl;


	return 0;
}