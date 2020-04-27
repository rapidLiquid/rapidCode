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
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;
	
	int t;cin >> t;
	while(t--) {
		int n, x; cin >> n >> x;
		std::vector<LL> v(n);
		fr(i,0,n){cin >> v[i];}
		sort(all(v));
		fr(i,0,n)v[i] += (i>0?v[i-1]:0);
		LL ans=0;
		fr(i,0,n) {
			LL tot=v[n-1];
			if(i>0)tot-=v[i-1];
			LL z = tot/(n-i);
			if(z>=x){
				ans=n-i;
				break;
			}
		}
		cout << ans << endl;
	}


	return 0;
}