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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int mn = (a-b)*n;
		int mx = (a+b)*n;
		// int from = (c - d)/n, to = (c + d)/n;
		
		if(mn>=(c-d)&&mn<=(c+d)) cout << "Yes";
		else if(mx>=(c-d)&&mx<=(c+d)) cout << "Yes";
		else if(mn<(c-d)&&mx>(c+d))cout<<"Yes";
		else cout << "No";
		cout <<endl;


	}


	return 0;
}