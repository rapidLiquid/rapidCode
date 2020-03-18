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
typedef pair< LL, LL> ii;
typedef vector< LL> vi;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

//finally accepted

// segtree and lazy update and prop for finding max in a range
void _build(vi& tree, vi& arr, int idx, int l, int r) {
	if(l>r)return;
	if(l == r) { tree[idx] = arr[l]; return; }
	int m = (l+r)>>1;
	_build(tree,arr,(idx<<1),l,m);
	_build(tree,arr,1+(idx<<1),m+1,r);
	tree[idx]=max(tree[idx<<1],tree[1+(idx<<1)]);
}


void _push(vi& T,vi& L,int i) {
	int ts = (int)T.size();
	if(i >= ts) return;
	if(L[i] > INT_MIN) T[i] += L[i];
	if((i<<1) < ts) {
		if(L[i<<1]>INT_MIN&&L[i] > INT_MIN)L[i<<1] += L[i];
		else if(L[i<<1] == INT_MIN) L[i<<1] = L[i]; // very imp, why ??
	}
	if((1+(i<<1)) < ts) {
		if(L[1+(i<<1)]>INT_MIN&&L[i] > INT_MIN)L[1+(i<<1)] += L[i];
		else if(L[1+(i<<1)]==INT_MIN) L[1+(i<<1)] = L[i];
	}
	L[i] = INT_MIN;
}


LL _query(vi& tree,vi& lazy, int idx,int l, int r,int s,int e) {
	//lazy
	_push(tree,lazy,idx);
	if(s > e || s > r || e < l) return INT_MIN;
	if(s>=l && e<=r) return tree[idx];
	int m = (s+e) >> 1;
	int a =_query(tree,lazy,idx<<1,l,r,s,m);
	int b =_query(tree,lazy,1+(idx<<1),l,r,m+1,e);
	return max(a,b);
}


void _upd(vi& tree, vi& lazy, LL val, int idx,int l, int r,int s,int e) {
	_push(tree,lazy,idx);
	if(s > e || s > r || e < l) return;
	if(s>=l && e<=r) {
		if (lazy[idx] > INT_MIN) lazy[idx] += val; 
		else lazy[idx] = val; 
		_push(tree,lazy,idx);
		return;
	}
	int m = (s+e)>>1;
	_upd(tree,lazy,val,idx<<1,l,r,s,m);
	_upd(tree,lazy,val,1+(idx<<1),l,r,m+1,e);
	tree[idx] = max(tree[idx<<1],tree[1+(idx<<1)]);

}




vi tree;
vi lazy;
vi arr;
vi arr2;
std::vector<ii> a;
std::vector<ii> b;
std::vector<pair<ii,int>> mons;

bool comp(pair<ii,int>& a, pair<ii,int>& b) {
	if(a.F.F < b.F.F) return true;
	// if(a.F.S < b.F.S) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	fastio;
	
	int n,m,p; cin >> n >> m >> p;
	a = vector<ii>(n);
	b = vector<ii>(m);
	mons = vector<pair<ii,int>>(p);
	fr(i,0,n) cin >> a[i].F >> a[i].S;
	fr(i,0,m) cin >> b[i].F >> b[i].S;
	fr(i,0,p) cin >> mons[i].F.F >> mons[i].F.S >> mons[i].S;

	sort(all(a));
	sort(all(b));
	sort(all(mons), comp);



	arr = vi(m); arr2 = vi(m);
	fr(i,0,m) {
		arr[i] = -b[i].S;
		arr2[i] = b[i].F;
		// cout << arr[i] << " ar1 ar2 " << arr2[i] << endl;
	}

	tree = vi (4*m);
	lazy = vi (4*m,INT_MIN);
	_build(tree,arr,1,0,m-1);

	int midx = 0;
	long long ans = INT_MIN;
	fr(i,0,n) {
		// cout << " --i  " << i << " " << a[i].F << " " << a[i].S << endl;
 		for( ; mons[midx].F.F < a[i].F && midx < p; ++midx ) {
			int def = mons[midx].F.S;
			int idx = lower_bound(all(arr2),def) - arr2.begin();

			if(idx!=m && arr2[idx] == def) ++idx;
			if(idx == m) continue;
			_upd(tree,lazy,mons[midx].S,1,idx,m-1,0,m-1);
		}
		//find ans here
		LL v = _query(tree,lazy,1,0,m-1,0,m-1);
		// fr(i,0,10)cout << i << " tr " << tree[i] << endl;
		ans = max(ans, -a[i].S+v);
	}
	cout << ans << endl;



	return 0;
}


/*
EXPLANATION

we have list of Ai and CAi
we have list of Bi and CBi

we have list of Xj,Yj,Zj


we need to select an Ai and a Bj
s.t. the profit is max

approach

fix an Ai

for each Ai

profit(i) = -A[i] - B[j] + 
	( sum of only those Z[k] (where X[k] < A[i]) s.t. B[j] > Y[k] )
in a way we are fixing the monsters by fixing the A[i]
but still we need to take care of the other parameter
we can simply update
if a moster has some attack Y then we can add the profit
to all the defense values greater than Y, for which we construct a segment tree
we are adding it in a range simply

int k = 0;
fr(i,0,n) {
	// n A's
	for(; mons[k].X < A[i]; ++k) {
		// now we know for sure that the defense of these monster
		// is less than the selected attack
		// all of them have certain attacks
		// we need to now update the defense
		// simply these profits will be added to those defense
		// which is higher than selected attack
		// why we do this since we can pick any defense modifier
		// after doing this , pick the defense modifier
		// with the highest profit

		update for all profit higher than the current
		because had we selected that armor
		we would have survived the attack and got the profit

	}

}


in simple terms, we need to fix the attack
and now one by one just update all the higher defenses
because picking those defenses would give us the current profit

in general , these are segment tree problems
come up with a general formula or approach and fix a param
like start from the lowest or the highest and update all the ranges


*/




