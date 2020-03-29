#include <iostream>
#include <map>
#include <set>
using namespace std;


/*
A substring is special when all the characters occur at most 2 times
let L be the current length in consideration
if we are able to find atleast one such substr 
then LETS look for higher lengths
else check for lower lengths

we are pushing all the values into the map as count
and keeping those values in set 
whose  occurences exceed 2


*/

bool f(const string& s, int k) {
	// k is the length
	// to check whether the string contains a
	// special substr of length k
	int n = s.length();
	map<char,int> cnt;
	set<char> S;
	int flag = 0;

	for(int i=0;i<k;++i) {
		cnt[s[i]] ++;
		if(cnt[s[i]] > 2)
			S.insert(s[i]);
	}
	if(!S.empty()) flag=1;

	for(int i=k;i<n;++i) {
		cnt[s[i]] ++;
		cnt[s[i-k]] --;
		if(cnt[s[i]] > 2)
			S.insert(s[i]);
		if(cnt[s[i-k]] < 3)
			S.erase(s[i-k]);
		if(S.empty()) flag=1;
	}
	return flag;

}





int main(int argc, char const *argv[])
{

	string s;
	cin >> s;
	int low = 1, high = s.length();
	while(low <= high) {
		int mid = (low + high) / 2;
		if(f(s,mid)) low=mid+1;
		else high = mid-1;
	}
	cout << low << endl;

	return 0;
}