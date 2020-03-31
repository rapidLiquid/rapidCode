#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
 

 // START FROM HERE

#define vi std::vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define F first
#define S second
int widestGap(int len, vi st, vi en) {

	int n = (int)st.size();
	vii intervals;
	
	for(int i = 0; i < n; ++i) intervals.push_back({st[i],en[i]});
	
	stack< ii > stk;
	sort(intervals.begin(), intervals.end());

	for(int i = 0; i < n; ++i) {
		ii curr = intervals[i];
		if(stk.empty()) stk.push(curr);
		else {
			ii t = stk.top();
			if(curr.F > t.S) stk.push(curr);
			else {
				stk.pop();
				ii nt = { t.F , max(t.S, curr.S) };
				stk.push(nt);
			}
		}
	}
	
	ii prev = stk.top();
	int res = len - prev.S;
	stk.pop();
	while(!stk.empty()) {
		ii now = stk.top();
		res = max(res, prev.F - now.S - 1);
		prev = now;
		stk.pop();
	}
	res = max(res, prev.F-1);
	return res;



}


int main(int argc, char const *argv[])
{


	int len;cin >> len;
	int n;cin >> n;
	std::vector<int> st(n);
	std::vector<int> en(n);
	for(int i = 0; i < n; ++i) cin >> st[i];
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> en[i];
		cout << widestGap(len, st,en)<<endl;

	return 0;
}