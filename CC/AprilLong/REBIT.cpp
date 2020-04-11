#include <bits/stdc++.h>
using namespace std;
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)

typedef pair< int, int> ii;
typedef long long LL;
unordered_map<int,int>op;
unordered_map<int,LL>dp[4];
string expr;

//TODO
const LL mod = 998244353;

LL mul(LL x, LL y) { x%=mod; y%=mod; return (x*y)%mod; }
LL add(LL x, LL y) { x%=mod; y%=mod; return (x+y)%mod; }

unordered_map<int,int>mpp;


LL Pow(LL x, LL y) {
	LL res = 1;
	while(y) {
		if(y&1) res=mul(res,x);
		y>>=1;
		x=mul(x,x);
	}
	return res;
}

LL _ways(int l,int r,char c) {

	// ways to get char c = 0,1,a,A
	// from range l,r
	if(dp[mpp[c]].count(l))return dp[mpp[c]][l];
	if(l == r) return 1;//this is #
	int m = op[l];
	LL ans = 0;
	if(expr[m]=='&') {
		if(c=='1') {
			ans = add (ans , mul(_ways(l+1,m-1,'1') , _ways(m+1,r-1,'1')));
		}
		else if(c=='0') {
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'A')));

		}
		else if(c=='a') {
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'a')));
		}
		else {
			//A
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'A')));
		}
	} else if(expr[m] == '|') {
		if(c=='1') {
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'A')));
		}
		else if(c=='0') {
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'0')));
		}
		else if(c=='a') {
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'a')));

		}
		else {
			//A
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'A')));
		}
	} else {
		// ^
		if(c=='1') {
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'0')));
		}
		else if(c=='0') {
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'a')));

		}
		else if(c=='a') {
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'A')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'a')));
		}
		else {
			//A
			ans = add(ans, mul(_ways(l+1,m-1,'1'), _ways(m+1,r-1,'a')));
			ans = add(ans, mul(_ways(l+1,m-1,'a'), _ways(m+1,r-1,'1')));
			ans = add(ans, mul(_ways(l+1,m-1,'A'), _ways(m+1,r-1,'0')));
			ans = add(ans, mul(_ways(l+1,m-1,'0'), _ways(m+1,r-1,'A')));
		}

	}
	return dp[mpp[c]][l]=ans;

}


int main(int argc, char const *argv[])
{
	mpp['0']=0;
	mpp['1']=1; mpp['a']=2; mpp['A']=3;
	int t; scanf("%d", &t);
	while(t--) {
		cin >> expr;
		int n= expr.length();
		stack <ii> stk;
		op.clear();
		dp[0].clear(); dp[1].clear();
		dp[2].clear(); dp[3].clear();
		int now;
		int hashh=0;
		fr(i,0,n){
			if(expr[i]=='#')++hashh;
			if(expr[i]=='(')stk.push({i,-1});
			else if(expr[i]=='|' ||
					expr[i]=='&' ||
					expr[i]=='^') {

				// now=i;
				int z= stk.top().first;
				stk.pop();
				stk.push({z,i});
			}
			else if(expr[i]==')') {
				op[stk.top().first]=stk.top().second;
				stk.pop();
			}
		}
		// for(auto x : op) {
		// 	cout << x.first << " op " << x.second << endl;
		// }
		LL denom = Pow(4,hashh);
		// cout << "de " << denom << endl;
		denom = Pow(denom, mod-2);
		LL z = mul(_ways(0,n-1,'0'), denom);
		LL o = mul(_ways(0,n-1,'1'), denom);
		LL a = mul(_ways(0,n-1,'a'), denom);
		LL A = mul(_ways(0,n-1,'A'), denom);
		printf("%lld %lld %lld %lld\n", z,o,a,A);
		// cout << "0 " << _ways(0,n-1,'0') << endl;;
		// cout << "1 " << _ways(0,n-1,'1') << endl;;
		// cout << "a " << _ways(0,n-1,'a') << endl;;
		// cout << "A " << _ways(0,n-1,'A') << endl;;


	}	


	return 0;
}



/*


((#&#)|((#|#)^#))

0

| -> 0,0
& -> 1,0  0,1  0,0  a,0   0,a   A,0   0,A   a,A   A,a
^ -> a,a  A,A  0,0  1,1








*/