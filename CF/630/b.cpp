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


vi _si(int n) {
 vi pr(n+1,1);
 pr[0] = pr[1] = 0;
 fr(i,2,n+1) {
  if (!pr[i]) continue;
  for(int j = 2*i; j < n+1; j+=i)
   pr[j] = 0;
 }
 vi res;
 fr(i,0,n+1) if(pr[i]) res.pb(i);
 return res;
}


int main(int argc, char const *argv[])
{
 fastio;
 
 t_times {
  int n;cin >> n;
  vi a(n);
  fr(i,0,n)cin>>a[i];

  vi ans(n,0);
  
  int color=0;
  vi till[13];
  sort(all(a));
  till[color].pb(0);


  fr(i,1,n) {
  	int flag2=0;
  	fr(j,0,color+1) {
  		int flag = 1;
  		fr(k,0,(int)till[j].size()) {
  			if(__gcd(a[till[j][k]],a[i])==1){
  				flag=0;break;
  			}
  		}
  		if(flag){till[j].pb(i);flag2=1;break;}
  	}
  	if(!flag2){
  		++color;
  		till[color].pb(i);
  	}


  }
  fr(c,0,color+1){
  	for(int i : till[c]) ans[i]=c+1;
  }
  cout << color+1 << endl;
  for(int i : ans)cout << i << " ";
  	cout << endl;

 }
 return 0;
}