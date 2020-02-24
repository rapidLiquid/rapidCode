#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	
	int t;cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		// std::vector<int> v(n);
		int v[n];
		for(int i = 0; i < n; ++i) cin>>v[i];
		std::vector<int> p(m);
		for(int i = 0; i < m; ++i) cin>>p[i];
		sort(p.begin(), p.end());

		int from = p[0]-1;
		for(int i = 1; i < m; ++i) {
			if(p[i] == p[i-1]+1) continue;
			int to = p[i-1]+1;
			sort(v+from,v+to);
			from = p[i]-1;
		}
		int to = p[m-1]+1;
		sort(v+from,v+to);
		int flag = 1;
		for(int i = 1; i < n; ++i)
			if(v[i] < v[i-1]) flag = 0;
		puts(flag?"YES":"NO");


	}

	return 0;
}