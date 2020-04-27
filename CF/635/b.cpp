#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define pb push_back
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE


int main(int argc, char const *argv[])
{
	fastio;
	t_times {
		int x, n, m;
		cin >> x >> n >> m;
		// x-=10*m;
		if(x<=10*m)cout << "YES\n";
		// if(x<=0)cout<<"YES\n";
		else {
			fr(i,0,n){
				x/=2;
				x+=10;
			}
			x-=10*m;
			if(x>0)cout<<"NO\n";
			else cout << "YES\n";
		}
		

	}
	
	return 0;
}