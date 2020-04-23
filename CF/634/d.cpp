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

char inc(char x) {
	int d = x-'0';
	d++;
	if(d==10)d=1;
	return (char)(d+'0');
}
int main(int argc, char const *argv[])
{
	fastio;
	
	t_times {
		string s[9];
		fr(i,0,9)cin>>s[i];
		s[0][0] = inc(s[0][0]);
		s[1][3] = inc(s[1][3]);
		s[2][6] = inc(s[2][6]);
		
		s[3][1] = inc(s[3][1]);
		s[4][4] = inc(s[4][4]);
		s[5][7] = inc(s[5][7]);
		
		s[6][2] = inc(s[6][2]);
		s[7][5] = inc(s[7][5]);
		s[8][8] = inc(s[8][8]);
		// cout << endl;
		fr(i,0,9)cout<<s[i]<<endl;
	}


	return 0;
}