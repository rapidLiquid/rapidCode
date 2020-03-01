#include <bits/stdc++.h>
using namespace std;


// useless
int solve(string s, map<string, int>& dp) {

	if(dp.find(s)!=dp.end()) return dp[s];
	int ans = 0;
	string tmp = "";
	// int idx=-1;
	set<int>S;
	int n = s.length();
	for(int i  = 0; i < n; ++i) {
		if(i < n-1)
			if(s[i+1]+1 == s[i]) {
				S.insert(i);
			}
		if(i > 0)
			if(s[i-1]+1==s[i]){
				S.insert(i);
			}
	}

	for(int i : S){
		string tmp = "";
		for(int j = 0; j < n; ++j) {
			if(j == i)continue;
			tmp += s[j];
		}
		ans = max(ans, 1+solve(tmp,dp));
	}
	return dp[s] = ans;


}



int main(int argc, char const *argv[])
{
	string s;
	int n;cin >> n; cin >> s;
	// map<string, int> dp;
	// cout << solve(s, dp) << endl;
	// int cnt = 0;
	// int zz = 26;
	// for(int j = 0; j < 5000; ++j) {
	// 	zz--;
	// 	zz%=26;zz+=26;zz%=26;
	// 	char C = zz + 'a';
	// 	string tmp="";
	// 	int n = (int)s.length();
	// 	// cout << " n " << n << endl;
	// 	int idx = -1;
		
	// 	for(int i = n-1; i >= 0; --i) {
	// 		if(s[i]!=C)continue;
	// 		if(i < n-1)
	// 			if(s[i+1]+1 == s[i]) {
	// 				idx = i;
	// 				break;
	// 			}
	// 		if(i > 0)
	// 			if(s[i-1]+1==s[i]){
	// 				idx = i;
	// 				break;
	// 			}
	// 	}

	// 	// cout << "ok\n";
	// 	// if(idx == -1) break;

	// 	if(idx!=-1)++cnt;
	// 	for(int i = 0; i < n; ++i) {
	// 		if(i == idx) continue;
	// 		tmp += s[i];
	// 	}
	// 	// cout << tmp << " idx " << idx << endl;
	// 	s = tmp;

	// }
	// // cout << s << endl;
	// cout << cnt << endl;


	// set<int> S;
	// for(int i = 0; i < n; ++i)S.insert(i);

	// for(int i = 1; i < n; ++i) {
	// 	auto z = S.find(i);
	// 	if(z ==  S.end()) continue;
	// 	--z;
	// 	if(s[*z] + 1 == s[i]) S.erase(i);
	// }

	// for(int i = n-2; i >= 0; --i) {
	// 	auto z = S.lower_bound(i+1);
	// 	if(z == S.end()) continue;
	// 	if(s[*z]+1 == s[i]) S.erase(i);
	// }
	// for(int i : S) cout << i << " ";
	// 	cout << endl;
	// cout << n - (int)S.size() << endl;

	int cnt = 0;
	std::vector<int> rem(n,0);


	int zz = 26;
	for(int i = 0; i < 5000; ++i) {
		--zz;
		zz += 26;
		zz %= 26;
		char C = zz + 'a';
		for(int i = 1; i < n; ++i) {
			if(s[i]!=C) continue;
			if(rem[i]) continue;
			for(int j = i-1; j >= 0; --j) {
				if(s[j]+1==s[i]) rem[i] = 1;
				if(!rem[j])break;
			}
			// break;
		}
		for(int i = n-2; i >= 0; --i) {
			if(s[i]!=C) continue;
			if(rem[i]) continue;
			for(int j = i+1; j < n; ++j) {
				if(s[j]+1==s[i]) rem[i] = 1;
				if(!rem[j]) break;
			}
			// break;
		}
	}
	// for(int i : rem)cout << i << " ";
	// 	cout << endl;
	for(int i : rem) if(i) ++cnt;
		cout << cnt <<endl;


	
	return 0;
}

// recursion timed out
// doing from back useless since 2 way deps
// doing from front useless since 2 way deps
// doing from front by actually removing  the character useless
 	//  since rem characTER wont help in knowing the deps
// doing from back in reverse order is somwhat useful since
	// the least deps are removed first
 

// DID THIS----->
// doing multiple times for all characters in reverse order
// checking if possible to remove that charac from back or from front
