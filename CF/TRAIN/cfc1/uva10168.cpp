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



// can we express a number as sum of 4 primes


/*

we can divide the numbers into two even anumbers and express
them individually


*/

unordered_map<int,ii>goldbach;
void si() {
	const int N = 1e7+8;
	vi s(N,1);
	s[0] = s[1] = 0;
	int cnt = 0;
	fr(i,2,N){
		if(s[i]==0)continue;
		++cnt;
		for(int j = 2*i; j < N; j += i){
			s[j]=0;
		}
		// if(i<100)cout << i << endl;
	}
	
	fr(i,4,N){
		if(i&1)continue;
		int flag = 0;
		fr(j,2,800){
			if(s[j]&&s[i-j]){
				flag=1;
				goldbach[i] = {j,i-j};
				break;
			}
		}
		// if(!flag)cout<<"NOPE"<<endl;
	}
	// cout << cnt << endl;
	//cehck whether each is greater than 0

}



int main(int argc, char const *argv[])
{
	fastio;
	int n;
	si();
	const string impos = "Impossible";
	while(cin >> n) {
		// cout << n << endl;;
		if(n&1 || n < 8)
			cout<< impos << endl;
		else {
			cout << "2 2 ";
			cout << goldbach[n-4].F << " " << goldbach[n-4].S << endl;
		}
		// FOR odd NUMBERs ???? 
	}


	return 0;
}