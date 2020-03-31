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
		int a, b, c, d;//l r d u
		cin >> a >> b >> c >>d;
		int x,y,x1,y1,x2,y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if((x2-x1==0&&(a>0||b>0)) || (y2-y1==0&&(c>0||d>0))) {
			cout << "No\n";
			continue;
		}
		int l = x-x1;
		int r = x2-x;
		int up = y2-y;
		int down = y-y1;
		int z= min(a,b);
		a-=z;b-=z;
		int poss1=0;
		poss1 = l>=a;
		poss1 &= r>=b;
		z = min(c,d);
		c-=z; d-=z;
		poss1 &= down>=c;
		poss1 &= up>=d;
		cout << (poss1 ? "Yes" :"No")<<endl;


	}
	return 0;
}