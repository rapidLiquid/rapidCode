#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n; cin >> n;
	std::vector<int> v;
	for(int i = 0; i < n; ++i) cin >> v[i];



	// construct li and ri array
	// where li is the best possible ans when we are at i (from left)
	// for any i, we find the next smaller left height
	// now the heights in between them can be shortened to fit the needs of curr
	// but the next smaller will again fit the lefts according to itself
	// so   l[i] = (j-i)*h[i]+l[j]





	return 0;
}