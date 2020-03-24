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
		int n; cin >> n;
		set<int>avail;
		fr(i,0,n)avail.insert(i+1);
		std::vector<int> v[n];
		std::vector<int> vis(n,0);
		fr(i,0,n) {
			int k;cin>>k;
			fr(j,0,k) {
				int x;cin>>x;
				v[i].pb(x);
				if(!vis[i]) {
					if(avail.find(x)!=avail.end()) {
						vis[i]=1;
						avail.erase(x);
					}
				}
			}
			
		}
		if(!avail.size()) {
			cout << "OPTIMAL\n";
			continue;
		}
		int idx=-1;int king;
		fr(i,0,n) {
			if(!vis[i] && idx==-1) {
				//if el not in list but in set
				if(!v[i].size()) {
					idx=i;
					auto z=avail.begin();
					king=(*z);
					break;
				}
				int prev = 0;
				for(int kk : v[i]) {
					auto z = avail.lower_bound(prev);
					if(z!=avail.end()&&(*z)!=kk) {
						idx=i;
						king=(*z);
						break;
					}
				}

				// int mx = v[i].size()?v[i].back():0;
				// auto z= avail.lower_bound(mx);
				// if(z!=avail.end()) {
				// 	king = (*z);
				// 	idx = i;
				// 	break;
				// }
			}
		}
		if(idx==-1) {
			cout << "OPTIMAL\n";
		} else {
			cout << "IMPROVE\n";
			cout << idx+1 << " " << king << endl;
		}



	}
	return 0;
}