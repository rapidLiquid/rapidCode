#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define vi vector<int>
#define vii vector<ii>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define LL long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(int argc, char const *argv[])
{
	fastio;
	int n;
	cin >> n;
	vii a(n);
	fr(i,0,n) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(all(a));

	set<int>Set;Set.insert(-1);Set.insert(n);
	LL ans = 0;
	fr(i,0,n) {
		int nxt = *Set.upper_bound(a[i].S);
		int pre = *(--Set.lower_bound(a[i].S));
		ans -= (nxt-a[i].S)*1ll*(a[i].S-pre)*a[i].F;
		Set.insert(a[i].S);
	}
	reverse(all(a));
	Set.clear(); Set.insert(-1); Set.insert(n);
	fr(i,0,n) {
		int nxt = *Set.upper_bound(a[i].S);
		int pre = *(--Set.lower_bound(a[i].S));
		ans += (nxt-a[i].S)*1ll*(a[i].S-pre)*a[i].F;
		Set.insert(a[i].S);
	}

	cout << ans << endl;






	return 0;
}




/*

earlier was using this approach , for every element find the 
prev and next highest and then for also min

now that element will occur in the subsegments between the next
and prev max as an additive element and as a negated element
for the min case 

but but but this will give us lower counts / extra counts

as when we consider like

1 4 1
answer should be 9 but this approach will give us 8

*/
