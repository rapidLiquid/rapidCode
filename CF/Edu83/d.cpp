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

const LL P = 998244353;

LL mul(LL x, LL y) {
	x%=P; y%=P;
	return (x*y)%P;
}

LL Po(LL x, LL y) {
	LL res = 1;
	while(y) {
		if(y&1) res = mul(res, x);
		y>>=1;
		x =mul(x,x);
	}
	return res;
}

LL f(LL n) {
	LL res=1;
	fr(i,1,n+1)res=mul(res,i);
	return res;
}

LL nCr(LL n, LL r) {

	LL nu = f(n);
	LL d = mul(f(r),f(n-r));

	LL res = mul( nu , Po(d,P-2) );
	return res;

}

int main(int argc, char const *argv[])
{
	fastio;
	
	// (n-2) * (pow(2,n-3)) * mC(n-1)


	int n, m; cin >> n >> m;
	if(n == 2) {
		puts("0");
		return 0;
	}

	LL res = (n-2);
	res = mul(res, Po(2,n-3));
	res = mul(res, nCr(m,n-1));
	cout << res << endl;




	return 0;
}