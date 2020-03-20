#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

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
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< vi> vvi;
 
const LL mod = 998244353;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

LL mul(LL x,LL y) {
	x%=mod;y%=mod;
	return (x*y)%mod;
}
int main(int argc, char const *argv[])
{
	fastio;
	
	int n, k;
	cin >> n >> k;
	std::vector<ii> v(n);
	fr(i,0,n) {cin >> v[i].F; v[i].S = i;}

	sort(all(v));
	reverse(all(v));
	vi pos; LL anss=0;
	fr(i,0,k){anss+=v[i].F;pos.pb(v[i].S);}
	sort(all(pos));
	LL tot=1;
	fr(i,1,k){
		// cout << pos[i-1] << " " << pos[i] << endl; 
		tot=mul(tot,pos[i]-pos[i-1]);
	}
	cout << anss << " " << tot << endl;

	return 0;
}