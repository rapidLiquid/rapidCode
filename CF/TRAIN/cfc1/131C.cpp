#include <bits/stdc++.h>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define pb push_back
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;

typedef pair< LL, LL> ll;
typedef vector< LL> vl;
typedef vector< ll> vll;
typedef vector< vl> vvl;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;
	
	vvl C(100, vl (100));

	fr(i,0,100) {
		fr(j,0,i+1) {
			// nCr = n-1Cr + n-1Cr-1
			if(j==0)C[i][j] = 1;
			else if(i==j)C[i][j] = 1;
			else C[i][j] = C[i-1][j] + C[i-1][j-1];
			// cout << " i j " << i << " " << j << " " << C[i][j] << endl;
		}
	}


	int n, m, t;cin >> n >> m >> t;
	
	LL ans = 0;
	fr(i,4,n+1) {
		fr(j,1,m+1){
			if(i+j==t) {
				// cout << " i j " << C[n][i] << " " << C[m][j] << endl;
				ans += (C[n][i] * C[m][j]);
			}

		}
	}
	cout << ans << endl;


	return 0;
}