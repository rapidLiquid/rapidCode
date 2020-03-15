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



// to support point updates and range query for sum

void _build(vi& tree, vi& arr, int idx, int l, int r) {

	if(l == r) { tree[idx] = arr[l]; return ; }
	int m = (l + r) >> 1;
	_build(tree,arr,idx<<1,l,m);
	_build(tree,arr,1+(idx<<1),m+1,r);
	tree[idx] = tree[idx<<1] + tree[1+(idx<<1)];

}


int _query(vi& tree, int idx, int l, int r, int s, int e) {

	if(l>e || r<s || l>r)return 0; // for sum query
	if(l>=s&&r<=e)return tree[idx];
	int m = (l + r) >> 1;
	int a = _query(tree,idx<<1,l,m,s,e);
	int b = _query(tree,1+(idx<<1),m+1,r,s,e);
	return a+b;
}


// point update is simply rebuilding the tree
void _upd(vi& tree, vi& arr, int p, int val) {

	arr[p]=val;
	int l = 0 , r = (int)arr.size() - 1;
	_build(tree,arr,1,l, r);

}




int main(int argc, char const *argv[])
{
	fastio;
	
	vi arr({1,2,3,4,5});

	int n = (int)arr.size();
	vi tree(3*n);
	_build(tree,arr,1,0,n-1);
	cout << _query(tree,1,0,n-1,2,3) << endl;
	cout << _query(tree,1,0,n-1,3,4) << endl;
	cout << _query(tree,1,0,n-1,2,4) << endl;
	_upd(tree,arr,1,100);
	cout << _query(tree,1,0,n-1,0,2) << endl;




	return 0;
}