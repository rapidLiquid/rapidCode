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

LL FD(vi& x,vi& y, vi& z){
	LL ans = LLONG_MAX;
	for(int i:x) {
		auto kk=lower_bound(all(y),i);
		if(kk==y.end())--kk;
		vi tmp({*kk});
		if(kk!=y.begin()){
			--kk;
			tmp.pb(*kk);
		}
		// if(kk!=y.begin()){
		// 	--kk;
		// 	tmp.pb(*kk);
		// }
		for(int j:tmp) {
			auto kk2=lower_bound(all(z),j);
			if(kk2==z.end())--kk2;
			vi tmp2({*kk2});
			if(kk2!=z.begin()){
				--kk2;
				tmp2.pb(*kk2);
			}
			// if(kk2!=z.begin()){
			// 	--kk2;
			// 	tmp2.pb(*kk2);
			// }
			for(int yo : tmp2) {
				LL tmpp = i*1ll*i + j*1ll*j + yo*1ll*yo
					- (i*1ll*j + j*1ll*yo + i*1ll*yo);
				ans = min(ans,2*tmpp);
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	fastio;
	t_times {
		int nr,ng,nb;
		cin >> nr >> ng >> nb;

		vi x(nr);
		vi y(ng);
		vi z(nb);
		fr(i,0,nr) cin >> x[i];
		fr(i,0,ng) cin >> y[i];
		fr(i,0,nb) cin >> z[i];
		sort(all(x));
		sort(all(y));
		sort(all(z));
		LL ans = LLONG_MAX;
		
		ans = min(ans, FD(x,y,z));
		ans = min(ans, FD(x,z,y));


		ans = min(ans, FD(y,x,z));
		ans = min(ans, FD(y,z,x));

		ans = min(ans, FD(z,y,x));
		ans = min(ans, FD(z,x,y));

		cout << ans << endl;
	}

	return 0;
}