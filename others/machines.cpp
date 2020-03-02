/*

machines are given with reliability and speed
we need to maximise (sum of speed) * reliability

we can select at most m machines
reliability of the config = minimum reliability of all the selected machnines

idea
-----

sort the machines according to reliability
start from the end

curr_rel = min(curr_rel, rel[i])
	now when the reliability changes, 
	we need to remove the min reliability machine from the set
	and select the current speed of the machine

or when the reliability doesn't change, just pick the max speed machines only
maintain a running sum called   "curr_sum"



*/

#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


long long solve(int m, std::vector<int> speed, std::vector<int> reliability) {
	int n = (int)speed.size();
	std::vector<pair<int,int>> v;
	for(int i = 0; i < n; ++i) v.push_back({reliability[i], speed[i]});
	sort(v.begin(), v.end());
	set<int> S;
	map<int,int> cnt;
	int curr_min = INT_MAX;
	int curr_sum = 0;
	long long ans = 0;
	for(int i = n-1; i >= 0; --i) {
		int rel = v[i].first;
		int spe = v[i].second;
		if(S.size() < m) {
			curr_sum += spe;
			curr_min = rel;
			cnt[spe]++;
			S.insert(spe);
			ans = max(ans, curr_sum * 1ll * curr_min);
		}
		else if(S.size() == m) {
			int mn = *S.begin();
			curr_min = min(rel, curr_min);
			curr_sum -= mn;
			curr_sum += spe;
			cnt[mn]--;
			cnt[spe]++;
			S.erase(mn);
			S.insert(spe);
			ans = max(ans, curr_sum * 1ll * curr_min);
		}
	}
	return ans;
}






int main(int argc, char const *argv[])
{


	std::vector<int> speed({12,112,100,13,55});
	std::vector<int> rel({31,4,100,55,50});
	cout << solve(3, speed, rel) << endl;

	return 0;
}