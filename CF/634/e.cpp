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


int check(int mid, vvi& pre,int i, int j) {
	// is it possible to get length>=mid
	// for idx bwn  (j,i]
	fr(k,0,201) //200 times hence tle
		if(pre[k][j]-pre[k][i]>=mid)
			return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	// fastio;
	int t;
	scanf("%d",&t);
	while(t--) {

		// 
		int n;
		// cin >> n;
		scanf("%d",&n);
		vi a(n);
		fr(i,0,n) scanf("%d",&a[i]);

		vvi pre(210, vi(n,0));
		int ans = 0;
		fr(i,0,201) {
			fr(j,0,n) {
				pre[i][j] = a[j]==i?1:0;
				if(j>0)
					pre[i][j] += pre[i][j-1];
			}
			ans = max(ans, pre[i][n-1]);
		} // all same


		// middle value doesnt matter
		// for every 200 (k) values
		// for every i , just find the last j st
		// pre[i][k] == pre[n-1][k] -  pre[j-1][k]
		// pre[i][k] + pre[j-1][k] == pre[n-1][k]
		// last j-1
		fr(i,0,201) {
			fr(j,0,n) {
				// int x = pre[j][i];
				int y = pre[i][n-1] - pre[i][j];
				int idx = upper_bound(all(pre[i]),y)-pre[i].begin();
				--idx;//since upperbound gives one more

				if(idx>=j) {
					// max freq ele bwn idx and j
					// pre[k][idx] - (j>0?pre[k][j-1]:0);
					// max among all k
					int low = 0, high = idx - j;
					while(low <= high) {
						int mid = (low + high) / 2;
						if(check(mid,pre,j,idx)) low = mid + 1;
						else high = mid - 1;
					}
					int something= pre[i][j] + pre[i][n-1]-pre[i][idx] + high;
					ans = max(ans, something);

				}
				

			}
		}
		printf("%d\n", ans);

	}

	return 0;
}