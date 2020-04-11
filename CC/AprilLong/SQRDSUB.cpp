#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
	return abs(x) == 2 || abs((x/2)%2)==1;
}

int main(int argc, char const *argv[])
{
	// cout << ((-3)%2) << endl;

	int t;cin >> t;
	while(t--) {
		int n; scanf("%d", &n);
		std::vector<int> v(n);
		std::vector<int> p({0});
		for(int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			if(v[i]%2==0) p.push_back(i+1);
		}
		p.push_back(n+1);
		int l = p.size();
		long long ng = 0;
		for(int i = 1; i < l-1; ++i) {
			if(!check(v[p[i]-1]))continue;
			int pre = p[i]-p[i-1];
			int nex = p[i+1]-p[i];
			ng += (nex*1ll*pre);
		}
		// ng >>= 1;
		long long res = (n*1ll*(n+1))/2;
		res -= ng;
		cout << res << endl;


	}
	return 0;
}