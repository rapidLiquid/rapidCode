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
	

	int n, m, k;
	cin >> n >> m >> k;
	// do this for k-1 tubes...
	vii ans;
	fr(i,1,n+1){
		if(i&1){
			fr(j,1,m+1) ans.pb({i,j});
		} else {
			rev(j,m,1) ans.pb({i,j});
		}
	}

	fr(i,0,k-1){
		cout << 2 << " ";
		cout << ans[i*2].F << " " << ans[i*2].S << " ";
		cout << ans[i*2+1].F << " " << ans[i*2+1].S << " ";
		cout << endl;
	}
	cout << n*m-(2*(k-1)) << " ";
	fr(i,2*k-2,sz(ans))cout << ans[i].F << " " << ans[i].S << " " ;
	cout << endl;


	return 0;
}