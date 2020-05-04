#include <bits/stdc++.h>
using namespace std;


int min_umbrella(vector<int> umb, int cap) {
	int n = umb.size();
	int inf = 2000;
	vector< vector< int > > dp( n, vector<int> (cap+1, inf) );
	// dp[0] = 0;
	for(int i = 0; i < n; ++i) {
		int curr = umb[i];
		dp[i][curr] = 1;
		if(i > 0) {
			for(int j = 0; j < cap + 1; ++j)
				dp[i][j] = min(dp[i][j],dp[i-1][j]);
			for(int j = curr+1; j < cap + 1; ++j)
				dp[i][j] = min(dp[i-1][j-curr]+1,dp[i][j]);
		}
	}
	//assuming umbrellas are unique

	return dp[n-1][cap] >= inf ? -1 : dp[n-1][cap];

}




int main(int argc, char const *argv[])
{
	
	std::vector<int> umb({2,4});
	int req = 4;
	cout << min_umbrella(umb, req) << endl;

	return 0;
}