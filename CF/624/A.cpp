#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
		
	int t;cin >> t;
	while(t--) {
		int from , to;
		cin >> from >> to;
		//odd add and even sub
		if(to == from) {
			cout << 0 << endl;
		}
		else if(to>from) {
			if(to&1) 
				if(from&1) cout << 2 << endl;
				else cout << 1 << endl;
			else
				if(from&1) cout << 1 << endl;
				else cout << 2 << endl;
		}
		else {
			if(to&1)
				if(from&1) cout << 1 << endl;
				else cout << 2 << endl;
			else
				if(from&1) cout << 2 << endl;
				else cout << 1 << endl;
		}

	}
	return 0;
}