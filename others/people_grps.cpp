#include <iostream>
#include <vector>
using namespace std;
 
typedef long long int LL;
#define vL vector<LL>
#define vvL vector<vL>

LL go(int prev, int grps, int people, vector<vvL>& dp) {


	if(people < 0) return 0;
	if(grps == 0) {
		if(people == 0) return 1;
		return 0;
	}
	if(dp[prev][grps][people]!=-1) return dp[prev][grps][people];
	LL ans = 0;
	for(int i = prev; i < people+1; ++i) ans += go(i,grps-1,people-i, dp);
	return dp[prev][grps][people]=ans;

}




int main(int argc, char const *argv[])
{
	
	int n, m;
	cin >> n >> m;
	std::vector<vvL> dp(201, vvL (201, vL (201, -1)));
	cout << go(1,m,n, dp) << endl;


	return 0;
}