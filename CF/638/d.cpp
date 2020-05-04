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

/*


s k n
3 3 4 10
s + k <= n - k

*/

int main(int argc, char const *argv[])
{
	fastio;
	
	t_times {
		LL n; cin >> n;
		vl ans({1});
		LL s = 1, pre = 1;
		while(s < n) {
			LL x;
			if(2*pre >= n-s) x = n-s;
			else x = min(2*pre, (n-s)/2);
			s += x;
			pre = x;
			ans.pb(pre);
		}
		// for(int i : ans)cout << i << " ";
		// 	cout << endl;
		vl ans2;
		fr(i,1,(int)ans.size())
			ans2.pb(ans[i]-ans[i-1]);
		cout << (int)ans2.size() << endl;
		for(LL x : ans2)cout<<x<<" ";
		cout << endl;
	}

	return 0;
}


/*


1 a1 a2 a3 a4 .... ak

sum is n and 

ai <= ai+1 <= 2*ai

*/