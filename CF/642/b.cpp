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
	
	t_times {
		int n, k;cin >> n>> k;
		vi a(n);
		vi b(n);
		fr(i,0,n) cin >> a[i];
		fr(i,0,n) cin >> b[i];
		// sort(all(a));
		sort(all(b));
		reverse(all(b));
		// int j = k-1;
		fr(i,0,k) {
			// if(!k) break;
			a.pb(b[i]);
			// if(a[i] < b[j]) swap(a[i],b[j++]);
		}
		sort(all(a));
		reverse(all(a));
		int s = 0;
		fr(i,0,n)s+=a[i];
		cout << s << endl;
	}


	return 0;
}