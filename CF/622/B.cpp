#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	

	int t;
	cin >> t;
	while(t--) {
		long long n, x, y;
		cin >> n >> x >> y;
		cout << min(x+y-1,n-1)+1<< " " << min(x+y,n+1)-1 <<endl;
	}

	return 0;
}