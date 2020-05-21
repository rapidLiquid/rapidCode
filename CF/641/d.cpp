#include <bits/stdc++.h>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rev(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define pb push_back
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;

typedef pair< LL, LL> ll;
typedef vector< LL> vl;
typedef vector< ll> vll;
typedef vector< vl> vvl;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;
	

	t_times{
		int n,k;cin >> n >> k;
		vi v(n+1);
		fr(i,1,n+1){
			cin>>v[i];
			if(v[i]==k)v[i]=0;
			else if(v[i]<k)v[i]=-1;
			else v[i]=1;
		}
		// find any subsegemt st 1s is half of that
		int c = 0;
		// map<int,int>m;
		int flag = 0;
		int mn = INT_MAX;
		fr(i,1,n+1){
			// if(v[i])++c;
			c += v[i];
			// m[2*c-i]=1;
			int curr = 2*c-i;
			cout << "cutr " << curr << endl;
			if(curr - mn >= 0)flag = 1;
			mn = min(curr,mn);
		}
		if(flag)cout <<"yes";
		else cout << "no";
		cout << endl;

	}

	return 0;
}