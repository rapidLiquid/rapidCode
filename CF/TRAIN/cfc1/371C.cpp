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
	string recipe;
	cin >> recipe;
	int ca = 0, cb = 0, cc=0;
	for(char c : recipe) {
		if(c=='B')ca++;
		if(c=='S')cb++;
		if(c=='C')cc++;
	}

	int na, nb, nc; cin >> na >> nb >> nc;
	int pa, pb, pc; cin >> pa >> pb >> pc;
	LL rubles;
	cin >> rubles;

	int c = na*pa + nb*pb + nc*pc;
	
	LL low = 0, high = 1e13;
	
	auto check = [&] (LL tot) {
		LL an = max(0ll,tot*ca - na);
		LL bn = max(0ll,tot*cb - nb);
		LL cn = max(0ll,tot*cc - nc);
		LL money = an*pa + bn*pb + cn*pc;
		return money <= rubles;
	};

	while(low <= high) {
		LL mid = (low + high) / 2;
		if(check(mid)) low= mid+1;
		else high = mid-1;
	}
	cout << high << endl;


	return 0;
}