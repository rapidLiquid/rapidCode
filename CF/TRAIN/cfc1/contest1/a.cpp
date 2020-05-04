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

int p3(string& s) {
	// 3 ^ s
	// int n = s.size();
	// int S = 0;
	// fr(i,0,n){
	// 	S += s[i]-'0';
	// 	S %= 3;
	// }
	// if(S==0) return 1;
	// else if(S == 1) return 3;
	// return 9;

	int n = s.size();
	if(n==1 && s[0]=='0') return 1;
	int d = s[n-1]-'0';
	if(n>1) d += (s[n-2]-'0')*10;
	d%=4;
	if(d==0) return 1;
	if(d==1) return 3;
	if(d==2) return 9;
	return 7;
}

int p4(string& s) {
	int n = s.size();
	if(n==1 && s[0]=='0') return 1;
	else if((s[n-1]-'0')&1) return 4;
	return 6;
}


int p2(string& s) {
	int n = s.size();
	if(n==1 && s[0]=='0') return 1;
	int d = s[n-1]-'0';
	if(n>1) d += (s[n-2]-'0')*10;
	d%=4;
	if(d==0) return 6;
	if(d==1) return 2;
	if(d==2) return 4;
	return 8;
}

int main(int argc, char const *argv[])
{
	fastio;
	

// 2 -> 4 -> 8 -> 6 -> 2 -> 4 -> 8-> 6
// 3 -> 9 -> 7 -> 1 -> 3 -> 9 -> 7
// 4 -> 6 -> 4 -> 6
	string s;
	cin >> s;
	cout << (1+p2(s)+p3(s)+p4(s))%5 << endl;


	return 0;
}