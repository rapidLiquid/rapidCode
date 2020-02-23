#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int t;
	cin >> t;
	while(t--) {
		int bus, tram, money;
		cin >> bus >> tram >> money;
		string s;cin >> s;
		std::vector<int> v;
		v.push_back(0);
		int n = s.length();
		for(int i = 1; i < n; ++i) {
			if(s[i] == s[i-1]) continue;
			v.push_back(i);
		}
		if(v.back() == n-1) v.pop_back();
		int last = n-1;
		reverse(v.begin(), v.end());
		
		for(int i : v) {
			int price = s[i]=='A'?bus:tram;
			if(money >= price) {
				money -= price;
				last = i;
			} else break;
		}
		cout << last +1<< endl;


	}
	return 0;
}