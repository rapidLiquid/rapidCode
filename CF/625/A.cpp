#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	

	int n;cin >> n;
	std::vector<int> r(n);
	std::vector<int> b(n);
	for(int i = 0; i < n; ++i) cin >> r[i];
	for(int i = 0; i < n; ++i) cin >> b[i];

	int c1 = 0, c2 = 0;
	for(int i = 0; i < n; ++i) {
		if(r[i] == b[i]) continue;
		else if(r[i] > b[i])c1++;
		else if(b[i] > r[i])c2++;
	}


	if(c1 == 0) puts("-1");
	else {
		if(c1 == c2) puts("2");
		else if(c1 > c2) puts("1");
		else {
			// c2 -= c1;
			cout << (c2/c1+1) << endl;
		}
	}




	return 0;
}