#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	

	vector<int> div[20014];
	// vector<vector<int> > div2(30004, vector<int> ());
	for(int i = 1; i < 20014; ++i) {
		set<int>S;
		for(int j = 1; j*j<=i; ++j) {
			if(i%j==0)S.insert(j);
			if(i%j==0)S.insert(i/j);
		}
		div[i] = std::vector<int> (S.begin(), S.end());
	}


	int t;cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int fo=-1,fi = -1, fa=-1, mn = INT_MAX;

		for(int x = 1; x <= 2e4+10; ++x) {
			int n1 = (c/x)*x, n2 = (c/x+1)*x;
			int d3 = min(abs(n1-c),abs(n2-c));
			int fotmp;
			if(abs(n1-c) < abs(n2-c)) fotmp = (c/x)*x;
			else fotmp = (c/x+1)*x;

			int d2 = abs(x-b);

			auto z = lower_bound(div[x].begin(), div[x].end(),a);
			int d1 = abs((*z)-a);
			int fatmp = (*z);
			if(z!=div[x].begin())z--;
			if(abs((*z)-a) < d1){
				d1 = abs((*z)-a);
				fatmp=(*z);
			}


			if(d1 + d2 + d3 < mn) {
				mn = d1 + d2 + d3;
				fo = fotmp;
				fi = x;
				fa = fatmp;
			}

		}
		cout << mn << endl;
		cout << fa << " " << fi << " " << fo << endl;
	}
	return 0;
}
