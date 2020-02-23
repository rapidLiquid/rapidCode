#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int t; cin >> t;
	while(t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int up = (x)*b;
		int down = (a-x-1)*b;
		int lef = (y)*a;
		int right = (b-y-1)*a;
		cout << max(max(up,down),max(lef,right))<<endl;
	}
	return 0;
}