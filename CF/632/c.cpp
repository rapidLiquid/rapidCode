#include <bits/stdc++.h>

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
#define sz(a) (int)((a).size())
 
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
	
	int n;
	cin >> n;
	std::vector<LL> v(n);
	map<LL,LL>m;
	// m[0]=0;
	m[0]=0;
	LL c = 0; // empty subarrays
	int li = -1;
	int pos = -2;
	fr(i,0,n) {
		cin >> v[i];
		if(!v[i])pos=i;
		if(i>0)v[i]+=v[i-1];

		int tmp=-1;
		if(m.count(v[i])) tmp=m[v[i]];
		tmp=max(tmp,pos);
		li=max(li,tmp);
		c += (i-li);

		m[v[i]]=i+1; // very imp for differences
	}
	cout << c << endl;




	return 0;
}


/*

logic is that that for any subarray 
l , r
there shouldnot be a subarray
l1,r1
s.t.
l <= l1 <= r
hence in a way we need to store the leftmost 
index of every subarray
*/

/*

learnings
think thrice, code once
think about the logic and understand the question fully
dont jumnp to conclusions without thinking
especially if u have seen the sort of question before



*/