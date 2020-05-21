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
		int n;cin >> n;


		set<pair<int,ii>> Ss;
		// { length , {l, r} }
		Ss.insert({-n,{0,n-1}});
		vi a(n);int k = 1;
		while(!Ss.empty()) {
			// cout << "ok\n";
			auto z = *Ss.begin();
			int len = abs(z.F);
			int l = z.S.F;
			int r = z.S.S;
			Ss.erase(z);
			// cout << "len l  r " << len << " " << l << " " << r << endl;
			if(len&1) {
				int p = (l+r) /2;
				a[p] = k++;
				int l2 = p - l;
				if(!l2) continue;
				Ss.insert({-l2,{l,p-1}});
				Ss.insert({-l2,{p+1,r}});
			} else {
				int p = (l+r)/2;
				a[p] = k++;
				int l1 = p-l;
				int l2 = r-p;
				if(l1) Ss.insert({-l1,{l,p-1}});
				if(l2) Ss.insert({-l2, {p+1,r}});
			}

		}
		fr(i,0,n)cout << a[i] << " ";
		cout << endl;


	}


	return 0;
}