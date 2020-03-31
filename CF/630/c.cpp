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

// int opp(int n, int idx) {
// 	if (idx <= n / 2) return n-1-idx;
// 	return 
// }

int main(int argc, char const *argv[])
{
	fastio;
	
	t_times {
		int n, k;cin >> n >> k;
		string s; cin >> s;
		int changes = 0;
		vi vis(n,0);

		fr(i,0,n) {
			if(vis[i])continue;
			vi ss;
			queue<int> q;
			vis[i] = 1;
			q.push(i);
			// if(!vis[n-1-i])q.push(n-1-i);
			vi cnt(26,0);
			while(!q.empty()) {
				int fr = q.front();
				cnt[s[fr]-'a']++;
				ss.pb(fr);
				q.pop();
				if(fr-k >= 0 && !vis[fr-k]) {
					vis[fr-k] = 1;
					q.push(fr-k);
				}
				if(fr+k < n && !vis[fr+k]) {
					vis[fr+k] = 1;
					q.push(fr+k);
				}
				if(!vis[n-1-fr]) {
					vis[n-1-fr] = 1;
					q.push(n-1-fr);
				}

			}
			int idx = 0;
			fr(i,1,26) if(cnt[i]>cnt[idx]) idx = i;
			changes += (int)ss.size() - cnt[idx];
			// for(int p:ss) s[p] = (char)(idx+'a');

		}
		cout << changes << endl;

	}
	return 0;
}