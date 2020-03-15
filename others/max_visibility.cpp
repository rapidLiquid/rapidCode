#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
#define t_times int t; cin >> t; while(t--)
typedef long long LL;
 // START FROM HERE

int getWinner(std::vector<int> h) {
	int n = (int)h.size();

	std::vector<int> front(n); // number of drivers in front
	std::vector<int> behind(n); // number of drivers behind
	std::vector<LL> visibility(n);
	std::stack<int> stk;

	// finding the front
	for(int i = 0; i < n; ++i) {
		if(stk.empty()) stk.push(i);
		else {
			while(!stk.empty() && h[stk.top()] <= h[i]) {
				front[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}
	}
	while(!stk.empty()) {
		front[stk.top()] = n-1;
		stk.pop();
	}

	//finding behind
	for(int i = n-1; i>=0; --i) {
		if(stk.empty()) stk.push(i);
		else {
			while(!stk.empty() && h[stk.top()] <= h[i]) {
				behind[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}
	}
	while(!stk.empty()) {
		behind[stk.top()] = 0;
		stk.pop();
	}

	// visibility set
	for(int i = 0; i < n; ++i) {
		int b = i - behind[i];
		int f = front[i] - i;
		visibility[i] = (i+1)*1ll*(b+f);
	}
	int idx = 0;
	for(int i = 0; i < n; ++i) {
		if(visibility[i] > visibility[idx]) idx = i;
		// cout << i << " v " << visibility[i] << endl;
	}
	return idx + 1;
}

int main(int argc, char const *argv[])
{
	
	t_times {
		int n; cin >> n;
		std::vector<int> h(n); // height
		for(int i = 0; i < n; ++i) cin >> h[i];
		cout << getWinner(h) << endl;
	}

	return 0;
}