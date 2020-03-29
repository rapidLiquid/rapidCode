#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
 

 // START FROM HERE

std::set<string> tok(const string& s) {
	string tmp = "";
	std::set<string> toks;
	for(char c : s) {
		if(c >= 'A' && c <= 'Z') c += ('a' - 'A');
		else if (c >= 'a' && c <= 'z') ;
		else {
			toks.insert(tmp);
			tmp = "";
			continue;
		}
		tmp += c;
	}
	if(tmp.length())toks.insert(tmp);
	return toks;
/*
"A a Aa ABCd!" -> {"a","a","aa","abcd"}

*/
}
bool comp(pair<int,string>& a,pair<int,string>& b) {
	if(a.first > b.first) return 1;
	if(a.first == b.first) return a.second > b.second;
	return 0;
}
std::vector<string> popularNFeatures(int num, int top, std::vector<string> poss,int nreq,std::vector<string> lines) {

	map<string,int>S;
	for(string s : poss) S[s]=0;

	for(string s : lines) {
		std::set<string> toks = tok(s);
		for(string ss : toks)
			if(S.find(ss)!=S.end()) S[ss] ++;
	}
	std::vector<pair<int,string>> v;
	std::vector<string> ans;
	for(auto z : S) v.push_back({z.second,z.first});
	sort(v.begin(), v.end(),comp);
	for(int i = 0; i < min(top,(int)v.size()); ++i)
		if(v[i].first) ans.push_back(v[i].second);
	
	return ans;

}





int main(int argc, char const *argv[])
{

	
	return 0;
}