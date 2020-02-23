#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n;
	cin >> n;
	std::vector<pair<int,int>> p(n);	
	
	map<int,int> cnt;
	for(int i = 0; i < n; ++i) { 
		cin >> p[i].second;
		cnt[p[i].second]++;
	}
	for(int i = 0; i < n; ++i) cin >> p[i].first;

	stack<int> stk2;
	stack<int> stk;
	set<int> to;
	// this set will be populated
	//how to pop to?????
	// keep one and push the rest further
	
	for(auto z : cnt) stk2.push(z.first);
	
	while(!stk2.empty()) {
		stk.push(stk2.top());
		stk2.pop();
	}
	while(!stk.empty()) {
		int now = stk.top();
		to.insert(now);
		stk.pop();
		// cout << now << " cm " << cnt[now] << endl;
		if(cnt.count(now) && cnt[now]>1) {
			cnt[now+1]+=cnt[now]-1;
			if(stk.empty())
				stk.push(now+1);
			if(!stk.empty() && stk.top() != now+1)
				stk.push(now+1);
		}
	}

	sort(p.begin(), p.end());
	long long cost=0;

	for(int i = n-1; i>=0; --i) {
		int from = p[i].second;
		int z = *to.lower_bound(from);
		to.erase(z);
		cost += (z-from)*1ll*p[i].first;
	}

	cout << cost << endl;

	return 0;
}

/*
logic

let there be n unique numbers that we need at the end
populate those numbers by some method X

let there be two items a,b and we need to move them to c,d 
let the prices be p1, p2

a,b -> c,d
p2 > p1 and c < d
c1 = (d-a)*p1 + (c-b)*p2 => c*p2 + d*p1
c2 = (d-b)*p2 + (c-a)*p1 => d*p2 + c*p1
since d > c and p2 > p1 so c2 > c1
so we need to prioritize on the basis of price
and shift to the nearest possible

VIMP NOTE - dont care about a,b ORDER
	since COST INDIE of that
	(becoz of this unable to solve in contest)

if p1 == p2 dont care

method X

make a map
start populating the to array
keep one push the rest
use stack to keep track of the different ranges


*/