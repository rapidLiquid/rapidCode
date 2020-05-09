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

int poss=0, n;
vector<vvi> dp;
int go(vector<string>& S,int px,int py,int n,int turn) {

	if(px<0 || px>2 || S[px][py] != '.') return 0;
	if(py>=n) return 1;
	
	if(dp[px][py][turn]!=-1)return dp[px][py][turn];
	// cout << "ATTTT " << px <<  ' ' << py << endl;
	int ans = 0;
	if(turn&1){
		ans |= go(S,px,py+1,n,turn^1);
		if(S[px][py+1]=='.') {
			ans |=go(S,px+1,py+1,n,turn^1);
			ans |=go(S,px-1,py+1,n,turn^1);
		}
	}
	else {
		if(S[px][py+1]=='.') {
			ans |=go(S,px,py+2,n,turn^1);
			// if(S[px][py+2]=='.') {
			// 	ans |=go(S,px+1,py+2,n,turn^1);
			// 	ans |=go(S,px-1,py+2,n,turn^1);
			// }
		}
	}
	return dp[px][py][turn] = ans;
}

int main(int argc, char const *argv[])
{
	fastio;
	
	t_times {
		int k;
		cin >> n >> k;
		vector<string> s(3);
		string tmp = "";
		fr(i,0,n) tmp += '.';
		fr(i,0,3){cin>>s[i];s[i]+=tmp;}
		int px,py=0;
		fr(i,0,3)if(s[i][0]=='s')px=i;
		poss = 0;
		// cout << "px py " << px << " " << py << endl;
		s[px][py] = '.';
		dp = vector<vvi> ( 3 , vvi ( 2*n , vi (2, -1)));
		int ans = go(s,px,py,n,1);
		if(ans)cout<<"YES\n";
		else cout << "NO\n";


	}


	return 0;
}