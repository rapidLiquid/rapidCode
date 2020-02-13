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

int _fL(int mask, int sb) {
	rev(i,sb-1,0) if((1<<i)&mask) return i;
	return -1;
}
int _fR(int mask, int sb) {
	int n = 0; while(mask > (1<<n))++n;
	fr(i,sb+1,n) if((1<<i)&mask) return i;
	return -1;
}

string _mask2str(int mask) {
	string s="";
	while(mask) {s+=(mask&1)?'1':'0'; mask>>=1;}
	reverse(all(s));
	return s==""?"0":s;
}

void _debug(vi& dp){
	int n = (int)dp.size();
	fr(i,0,n)cout<<_mask2str(i) << " " << dp[i] << endl;
}
/*

To be noted

fr(i,1,n-1) {
	fr(mask,0,(1<<n)){
		this wont work
		because we are doing for the first bit all the mask
		then for second bit all the mask
		the info second bit needs regarding the first bit is unavailable
	}
}

fr(mask,0,(1<<n)) {
	fr(i,1,n-1){
		this will work since we are calculating for each mask the best possibility
			when removing a bit
		now the info second bit needs wrt to first bit is available

	}
}
hece istead of bit -> mask   think   mask -> bit
given a mask , remove a bit and obviously we will get a mask with lower value 
i.e lets say we are at mask -> mask and removed the bit 
we get mask' -> mask ^ (1<<i)
clearly   mask' < mask
and we already calculated the best possibility for mask'
hence this works perfectly, building up step by step
from lower mask value to higher
*/
int _f(vi& h) {
	int n = (int)h.size();
	vi dp( (1<<n), inf );
	dp[ (1<<(n-1)) | 1 ]=0;
	fr(mask,0,(1<<n)){
		 fr(i,1,n-1){
			mask |= (1); mask |= (1<<(n-1));
			if( (1<<i) & mask ) {
				int l = _fL(mask,i), r = _fR(mask,i);
				int c = h[i] * h[l] * h[r] + dp[ mask^(1<<i) ];
				dp[mask] = min(dp[mask],c);
			}
		}
	}
	return dp[(1<<n)-1];
}



int main(int argc, char const *argv[])
{
	fastio;
	
	vi h({1,1,2,3,1});
	cout << _f(h) << endl;
	return 0;
}
