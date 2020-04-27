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
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
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

vi d;
vi d2;
vvi G;
void dfs(int root,int pr) {
	d2[root] = d2[pr] - 1;
	for(int v:G[root]) {
		if(v!=pr){
			dfs(v,root);
			d[root] += d[v];
		}
	}
	d[root]++;
}

LL ans=0;int seen=0;
void dfs2(int u,int pr) {
	if(d[u]==INT_MIN) ans+=seen;
	else seen++;
	for(int v:G[u]) {
		if(v!=pr)dfs2(v,u);
	}
	if(d[u]!=INT_MIN)--seen;
}

int main(int argc, char const *argv[])
{
	fastio;
	int n, k;cin >> n >> k;
	G = vvi (n+1,vi ());
	d = vi (n+1,0);
	d2 = vi (n+1,0);

	fr(i,0,n-1){
		int u,v;cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	std::vector<ii> v;
	fr(i,1,n+1){
		v.pb({d[i]+d2[i],i});
	}
	sort(v.begin(),v.end());

	fr(i,0,k){
		d[v[i].S]=INT_MIN;
		// cout << v[i].S << " F " << v[i].F << endl;;
	}
	// cout << endl;
	dfs2(1,0);
	cout << ans << endl;

	
	return 0;
}