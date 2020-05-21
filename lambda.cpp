#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	auto f = [] (int x) {
		auto f = [x] (int y) {
			return x+y;
		};
		return f;
	};

	cout << f(2)(3) << endl;	
	return 0;
}