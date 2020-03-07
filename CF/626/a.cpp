#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		std::vector<int> v(n);
		for(int i = 0; i < n; ++i) cin >> v[i];
		int idx = -1;
		for(int i = 0; i< n; ++i) {
			if(v[i]%2==0) { idx = i; break; }
		}
		if(idx!=-1) cout << 1 << endl << idx+1 << endl;
		else {

			if(n>1) cout << 2 << endl << 1 << " " << 2 << endl;
			else cout<<-1<<endl;
		}
	}

	return 0;
}