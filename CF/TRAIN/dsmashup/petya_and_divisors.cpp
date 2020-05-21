#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;

vector<vector<int> > divisors(N);
vector<int> last_div(N,-1);

void precompute() {
	// precompute all divisors
	for(int i = 1; i < N; ++i)
		for(int j = i; j < N; j += i)
			divisors[j].push_back(i);
}

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(int argc, char const *argv[])
{
	fastio;
	precompute();
	auto get_divs = [] (int x) {
		vector<int> d;
		for(int i : divisors[x])
			d.push_back(i);
		return d;
	};
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		vector<int> ds = get_divs(x);
		int cnt = 0;
		for(int d : ds) {
			if(last_div[d] < i-y) ++cnt;
			last_div[d] = i;
		}
		cout << cnt << endl;
	}


	return 0;
}

/*
the idea is that the number of divisors are limited avg 30
now for each divisor of a number we need to find the number of
divisors that that do not divide the number till a given range,
clearly there are only 30 divisors and we know the occurence of the
last divisor of the number, when did it divide last
we simply check for each divisor, when did it divide last ...



*/