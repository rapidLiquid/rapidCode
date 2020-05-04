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

vi sieve() {
	// a^2 is not a divisor which means
	/*
		
		for 10^12, we can consider till 10^6

	*/
}

int main(int argc, char const *argv[])
{
	fastio; LL n; cin >> n;
	set<LL> div;
	fr(i,1,(int)1e6+1) {
		if(n%i==0) {
			div.insert(n/i);
			div.insert(i);
		}
	}
	vl divs(all(div));
	reverse(all(divs));
	for(LL d : divs) {
		int flag = 0;
		for(LL i = 2; i * i <= d; ++i) {
			if(d%(i*i) == 0) flag = 1;
		}
		if(!flag) {
			cout << d << endl;
			return 0;
		}
	}
	cout << -1 <<endl;
	return 0;
}