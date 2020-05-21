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
	

	t_times {
		int n, m;cin >> n>> m;
		vvl mat(n,vl (m));
		vvl dp(n,vl (m));
		fr(i,0,n)fr(j,0,m)cin>>mat[i][j];

		dp[n-1][m-1] = mat[i-1][j-1];
		rev(i,n-1,0){
			rev(j,m-1,0){
				if(i==n-1&&j==m-1)continue;
				
				LL rc = LLONG_MAX;
				LL dc = LLONG_MAX;
				LL c2r = -1;
				LL c2d = -1;
				
				if(j+1<m) {
					LL change = dp[i][j+1];
					c2r = mat[i][j+1]-1;
					if(mat[i][j] >= c2r)
						change += (mat[i][j] - c2r);
					else {
						int blocks = m-1-j-1+n-i; // manhattan
						change += blocks*(c2r+1-mat[i][j+1]);
					}
					rc = change;
				}
				if(i+1<n) {
					LL change = dp[i+1][j];
					c2d = mat[i+1][j]-1;
					if(mat[i][j] >= c2d)
						change += (mat[i][j] - c2d);
					else {
						int blocks = m-j+n-i-2; // manhattan
						change += blocks*(c2d+1-mat[i+1][j]);
					}
					dc = change;
				}

				if(rc < dc)


			}
		}



	}

	return 0;
}