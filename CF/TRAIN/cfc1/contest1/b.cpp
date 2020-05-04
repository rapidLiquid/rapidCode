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
	

	int n;cin>>n;
	vi v(n);
	vi tmp(n);
	fr(i,0,n){cin>>v[i];tmp[i]=v[i];}
	sort(all(tmp));
	int X=0;
	map<int,int>yo;
	for(int i : tmp) yo[i]=++X;
	int st=-1,en=-1;
	fr(i,0,n) if(yo[v[i]]!=i+1) {st=i;break;}
	rev(i,n-1,0) if(yo[v[i]]!=i+1) {en=i;break;}

	//check if its the valid reversed segnemnt
	
	if(st == -1) { st++; en++; }
	int k = st+1, flag = 1;
	rev(i,en,st){
		if(yo[v[i]]!=k) flag = 0;
		++k;
	}
	if(flag) {
		cout << "yes" << endl;
		cout << st+1 << " " << en+1 << endl;
	}
	else cout << "no" << endl;

	return 0;
}