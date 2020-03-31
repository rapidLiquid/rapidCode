#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
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
typedef pair< LL, LL> ii;
typedef vector< LL> vi;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
const long double PI = 3.14159265358979323846L;
#define pi acos(-1.0)
 // START FROM HERE



// void _build(vi& tree, int idx, int l, int r) {
// 	if(l == r) {
// 		tree[idx] = 0;
// 		return;
// 	}
// 	int m = (l + r) >> 1;
// 	_build(tree,idx<<1,l,m);
// 	_build(tree,1+(idx<<1),m+1,r);
// 	tree[idx] = max(tree[idx<<1],tree[1+(idx<<1)]);
// }


LL _q(vi& tree, int idx, int l, int r, int s, int e) {
	if( s > e || s > r || e < l ) return 0;
	if(s>=l && e<=r) return tree[idx];
	int m = (s+e)>>1;
	LL a = _q(tree,idx<<1,l,r,s,m);
	LL b = _q(tree,1+(idx<<1),l,r,m+1,e);
	return max(a,b);
}

void _upd(vi& tree, int idx,int l, int r,int s, int e, LL val) {
	// its point update simply
	if(s > e || s > r || e < l) return ;
	if(s>=l&&e<=r) {
		// although wrong but here l = r
		tree[idx]=val;
		return ;
	}
	int m = (s+e)>>1;
	_upd(tree,idx<<1,l,r,s,m,val);
	_upd(tree,1+(idx<<1),l,r,m+1,e,val);
	tree[idx]=max(tree[idx<<1],tree[1+(idx<<1)]);

}


vi tree;
int main(int argc, char const *argv[])
{
	fastio;
	int n;
	cin >> n;
	std::vector<ii> V(n);
	
	fr(i,0,n) { 
		LL r,h; cin >> r >> h;
		V[i].F = r*r*h;
		V[i].S = i; 
	}

	sort(all(V));
	tree = vi(4*n,0);
	// _build(tree,1,0,n-1);
	fr(i,0,n) {
		LL curr = V[i].F;
		vi up;
		vi uv;
		while(V[i].F == curr && i < n) {

			LL best = _q(tree,1,0,V[i].S-1,0,n-1);
			// cout << "bes " << best << endl;
			LL val = V[i].F + best; // max till now
			// _upd(tree,1,V[i].S,V[i].S,0,n-1,val);
			up.pb(V[i].S);
			uv.pb(val);
			// do the point update
			//which array should be updated, i think tree only is enough
			++i;
		}
		fr(k,0,(int)up.size()){
			_upd(tree,1,up[k],up[k],0,n-1,uv[k]);
		}
		--i;
	}
	
	long double ans = tree[1] * pi;
	cout << std::fixed;
	cout << std::setprecision(20);
	cout  << ans << endl;


	return 0;
}





/*

https://codeforces.com/problemset/problem/629/D


The cakes are numbered in such a way that the cake number i 
can be placed only on the table or on some cake number j 
where j < i. 
Moreover, in order to impress friends Babaei will put the cake i on top 
of the cake j only if the volume of the cake i is 
strictly greater than the volume of the cake j.



dp[i] = max ( v[i] , dp[j] + v[i] );
forall j. i > j and v[i] > v[j]

fr(i,0,n) {
	dp[i] = v[i];
	rev(j,i-1,0) {
		if(v[i] > v[j]) {
			dp[i] = max(dp[i],dp[j]+v[i]);
		}
	}
}

*/