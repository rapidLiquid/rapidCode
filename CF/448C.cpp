#include <bits/stdc++.h>
#define vi std::vector<int>
using namespace std;

//TODO IMPLEMENT WITH SPARSE TABLE

typedef long long ll;

pair<int,int> _min(vi& v, int i, int j){
	int idx = i;
	for(int k = i; k <= j; ++k) if(v[k] < v[idx]) idx = k;
	int tmp = v[idx];
	for(int k = i; k <= j; ++k) v[k] -= tmp;
	return {tmp, idx};
}

ll _go(vi& v, int i, int j) {
	if(i > j) return 0;
	ll ver = j-i+1;
	auto m = _min(v,i , j);
	ll hor = m.first;
	int idx = m.second;
	hor += _go(v, i, idx-1) + _go(v, idx+1, j);
	return min(hor, ver);
}



int main(int argc, char const *argv[])
{
	
	int n; cin >> n;

	std::vector<int> v(n);

	for(int i = 0; i < n; ++i) cin >> v[i];

	cout << _go(v, 0, n-1) << endl;

	return 0;
}