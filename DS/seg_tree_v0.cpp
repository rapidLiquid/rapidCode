#include <bits/stdc++.h>
using namespace std;


/*
a simple seg tree to add the values 
and update and query

*/


const int N = 1e5+7;


typedef std::vector<int> vi;
vi arr(N);
vi tree(N*2+7);

void _build(vi& tree, int idx, int l, int r) {
	if(l == r) {
		tree[idx]=arr[l];
		return ;
	}
	_build(tree,idx>>1,l,m);
	_build(tree,1+(idx>>1),m+1,r);
	tree[idx]=tree[idx>>1]+tree[1+(idx>>1)];

}

int _query(vi& tree, int idx, int l, int r, int s, int e) {
	if(l > r || r < s || l > e) return 0; // for sum

	int m=(l+r)/2;
	int a=_query(tree,idx>>1,l,m,s,e);
	int b=_query(tree,1+(idx>>1),m+1,r,s,e);

	return a+b;

}

void _update(vi& tree, int idx, int l, int r, int s, int e) {
	if(l > r || r < s || l > e) return 0; // for sum

	if(l>=s&&r<=e) {
		return tree[idx];
	}

	int m=(l+r)/2;
	int a=_query(tree,idx>>1,l,m,s,e);
	int b=_query(tree,1+(idx>>1),m+1,r,s,e);

	return a+b;
}





int main(int argc, char const *argv[])
{
	

	return 0;
}