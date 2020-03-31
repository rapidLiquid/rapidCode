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
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE


// segtree and lazy update and prop for finding max in a range
void _build(vi& tree, vi& arr, int idx, int l, int r) {
	if(l == r) { tree[idx] = arr[l]; return; }
	int m = (l+r)>>1;
	_build(tree,arr,idx<<1,l,m);
	_build(tree,arr,1+(idx<<1),m+1,r);
	tree[idx]=max(tree[idx<<1],tree[1+(idx<<1)]);
}


void _push(vi& T,vi& L,int i) {
	int ts = (int)T.size();
	if(i >= ts) return;
	if(L[i] > INT_MIN) T[i] += L[i];
	if(L[1<<i]>INT_MIN&&L[i] > INT_MIN)L[i<<1] += L[i];
	// else L[1<<i]=L[i];//@todo WRONG
	if(L[1+(i<<1)]>INT_MIN&&L[i] > INT_MIN)L[1+(i<<1)] += L[i];
	L[i] = INT_MIN; // for max
}


int _query(vi& tree,vi& lazy, int idx,int l, int r,int s,int e) {
	//lazy
	_push(tree,lazy,idx);
	if(s > e || s > r || e < l) return INT_MIN;
	if(s>=l && e<=r) return tree[idx];
	int m = (s+e) >> 1;
	int a =_query(tree,lazy,idx<<1,l,r,s,m);
	int b =_query(tree,lazy,1+(idx<<1),l,r,m+1,e);
	return max(a,b);
}


void _upd(vi& tree, vi& lazy, int val, int idx,int l, int r,int s,int e) {
	_push(tree,lazy,idx);
	if(s > e || s > r || e < l) return;
	if(s>=l && e<=r) {
		if (lazy[idx] > INT_MIN) lazy[idx] += val; 
		else lazy[idx] = val; 
		_push(tree,lazy,idx);//WHY?? @todo
		return;
	}
	int m = (s+e)>>1;
	_upd(tree,lazy,val,idx<<1,l,r,s,m);
	_upd(tree,lazy,val,1+(idx<<1),l,r,m+1,e);
	tree[idx] = max(tree[idx<<1],tree[1+(idx<<1)]);

}






/*
		  8
	 4 	       8

  2     4    6     8

1  2  3  4  5  6  7  8


*/

const INT MX = 1e6+7;
// vi tree;
// vi lazy;


int main(int argc, char const *argv[])
{
	fastio;
	// int n,m,p; cin >> n >> m >> p;
	// std::vector<ii> a(n);
	// std::vector<ii> b(m);
	// std::vector<pair<ii,int>> mons(p);
	// fr(i,0,n) cin >> a[i].F >> a[i].S;
	// fr(i,0,n) cin >> b[i].F >> b[i].S;
	// fr(i,0,p) cin >> mons[i].F.F >> mons[i].F.S;





	// tree = vi (3*MX);
	// lazy = vi (3*MX,INT_MIN);

	vi arr({1,2,3,4,5,6,7,8});
	int n = (int)arr.size()
	vi tree(3*n);
	vi lazy(3*n);
	_build(tree,arr,1,0,n-1);
	fr(i,0,22) cout << i << " " << tree[i] << endl;
	cout << endl;
	cout << _query(tree,lazy,1,2,3,0,n-1) << endl;
	cout << _query(tree,lazy,1,0,3,0,n-1) << endl;
	cout << _query(tree,lazy,1,0,1,0,n-1) << endl;
	_upd(tree,lazy,33,1,0,2,0,n-1);
	cout<<"afupd\n";
	fr(i,0,22) cout << i << " " << tree[i] << endl;
	cout << _query(tree,lazy,1,0,1,0,n-1) << endl;
	cout << _query(tree,lazy,1,0,2,0,n-1) << endl;
	cout << "afterque\n";
	fr(i,0,22) cout << i << " " << tree[i] << endl;




	return 0;
}