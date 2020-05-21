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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vvi dpf(n,vi (2,0));
		// vvi dpb(n,vi (2,0));
		
		int ones = 0;
		
		fr(i,0,n)if(s[i]=='1')ones++;
		int ans = ones;
		int curr = 0;

		vi oc(n);
		fr(i,0,n) {
			if(s[i]=='1')++oc[i];
			if(i-k>=0)oc[i]+=oc[i-k];
		}

		fr(i,0,n) {
			dpf[i][0] = s[i] == '0' ? 0 : 1;
			dpf[i][1] = s[i] == '0' ? 1 : 0;
			if(i-k>=0) {
				dpf[i][1] += min(dpf[i-k][1], dpf[i-k][0]);
				dpf[i][0] += dpf[i-k][0];
			}
			int ops = ones - oc[i]; // switch em off
			ops += dpf[i][1];
			ans = min(ans, ops);
		}
		cout << ans << endl;


	}



	return 0;
}