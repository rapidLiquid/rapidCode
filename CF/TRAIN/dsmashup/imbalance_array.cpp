


/*



imbalacne of the array is the sum of the


SUMOF (mx-mn) over all the subsegments ....


can we consider a subsegment ending at some point

how many segments is the element part of

find next , find prev and then 





*/

#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define vi vector<int>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

vi prev_m(vi& arr, function<bool(int,int)> pred) {
	stack<int> stk;
	int n = sz(arr);
	vi prev(n);
	for(int i = n-1; i>=0; --i) {
		while(!stk.empty() && pred(arr[stk.top()], arr[i])) {
			prev[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()) {
		prev[stk.top()] = -1;
		stk.pop();
	}
	return prev;
}

vi nxt_m(vi& arr, function<bool(int,int)> pred) {

	stack<int> stk;
	int n = sz(arr);
	vi nxt(n);
	fr(i,0,n) {
		while(!stk.empty() && pred(arr[stk.top()], arr[i]) ) {
			nxt[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		nxt[stk.top()] = n;
		stk.pop();
	}
	return nxt;
	//  -1 1 2

}


int _test(vi& arr) {

	// bf testing
	int ans  = 0; 
	return ans;
}




int main(int argc, char const *argv[])
{
	

	int n; cin >> n;
	vi a(n);
	fr(i,0,n) cin >> a[i];

	auto greater = [] (int a, int b) { return a <= b; };
	auto smaller = [] (int a, int b) { return a >= b; };
	vi nxt_mx = nxt_m(a, greater);
	vi nxt_mn = nxt_m(a, smaller);
	vi prev_mx = prev_m(a, greater);
	vi prev_mn = prev_m(a, smaller);

	long long  ans = 0;
	fr(i,0,n) {
		cout << i << " mx " << (nxt_mx[i]-i)*(i-prev_mx[i]) << endl;;
		cout << i << " mn " << (nxt_mn[i]-i)*(i-prev_mn[i]) << endl;;
		ans += (nxt_mx[i]-i)*1ll*(i-prev_mx[i])*a[i];
		ans -= (nxt_mn[i]-i)*1ll*(i-prev_mn[i])*a[i];
	}
	cout << "ans " << ans << endl;

	fr(i,0,n) cout << (nxt_mx[i] == n ? -1 : a[nxt_mx[i]]) << " ";
	cout << endl;
	fr(i,0,n) cout << (nxt_mn[i] == n ? -1 : a[nxt_mn[i]]) << " ";
	cout << endl;

	cout << "pre\n";
	fr(i,0,n) cout << (prev_mx[i] == -1 ? -1 : a[prev_mx[i]]) << " ";
	cout << endl;
	fr(i,0,n) cout << (prev_mn[i] == -1 ? -1 : a[prev_mn[i]]) << " ";
	cout << endl;




	return 0;
}