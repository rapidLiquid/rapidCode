#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	

	int n;cin >> n;
	string s; cin >> s;
	// int z = 26;
	for(int C = 'z'; C >= 'a'; --C) 
	{
		// --z;
		for(int cnt = 0; cnt < 101; ++cnt) {
			string tmp = "";
			int nn = s.length();
			int idx = -1;
			for(int i = 0; i < nn; ++i ) {
				if(s[i]!=C)continue;
				if(i > 0 && s[i] == s[i-1]+1) {
					idx = i;
					break;
				}
				if(i < nn-1 && s[i] == s[i+1]+1) {
					idx = i;
					break;
				}
			}
			if(idx == -1) break;
			for(int i = 0; i < nn; ++i)
				if(i!=idx)tmp+=s[i];
			s = tmp;
		}
	}
	cout << n - s.length() << endl;


	return 0;
}



/**
 *
 * proof - why does this work
 * we choose the highest character that can be removed
 * we can remove the highest char without any worry
 * becoz it has no dependencies
 * BUT
 * it might happen that multiple highest char depend
 * on the same lower character 
 * like abbbb
 * here all the b's depend on the single a
 *
 */ 
