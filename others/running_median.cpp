#include <bits/stdc++.h>
using namespace std;


#define ii pair<int,int>

class Median
{
private:
	set<ii> min_heap; set<ii> max_heap;
	void adjust() {
		// max heap size should be greater than min  heap size
		int szl = min_heap.size(), szr = max_heap.size();
		if(szl + 2 == szr) {
			auto z = max_heap.begin();
			min_heap.insert(*z);
			max_heap.erase(z);
		} else if(szl == szr + 1) {
			auto z = min_heap.end(); --z;
			max_heap.insert(*z);
			min_heap.erase(z);
		}
		// supports removal
	}

public:
	Median() {
		this->min_heap.clear();
		this->max_heap.clear();
	}
	int get_median() {
		return max_heap.begin()->first;
	}
	void add(int index, int x) {
		//wrong
		if(min_heap.lower_bound({x,-1}) == min_heap.end())
			max_heap.insert({x,index});
		else min_heap.insert({x,index});
		adjust();
	}
	void remove(int index, int x) {
		ii z = {x,index};
		if(min_heap.find(z)!=min_heap.end())
			min_heap.erase(z);
		else max_heap.erase(z);
		adjust();
	}
	~Median(){};
	
};


vector<int> solve(vector<int>& arr, int k) {

	// find median for all subarrays of size k
	std::vector<int> ans;
	int n = arr.size();
	Median med;
	for(int i = 0; i < min(n,k); ++i)
		med.add(i,arr[i]);
	ans.push_back(med.get_median());
	// med.show();
	for(int i = k; i < n; ++i) {
		med.remove(i-k,arr[i-k]);
		med.add(i,arr[i]);
		ans.push_back(med.get_median());
		// med.show();
	}
	return ans;

}

int main(int argc, char const *argv[])
{
	

	vector<int> arr({1,2,3,4,5,6,7,8,1,2,3});
	int k = arr.size();

	std::vector<int> v = solve(arr,k);
	for(int i : v)cout << i << " ";
	cout << endl;

	return 0;
}