#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

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


vi _si(int n) {
	vi pr(n+1,1);
	pr[0] = pr[1] = 0;
	fr(i,2,n+1) {
		if (!pr[i]) continue;
		for(int j = 2*i; j < n+1; j+=i)
			pr[j] = 0;
	}
	vi res;
	fr(i,0,n+1) if(pr[i]) res.pb(i);
	return res;
}


int main(int argc, char const *argv[])
{
	fastio;	
	// int n = 1000;
	vi primes = _si(1000);
	int ps=(int)primes.size();
	t_times {
		int n;cin >> n;
		vi a(n);
		fr(i,0,n)cin>>a[i];

		vi ans(n,0);
		int c=1;
		set<int>s;
		fr(i,0,n)s.insert(i);
		int color=0;
		fr(i,0,n) {
			if(s.find(i)==s.end())continue;
			vi tmp;
			++color;
			for(int j : s) {
				if(__gcd(a[j],a[i])>1) tmp.pb(j);
			}
			for(int i : tmp) {ans[i]=color; s.erase(tmp);}
		}
		cout << color << endl;
		fr(i,0,n)cout << ans[i] << " ";
		cout << endl;

	}
	return 0;
}