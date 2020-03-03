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
	
	string s; cin >> s;
	int n = s.length();
	int f=0, e=n-1;
	vi r;
	while(f < e) {
		if(s[f] == '(' && s[e] == ')') {
			r.push_back(f);
			r.push_back(e);
			++f;
			--e;
		} else if(s[f] == '(' && s[e] == '(') {
			--e;
		} else if(s[f] == ')' && s[e] == '(') {
			++f; --e;
		} else if(s[f] == ')' && s[e] == ')') {
			++f;
		}
		// cout << f << " " << e << endl;
	}
	if((int)r.size()) {
		cout << 1 << endl;
		cout << (int)r.size() << endl;
		sort(all(r));
		fr(i,0,(int)r.size()) cout << r[i]+1 << " ";
		cout << endl;
	} else {
		cout << "0\n";
	}

	return 0;
}