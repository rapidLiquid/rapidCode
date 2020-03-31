// https://codeforces.com/contest/349/problem/B
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
#define _parr(a, n) for(int __i = 0; __i < (int )n; __i++) cout << a[__i] << ' '; cout << '\n'
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define frn(i, st, n) for(int i = (int )st; i <= (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).begin(), (c).end()
#define mp make_pair
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
	
	int V; cin >> V;
	vi v(9);
	fr(i,0,9) cin >> v[i];
	int mn = 0;
	fr(i,1,9) if(v[i] <= v[mn]) mn = i;
	string s = ""; int t = V/v[mn];
	fr(i,0,t) s += ('0' + (mn+1));
	if(s == "") {
		cout << -1 << endl;
		return 0;
	}
	V %= v[mn];
	fr(i,0,t) {
		rev(j,8,0) if(v[j]-v[s[i]-1-'0'] <= V) {
			V -= (v[j] - v[s[i]-1-'0']);
			s[i] = '0' + (j+1);
			break;
		}
	}
	cout << s << endl;



	return 0;
}