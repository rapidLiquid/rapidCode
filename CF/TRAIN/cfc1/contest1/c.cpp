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
	

	string s, t;cin>> s>> t;
	// sequence should be correct then automaton
	// sequence not correct but count correct then other
	// seq and count both same then both
	// both not there then need tree
	vi cnt(26,0);
	for(char c:s) cnt[c-'a']++;
	for(char c:t) cnt[c-'a']--;
	int mx = *max_element(all(cnt));
	int mn = *min_element(all(cnt));

	int seq=false;
	if(sz(t)<=sz(s)) {
		// seq=true;
		int idx = 0;
		fr(i,0,sz(s))if(idx<sz(t)&&s[i]==t[idx])++idx;
		if(idx==sz(t))seq=true;
	}


	if(mn==mx&&mx==0) cout << "array" << endl;
	else if(seq) cout << "automaton" << endl;
	else if(mn>=0) cout << "both" << endl;
	else cout << "need tree" << endl;

	return 0;
}