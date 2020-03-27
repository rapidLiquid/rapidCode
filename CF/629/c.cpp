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
	
	t_times {
		int n;cin >> n;
		string s; cin >> s;
		int flag =0;
		string ans1="", ans2="";
		fr(i,0,n) {
			if(s[i] == '2')
				if(!flag) ans1 += '1', ans2 += '1';
				else ans1 += '2', ans2 += '0';
			else if(s[i] == '0') ans1 += '0', ans2 += '0';
			else {
				if(flag) {
					ans1 += '1';
					ans2 += '0';
				} else {
					flag = 1;
					ans2 += '1';
					ans1 += '0';
				}
			}
		}
		cout << ans2 << endl << ans1 << endl;
	}
	return 0;
}