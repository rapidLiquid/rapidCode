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
		string s;cin >> s;
		sort(all(s));
		string ans = "";
		ans += s[k-1];
		int flag = 1;
		for(int i = k; i < n; ++i)
			if(s[i]!=s[k]) flag = 0;
		if(flag) {
			//all same
			int c = (n-k)/k;
			if((n-k)%k) ++c;
			if(s[0]==s[k-1]) 
				fr(i,0,c) ans += s[k];
		} else {
			if(s[0]==s[k-1]) fr(i,k,n) ans += s[i];
		}
		cout << ans << endl;


	}


	return 0;
}