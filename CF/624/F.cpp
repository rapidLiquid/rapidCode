#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int long long 
const ll MX = 2e5+7;

ll BIT1[MX],BIT2[MX], a[MX], n;
void update(ll x, ll delta)
{
      for(; x <= n; x += x&-x)
        BIT1[x] += delta;
}
ll query(ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT1[x];
     return sum;
}
void updaten(ll x, ll delta)
{
      for(; x <= n; x += x&-x)
        BIT2[x] += delta;
}
ll queryn(ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT2[x];
     return sum;
}

// int main()
// {
//      scanf(“%d”, &n);
//      int i;
//      for(i = 1; i <= n; i++)
//      {
//            scanf(“%d”, &a[i]);
//            update(i, a[i]);
//      }

int main(int argc, char const *argv[])
{
	cin >> n;
	std::vector<pair<ll,ll> > p(n+1);
	for(ll i = 1; i <= n; ++i) {
		cin >> p[i].second;
	}
	for(ll i = 1; i <= n; ++i) {
		cin >> p[i].first;
	}
	p[0].first = INT_MAX; p[0].second = INT_MAX;
	sort(p.begin(), p.end());
	std::vector<pair<ll,ll>> p2(n+1);
	for(ll i = n; i >= 1; --i) {
		p2[i].first=p[i-1].second;
		p2[i].second=i;

	}
	p2[0].first = p2[0].second= INT_MIN;
	sort(p2.begin(), p2.end());
	long long ans = 0;
	for(ll i = 1; i<= n; ++i) {
		// cout << p2[i].first << " i " << p2[i].second << endl;
		ll N = queryn(p2[i].second-1);
		ll S = query(p2[i].second-1);
		ans += N*p2[i].first - S;
		update(p2[i].second,p2[i].first);
		updaten(p2[i].second,1);
	}
	// cout << endl;
	cout << ans << endl;

	return 0;
}