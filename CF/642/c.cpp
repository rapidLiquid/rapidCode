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
	const int N = 5e5+7;
	vl f(N);
	LL c = 0;
	fr(i,3,n) {
		if(i%2==0)continue;
		f[i] = 4 * (f[n-2] + n-1 + c);
		c += n*1ll*(n-1);
	}


	t_times {
		int n;cin >> n;
		// f(n)
		// f(1) = 0
		// f(3) = 4 * f(n-2) + 4 * (n-2) * (n-2) + 4 * (n*(n-1)) / 2
		// f(3) = 4 + 12
		// f(5) = 16 + 9 + 
		// f(n) = f(n-2) + (n/2)*((n/2)-1) / 2
		// cout << 4*f(n)
		cout << f[n] << endl;
	}



	return 0;
}