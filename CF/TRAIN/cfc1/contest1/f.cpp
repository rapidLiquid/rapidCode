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
	
	int n, m; cin >> n >> m;
	vl a(n); vl b(m); vl sa(n); vl sb(m);
	fr(i,0,n) { cin >> a[i]; }
	fr(i,0,m) { cin >> b[i]; }
	sort(all(a)); sort(all(b));
	fr(i,0,n) { sa[i] = a[i] + (i>0?sa[i-1]:0); }
	fr(i,0,m) { sb[i] = b[i] + (i>0?sb[i-1]:0); }
	LL ans = LLONG_MAX;
	fr(i,0,m) {
		LL X = b[i];
		//all in a should be greater than this
		int ia = lower_bound(all(a), X) - a.begin();
		LL changes = ia*X - (ia>0?sa[ia-1]:0);
		// all in b should be less
		int ib = upper_bound(all(b), X) - b.begin();
		changes += (sb[m-1]-(ib>0?sb[ib-1]:0)) - (m-ib)*X;
		// b[i] = changes;
		ans = min(ans, changes);
	}

	fr(i,0,n) {
		LL X = a[i];
		//all in a should be greater than this
		int ia = lower_bound(all(a), X) - a.begin();
		LL changes = ia*X - (ia>0?sa[ia-1]:0);
		// all in b should be less
		int ib = upper_bound(all(b), X) - b.begin();
		changes += (sb[m-1]-(ib>0?sb[ib-1]:0)) - (m-ib)*X;
		ans = min(ans, changes);
	}
	cout << ans << endl;

	return 0;
}


/*




nos of b must be decreased and of a must be increased

lets say X  is the number




*/


