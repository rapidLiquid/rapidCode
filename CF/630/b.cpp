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


/*

TO be noted that the max value of number can be 1000
what does this mean
sqrt(1000) is around 31

primes till 31

2 3 5 7 11 13 17 19 23 29 31

only 11 primes are there

what does it mean , that the lowest prime divisor/divisor of the number
will be one of these primes because if the lowest is greater than these then 
the number will be > 1000
i was confused because i thought that what if 101 or some other prime is given
*/


int main(int argc, char const *argv[])
{
  
  vi pr({2, 3 ,5 ,7, 11, 13, 17, 19 ,23 ,29 ,31});
  t_times {
    int n ;
    cin >> n ;

    // vi a(n);
    vi ans(n);
    map<int,int>m; int idx=0;
    fr(i,0,n){
      int x; cin >> x;
      fr(j,0,11) if(x%pr[j]==0) ans[i]=j+1;
      if(!m.count(ans[i]))m[ans[i]]=++idx;
    }//any nmber taken, need to take the smallest number , compress the numbers
    cout << idx << endl;
    fr(i,0,n)cout << m[ans[i]] << " ";
    cout << endl;

  }

  return 0;
}