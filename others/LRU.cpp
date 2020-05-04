#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	set<pair<int,int>>S;
	S.insert({1,2});
	S.insert({1,3});
	S.insert({1,4});
	S.insert({2,1});
	S.insert({3,-1});

	for(auto x : S) {
		cout << x.first << " " << x.second << endl;
	}

	auto z = S.lower_bound({3,INT_MIN});
	if(z != S.end()) {
		cout << "YESSS\n";
		auto zz = *z;
		cout << zz.first << " " << zz.second << endl;
	}
	unordered_map<int,int>m;
	m[2]=3;
	m.erase(2);
	cout << m.count(2) << endl;
	return 0;
}