#include <bits/stdc++.h>
using namespace std;

map<int,long long> m;

int main(int argc, char const *argv[])
{
	
	int n;cin >> n;
	std::vector<int> b(n);
	for(int i = 0; i < n; ++i) cin >> b[i];	
	long long  ans = -1;

	for(int i = 0; i < n; ++i) {
		if(m.find(b[i]-i)==m.end()) m[b[i]-i] = b[i];
		else m[b[i]-i] += b[i];
		ans = max(ans, m[b[i]-i]);
	}
	cout << ans << endl;

	return 0;
}