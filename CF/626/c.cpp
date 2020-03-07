#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n; cin >> n;
	string s; cin >> s;




	stack<int> stk;
	int cnt = 0;
	int ans = 0;


	for(int i = 0; i < n; ++i) {

		if(s[i] == '(') ++cnt;
		else --cnt;

		if(stk.empty()) stk.push(i);
		else {
			if(s[i] == '(') stk.push(i);
			else if(s[stk.top()] == '(') stk.pop();
			else stk.push(i);
		}
		if(cnt == 0) {
			std::vector<int> v;
			while(!stk.empty()) { 
				v.push_back(stk.top());
				stk.pop();
			}
			reverse(v.begin(), v.end());
			if((int)v.size()) {
				int k = (int)v.size();
				ans += (v[k-1] - v[0] + 1);
			}
		}

	
	}

	if(cnt!=0) puts("-1");
	else{
		cout << ans << endl;
	}



	return 0;
}