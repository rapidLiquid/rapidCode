
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	/* code */

	int t;cin >> t;
	while(t--) {
		int n;
		cin >> n;
		// std::vector<int> b(n);

		// std::vector<int> vis(2n+1,0);
		std::vector<pair<int,int> > p(n);
		set<int> S;
		for(int i = 1; i < 2*n + 1; ++i) S.insert(i);
		for(int i = 0; i < n; ++i) {
			cin >> p[i].first;
			p[i].second=i+1;
			S.erase(p[i].first);
			// vis[p[i].first]=1;
		}
		// sort(p.begin(), p.end());
		// int curr = 2n;
		std::vector<int> ans(2*n);
		// cout << "here\n";
		int flag = 1;
		for(auto x: p) {
			int pos = x.second;
			int val = x.first;
			auto z = S.lower_bound(val);
			// --z;
			if(z==S.end() ||
				 (z!=S.end()&&(*z) <= val)
				 ) {
				flag = 0;break;
			}
			ans[pos*2-1-1] = val;
			ans[pos*2-1] = (*z);
			S.erase(z);
		}

		if(flag) {
			for(int i : ans)cout << i << " ";
				cout << endl;
		} else cout << -1 << endl;

	}



	return 0;
}