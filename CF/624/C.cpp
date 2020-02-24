#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
		
	int t;cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		string s;cin >> s;
		std::vector<int> r(m);
		for(int i = 0; i < m; ++i) cin >> r[i];
		vector<int> pref(n+1,0);
		for(int R: r) { pref[0]++; pref[R]--; }
		std::vector<int> res(26,0);
		for(int i = 0; i < n; ++i) {
			if(i>0)pref[i] += pref[i-1];
			res[s[i]-'a'] += pref[i]+1;
		}
		for(int i : res) cout << i << " ";
		cout << endl;


	}
	return 0;
}