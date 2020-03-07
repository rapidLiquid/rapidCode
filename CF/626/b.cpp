#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n, m, k;
	cin >> n >> m >> k;

	std::vector<int> B(m);
	std::vector<int> L(n);
	for(int i = 0; i < n; ++i) {
		cin >> L[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> B[i];
	}

	
	set<pair<int,int>>S;
	for(int i  = 1; i <= sqrt(k); ++i) {
		if(k%i)continue;
		S.insert({i,k/i});
		S.insert({k/i,i});
	}
	long long ans = 0;
	for(auto z : S) {
		int l = z.first; int b = z.second;
		int pb=0;
		int rb=0;
		for(int i = 0; i < m; ++i) {
			if(B[i])++rb;
			else rb=0;
			if(rb>=b)pb++;
		}
		int rl=0;
		for(int i = 0; i < n; ++i) {
			if(L[i])++rl;
			else rl=0;
			if(rl>=l) ans += pb;
		}
	}
	cout << ans << endl;
	return 0;
}