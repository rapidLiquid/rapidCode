#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int ans = 0;

		if(a) { ans++; a--; }
		if(b) { ans++; b--; }
		if(c) { ans++; c--; }
		std::vector<int> v({a,b,c});
		sort(v.rbegin(), v.rend());

		if(v[0]>0 && v[1]>0) { ans++; v[0]--; v[1]--; }
		// sort(v.rbegin(), v.rend());
		if(v[0]>0 && v[2]>0) { ans++; v[0]--; v[2]--; }
		// sort(v.rbegin(), v.rend());
		if(v[2]>0 && v[1]>0) { ans++; v[2]--; v[1]--; }
		// sort(v.rbegin(), v.rend());
		if(v[0]>0 && v[1]>0 && v[2]>0) { ans++; v[0]--; v[1]--; }
		// sort(v.rbegin(), v.rend());
		// if(b>0 && c>0) { ans++; b--; c--; }
		// if(a>0 && c>0) { ans++; a--; c--; }
		// if(a>0 && c>0 && b>0) { ans++; a--; c--; b--;}
		cout << ans << endl;
	}





	return 0;
}