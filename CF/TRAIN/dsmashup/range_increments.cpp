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



// we can use a sparse table also for query only
// we can try lazy update also for updating the values dynamically
// maybe set also
class SegTree
{
private:
	vii tree;
	int n;
	void _build(vi& arr, int idx, int l, int r) {
		if(l == r) {
			tree[idx].F = l;
			tree[idx].S = arr[l];
			// store idx
			return ;
		}
		int m = (l + r) / 2;
		_build(arr, 2*idx+1, l, m);
		_build(arr, 2*idx+2, m+1, r);
		tree[idx].F = tree[2*idx+1].S > tree[2*idx+2].S ?
			tree[2*idx+2].F : tree[2*idx+1].F;
		tree[idx].S = arr[tree[idx].F];
	}
	ii _query(int idx, int l, int r, int s, int e) {
		if(s > e || e < l || s > r) return {-1,INT_MAX};
		if(s >= l && e <= r) return tree[idx];
		int m = (s+e) / 2;
		ii lef = _query(2*idx+1,l,r,s,m);
		ii rig = _query(2*idx+2,l,r,m+1,e);
		return rig.S > lef.S ? lef : rig;
	}
	// int _update() {

	// }

public:
	SegTree(vi& arr) {
		// mk sgtree over this array
		this->n = (int)arr.size();
		tree = vii (3*n);
		this->_build(arr,0,0,n-1);
	}
	ii query(int l,int r) {
		ii ans = _query(0,l,r,0,n-1);
		return ans;
	}
	
};

// vector<pair<int,ii>>
void _solve(SegTree& tree, int l, int r, LL till_now, vii& yo) {
	// if(l > r) return vii ();
	if(l > r) return ;
	ii q = tree.query(l,r);
	int val = q.S;
	int idx = q.F;

	vii ans;
	if(val > till_now) {
		ans = vii (val-till_now, {l,r});
		till_now = val;
	}
	_solve(tree,l,idx-1,till_now, yo);
	_solve(tree,idx+1,r,till_now, yo);
	
	yo.insert(yo.end(),all(ans));
	// ans.insert(ans.end(), all(lef) );
	// ans.insert(ans.end(), all(rig) );
	// the commented impl gave TLE
	// return ans;
}


int main(int argc, char const *argv[])
{
	fastio;
	int n; cin >> n;
	vi arr(n);
	fr(i,0,n)cin>>arr[i];
	// vi arr;
	// arr = vi ({1,2,3,4,5});
	SegTree tree(arr);
	vii v;
	_solve(tree, 0, sz(arr)-1, 0, v);

	cout << sz(v) << endl;
	for(auto x : v)cout << x.F+1 << " " << x.S+1 << endl;



	return 0;
}