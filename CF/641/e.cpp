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

int main(int argc, char const *argv[])
{
	fastio;
	
	int n, m, q;
	cin >> n >> m >> q;
	std::vector<string> S(n);
	// cout << "OK\n";
	fr(i,0,n)cin>>S[i];


	vector<vector<bool> > wc(n,vector<bool> (m,0));
	// // vi d()
	fr(i,0,n){
		fr(j,0,m){
			char c=S[i][j];
			int flag = 0;
			if(i>0) flag |= (S[i-1][j]==c);
			if(i<n-1) flag |= (S[i+1][j]==c);
			if(j>0) flag |= (S[i][j-1]==c);
			if(j<n-1) flag |= (S[i][j+1]==c);
			if(flag) wc[i][j]=1;
		}
	}
	fr(kk,0,q) {
		int x, y;
		LL tu;
		cin >> x >> y >> tu;
		--x;--y;
		if(tu&1) cout << (wc[x][y] ? (S[x][y]=='1'?'0':'1') : S[x][y]) << endl;
		else cout << S[x][y] << endl;
	}



	return 0;
}