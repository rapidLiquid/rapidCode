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
		int n,k;
		cin >> n >> k;
		std::vector<LL> v(n);
		fr(i,0,n)cin>>v[i];
		std::set<LL> p;
		LL x = 1;
		// for(LL i = 1; i < (LL)1e17; i)
		while(x<(LL)1e17) {
			p.insert(x);
			x*=k;
		}
		sort(v.rbegin(), v.rend());
		int flag=1;
		fr(i,0,n){
			LL curr=v[i];
			// cout << "--c " << curr << endl;
			while(curr>0) {
				auto z=p.lower_bound(curr);
				if(z==p.end())break;
				if((*z) > curr) {
					if(z!=p.begin())--z;
					else break;
				}
				curr-=(*z);
				// cout << "er " << (*z) << endl;
				p.erase(z);
			}
			if(curr>0)flag=0;
		}
		puts(flag?"YES":"NO");


	}
	return 0;
}