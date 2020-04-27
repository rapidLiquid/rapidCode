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
	// int t; cin >> t;
	t_times {
		int n;
		cin >> n;
		std::vector<int>  v(n);
		set<int>f;
		set<int>s;
		map<int,int>cf;
		map<int,int>cs;
		// cout << "ok0\n";
		fr(i,0,n) { 
			cin >> v[i]; 
			s.insert(v[i]);
			if(cs.count(v[i])==0)cs[v[i]]=0;
			cs[v[i]]++;
		}
		// cout << "ok\n";
		std::vector<pair<int,int> > ans;
		// cout << "ok1\n";
		fr(i,0,n-1){
			cs[v[i]]--;
			if(cs[v[i]]==0)s.erase(v[i]);

			if(cf.count(v[i])==0)cf[v[i]]=0;
			cf[v[i]]++;

			if(cf[v[i]]==1)f.insert(v[i]);
			else break;
			
			auto z = f.end();--z;
			int l1 = *z;
			auto zz = s.end();--zz;
			int l2 = *zz;
			if(l1==sz(f) && l2==sz(s)){
				if(l1==i+1 && l2 == n-i-1) {
					ans.pb({l1,l2});
				}
			}
		}
		// cout << "ok2";
		cout << sz(ans) << endl;
		for(auto x : ans)
			cout << x.F << " " << x.S << endl;

	}


	return 0;
}