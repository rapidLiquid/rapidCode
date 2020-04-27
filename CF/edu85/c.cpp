#include <bits/stdc++.h>

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
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< LL, LL> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;

	t_times {
		
		int n;cin >> n;
		vii v(n);
		vi vis(n,0);
		fr(i,0,n) {
			cin >> v[i].F >> v[i].S;
		}
		LL bullets = LLONG_MAX;
		std::vector<LL> tmp(n);
		fr(i,0,n) {
			tmp[i] = v[i].F - v[(i-1+n)%n].S;
			tmp[i] = max(tmp[i],0ll);
			tmp[i] += (i>0?tmp[i-1]:0);
		}
		fr(i,0,n) {
			LL x = v[i].F;
			if(i>0) x += tmp[i-1];
			x += tmp[n-1]-tmp[i];
			bullets = min(bullets, x);
		}
		cout << bullets <<endl;




	}

	return 0;
}