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

vii get_divs(int x, vi& si){
	map<int,int>m;
	m[1]=1;
	while(si[x]>1){
		m[si[x]]++;
		x/=si[x];
	}
	vii v;
	for(auto z:m)v.pb({z.first,z.second});
	return v;
}

LL P(LL x, LL y){
	LL res = 1;
	while(y) {
		if(y&1) res *= x;
		x *= x;
		y>>=1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	fastio;

	const int MX = 2e5+7;
	vi si(MX);si[1]=1;
	fr(i,2,MX){
		if(si[i])continue;
		for(int j = i; j < MX; j+=i)
			if(!si[j])si[j]=i;
	}


	int n;cin >> n;
	vi v(n);
	fr(i,0,n)cin>>v[i];
	map<int,multiset<int> >m;
	fr(i,0,n){

		vii dc=get_divs(v[i],si);
		for(auto x : dc){
			m[x.F].insert(x.S);
			// sort(all(m[x.F]));
			// if(sz(m[x.F])==3)m[x.F].pop_back();
		}
	}
	LL ans = 1;
	for(auto x:m){
		// sort(all(x.S));
		auto z = x.S.begin();
		if(sz(x.S) == n){
			++z;
			ans *= P(x.F,(*z));
		}
		else if(sz(x.S)==n-1)
			ans *= P(x.F,(*z));
		// cout <<x.F << " v" ;
		// for(int i : x.S)cout << i << " ";
		// 	cout << endl;
	}
	cout << ans << endl;

	// we need to keep count of second max count of primes



	return 0;
}