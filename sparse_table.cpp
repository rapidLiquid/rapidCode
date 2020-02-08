#include <bits/stdc++.h>
using namespace std;



#define vi vector<int>
#define vvi std::vector<vi>



/*
use -> log N  query and no updates
query only DS

table[N][20]
table[i][0] = arr[i]
-> table[i][j] -> f ( arr[i] ... arr[i][i + (1 << j) - 1] )

*/

int func(int x, int y) {
	// return max(x, y);
	// return __gcd(x, y);
	return x + y;
}

vvi _build(vi arr) {
	int n = (int)arr.size();
	const int N = 20;
	vvi table(n, vi (N,0));

	for(int i = 0; i < n; ++i)
		table[i][0] = arr[i];
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j < N && i + (1 << (j-1)) < n; ++j) {
			table[i][j] = func( table[i][j-1] , table[i + (1 << (j-1))][j-1] );
		}
	}



	return table;
}


int _query(vvi& table, int l, int r) {
	int res = 0 ;

	// given a width and a start point , 
	// try to pick the max width and then continue
	// width decreases and the start point changes
	const int N = (int)table[0].size();
	while(l <= r) {
		// int width = r - l + 1;
		for(int i = N; i >= 0; --i) {
			if(l + (1 << i) - 1 <= r) {
				res = func(res, table[l][i]);
				l += (1 << i);
				break;
			}
		}
	}

	return res;
}


void view(vvi table) {
	int n = (int)table.size();
	const int N  = (int)table[0].size();

	for(int i = 0; i < n; ++i) {
		cout << " i " << i << " ->> ";
		for(int j = 0; j < N; ++j) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	vi arr({1,2,3,4,5});
	vvi table = _build(arr);
	view(table);
	cout << _query(table, 0, 1) << endl;;
	cout << _query(table, 0, 2) << endl;;
	cout << _query(table, 3, 4) << endl;;

	return 0;
}