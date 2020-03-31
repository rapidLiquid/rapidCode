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
		vi v(n);
		vi c(n);
		fr(i,0,n)cin>>v[i];
		c[0]=0;int last=n,first=1;
		fr(i,1,n)
			if(v[i]==v[i-1]) c[i]=c[i-1];
			else {
				first = i;
				break;
			}
		if(v[n-1] == v[0]) {
			c[n-1]=0;
			rev(i,n-2,0)
				if(v[i]==v[i+1]) c[i]=c[i+1];
				else {
					last = i+1;
					break;
				}
		}
		//[first,last)
		int grps=1;
		fr(i,first,last)if(v[i]!=v[i-1])grps++;

		if(grps==1) {
			cout << 1 << endl;
			fr(i,0,n)cout<< c[i]+1 << " ";
			cout <<endl;
		} else if(grps&1) {
			if(grps == n) {
				cout << 3 << endl;
				fr(i,1,n){
					if(v[i]==v[i-1])c[i]=c[i-1];
					else c[i]=(c[i-1]+1)%2;
				}
				c[n-1] = 2;
				fr(i,0,n)cout<<c[i]+1 <<" ";
				cout << endl;
			}
			else {
				//handle this
				cout << 2 << endl;
				if(first + n-last > 1) {
					c[first-1]=1;
					fr(i,first,last){
						if(v[i]==v[i-1])c[i]=c[i-1];
						else c[i]=(c[i-1]+1)%2;
					}
					fr(i,0,n)cout<<c[i]+1 <<" ";
					cout << endl;
				} else {
					int len=1;int flag = 1;
					fr(i,first,last) {
						if(v[i] ==v[i-1]) {
							c[i]=c[i-1];
							++len;
						} else {
							if(len>1&&flag) {
								c[i]=(c[i-1]+1)%2;
								c[i-1]=(c[i]+1)%2;
								swap(c[i-1],c[i]);
								flag=0;
							}
							c[i]=(c[i-1]+1)%2;
							len = 1;
						}
					}
					fr(i,0,n)cout<<c[i]+1 <<" ";
					cout << endl;
				}
				// cout << 2 << endl;
			}
		} else {
			// int mx=0;
			cout << 2 << endl;
			fr(i,1,n){
				if(v[i]==v[i-1])c[i]=c[i-1];
				else c[i]=(c[i-1]+1)%2;
			}
			fr(i,0,n)cout<<c[i]+1 <<" ";
			cout << endl;
		}



		// int mx=0;
		// fr(i,1,n){
		// 	if(v[i]==v[i-1])c[i]=c[i-1];
		// 	else c[i]=(c[i-1]+1)%2;
		// 	mx=max(mx,c[i]);
		// }
		// if(v[n-1] != v[0]) {
		// 	if(c[n-1]==c[0]) {
		// 		c[n-1]=mx+1;
		// 		mx=max(mx,c[n-1]);
		// 	}
		// }
		// cout << mx+1 << endl;
		// fr(i,0,n)cout<<c[i]+1 <<" ";
		// cout << endl;

	}
	return 0;
}