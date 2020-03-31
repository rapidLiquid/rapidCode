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


string f(string s) {
    int len = s.size();
    int mod = (int)(1e9+7);
    long long h = 0,hrev = 0;
    int mx = 0;long long base = 1;
    for(int i = 0;i<len;i++){
        h = (h + (s[i]*base)%mod)%mod;
        base = base * 3919;
        base %= mod;
        
        hrev = ((hrev * 3919) + s[i])%mod;
        
        if(h==hrev)
            mx = i + 1;
    }
    string ss="";
    fr(i,0,mx)ss+=s[i];
    return ss;
 }


int main(int argc, char const *argv[])
{
	int t;cin >>t;
	while(t--) {
		string s; cin >> s;
		string tmp = s;

		string ans1=f(s);
		// cout << ans1<<endl;
		reverse(tmp.begin(), tmp.end());
		string ans2=f(tmp);

		int l=0,r=s.length()-1;
		while(l<=r) {
			if(s[l]==s[r]){++l;--r;}
			else break;
		}
		if(l>r) {
			if(ans1.length()>ans2.length()){
				cout << ans1 << endl;
			} else {
				cout << ans2 << endl;
			}
		}
		else {
			string pal="";
			fr(i,0,l)pal+=s[i];
			string pal2=pal;
			reverse(pal2.begin(), pal2.end());
			string tmp2="";
			fr(i,l,r+1)tmp2+=s[i];
			string tmp3=tmp2;
			reverse(tmp3.begin(), tmp3.end());
			tmp3=f(tmp3);
			tmp2=f(tmp2);
			string ans="";
			if(tmp3.length()>tmp2.length()) ans = pal+tmp3+pal2;
			else ans = pal+tmp2+pal2;
			cout << ans << endl;

		}



	}
	

	return 0;
}