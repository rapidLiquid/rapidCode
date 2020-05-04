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


void _solve() {
	int n;cin >> n;
	int k1;cin >> k1; queue<int> q1;
	fr(i,0,k1){ int x; cin>>x; q1.push(x); }
	
	int k2;cin >> k2; queue<int> q2;
	fr(i,0,k2){ int x; cin>>x; q2.push(x); }

	map< pair <queue<int>,queue<int> >, bool> m;
	m[{q1,q2}] = 1;
	int steps = 0;
	
	while(1) {
		int t1 = q1.front(), t2 = q2.front();
		
		q2.pop(); q1.pop();
		if(t1 > t2) {
			q1.push(t2); q1.push(t1);
		} else {
			q2.push(t1); q2.push(t2);
		}
		if(m.count({q1,q2})) {
			cout << -1 << endl;
			return;
		}
		++steps;
		if(q1.empty() || q2.empty()) {
			int won = q1.empty() ? 2 : 1;
			cout << steps << " " << won << endl;
			return ;
		}
		m[{q1,q2}] = 1;
	}

}


int main(int argc, char const *argv[])
{
	fastio;
	_solve();

	return 0;
}