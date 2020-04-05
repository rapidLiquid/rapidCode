#include <bits/stdc++.h>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define _parr(a, n) for(int __i = 0; __i < (int )n; __i++) cout << a[__i] << ' '; cout << '\n'
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define frn(i, st, n) for(int i = (int )st; i <= (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).begin(), (c).end()
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;
	
	int n,m;cin >> n>>m;
	vi v(m);
	fr(i,0,m)cin>>v[i];
	int flag=1;
	long long  s= 0;
	fr(i,0,m){
		if(v[i]>n-i)flag=0;
		s+=v[i];
	}
	if(s<n)flag=0;

	if(! flag){
		cout <<"-1\n";
		return 0;
	}
	vi ans;
	int st = 0;
	int till = 0;
	for(int i = 0; i < m-1; ++i) {
		int bache_points = m-i-1;
		int bacha_line = n-till-v[m-1];
		if(bacha_line >= bache_points) {
			st = till + 1;
			till = st+v[i]-1;
		} else {
			++st;
			till = max(till, st + v[i]-1);
		}
		ans.pb(st);
	}
	ans.pb(n-v[m-1]+1);

	fr(i,0,m)cout << ans[i] << " ";
	cout << endl;


	return 0;
}