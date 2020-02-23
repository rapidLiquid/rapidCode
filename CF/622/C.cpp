#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	
	int n; cin >> n;

	std::vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];

	long long res = 0;
	int idx = -1;
	for(int i = 0; i < n; ++i) {
		int c = v[i];
		long long tmp = c;
		int mn = c;
		for(int j = i+1; j < n; ++j) {
			mn = min(mn, v[j]);
			tmp += mn;
		}
		mn = c;
		for(int j = i-1; j >= 0; --j) {
			mn = min(mn, v[j]);
			tmp += mn;
		}
		if(tmp > res) {
			res = tmp;
			idx = i;
		}
		// res = max(res, tmp);
	}

	int mn = v[idx];
	for(int j = idx+1; j < n; ++j) {
		mn = min(mn, v[j]);
		v[j] = mn;
		// tmp += mn;
	}
	mn = v[idx];
	for(int j = idx-1; j >= 0; --j) {
		mn = min(mn, v[j]);
		v[j] = mn;
		// tmp += mn;
	}
	for(int i : v)cout << i << " ";
	cout << endl;

	return 0;
}