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
 
const LL mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int numbering = 0; 	
int node_index = 0; 
vi euler;
vvi csum;
vi fst;
unordered_map<int,int> mpr;
vi val;
vvi G;
vi Primes;
vi lvl;
vi par;
// numbering for node mapping
// node_index for euler mapping , for finding fst

vi _sieve(int MX) {
	vi v(MX,0);
	for(int i = 2; i < MX; ++i) {
		if(v[i])continue;
		for(int j = i; j < MX; j+=i) v[j] = i;
	}
	return v;
}

int _cnt_primes(vi& arr) {
	int n = arr.size();
	int idx = 0;
	fr(i,0,n) {
		int tmp = arr[i];
		while(tmp>1) {
			if(!mpr.count(Primes[tmp]))
				mpr[Primes[tmp]]=idx++;
			tmp /= Primes[tmp];
		}
	}
	return idx;
}

void dfs(int u, int pr) {
	
	// mno[u]=numbering++;
	
	euler.pb(u); // bug this was
	int tmp = val[u];
	while(tmp>1) {
		int cp = Primes[tmp];
		csum[node_index][mpr[cp]]++;
		tmp /= cp;
	}
	fst[u]=node_index++;
	if(u>0){
		lvl[u]=lvl[pr]+1;
		par[u] = pr;
	}
	
	for(int v : G[u]) {
		if(v == pr) continue;
		dfs(v,u);
	}
	euler.pb(u);
	tmp = val[u];
	while(tmp>1) {
		int cp = Primes[tmp];
		csum[node_index][mpr[cp]]--;
		tmp /= cp;
	}
	node_index++;

}

LL mul(LL x, LL y) { x%=mod; y%=mod; return (x*y)%mod; }

LL getF(int l, int r, int m, int c) {
	// c is the prime limit
	LL ans = 1;
	vi tmp(c,0);

	int x = min(l,m); int y = max(l,m);

	for(int i = 0; i < c; ++i) {
		int num = csum[y][i];
		if(x>0) num -= csum[x-1][i];
		tmp[i] += num;
	}

	x = min(r,m); y = max(r,m);

	fr(i,0,c) {
		int num = csum[y][i];
		if(x>0) num -= csum[x-1][i];
		tmp[i] += num;
	}

	fr(i,0,c) {
		int z = csum[m][i];
		if(m>0) z-=csum[m-1][i];
		tmp[i] -= z;
		tmp[i]++;
		ans = mul(ans, tmp[i]);
	}

	return ans;
}

int find_lca(int u, int v) {
	int d = lvl[u] - lvl[v];
	if(d<0) {swap(u,v); d*=-1;}
	while(d) {u=par[u]; --d;}
	if(u==v)return u;
	while(par[u]!=par[v]){
		u=par[u];
		v=par[v];
	}
	return par[u];
} 

int main(int argc, char const *argv[])
{
	const int MX = 1e6+7;
	Primes = _sieve(MX);
	// fastio;
	t_times {
		euler.clear();
		// mno.clear();
		mpr.clear();
		// rmpr.clear();
		numbering = 0; 
		node_index = 0;

		int n; scanf("%d",&n);
		G = vvi(n, vi ());
		val = vi(n);
		fst = vi(n,-1);
		lvl = vi(n,0);
		par = vi(n,0);
		fr(i,0,n-1) {
			int u,v;
			scanf("%d%d",&u,&v);
			--u,--v;
			G[u].pb(v);
			G[v].pb(u);
		}
		fr(i,0,n) scanf("%d", &val[i]);
		
		int c = _cnt_primes(val);
		csum = vvi (2*n,vi (c,0));
		dfs(0,0);
		//populate cum sum
		// fr(j,0,c) {
		// 	fr(i,0,2*n)cout << csum[i][j] << " ";
		// 	cout << endl;
		// }
		fr(i,1,2*n) {
			fr(j,0,c) {
				csum[i][j] += csum[i-1][j];
			}
		}

		int q; scanf("%d",&q);
		while(q--) {
			int u, v; scanf("%d%d",&u,&v);
			--u,--v;
			int l = fst[u];
			int r = fst[v];
			if(l>r)swap(l,r);
			if(n>2000) puts("-1");
			else {
				int w = find_lca(u,v);
				int m = fst[w];
				printf("%lld\n",getF(l,r,m,c));
			}
		}

	}



	return 0;
}