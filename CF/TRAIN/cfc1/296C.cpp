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
	
	int n, m, k;
	cin >> n >> m >> k;
	vl a(n);
	vl b(n);

	fr(i,0,n)cin>>a[i];
	vector<pair<ii,int> > op(m);
	fr(i,0,m)cin>>op[i].F.F>>op[i].F.S>>op[i].S;

	vi co(m);
	fr(i,0,k){
		int l,r;
		cin >> l >> r;
		--l,--r;
		co[l] += 1;
		if(r+1<m)co[r+1]-=1;
	}
	fr(i,0,m){
		if(i>0)co[i]+=co[i-1];
		LL inc = co[i]*1ll*op[i].S;
		b[op[i].F.F-1] += inc;
		if(op[i].F.S<n)b[op[i].F.S] -= inc;
	}
	fr(i,1,n)b[i]+=b[i-1];
	fr(i,0,n){a[i]+=b[i];cout<<a[i]<<" ";}
	cout << endl;


	return 0;
}