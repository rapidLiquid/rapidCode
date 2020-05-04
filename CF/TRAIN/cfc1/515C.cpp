
/*


4 -> 4 3 2
3 -> 3 2
2 -> 2


555
5-> 5 4 3 2
5-> 5 4 3 2
5-> 5 4 3 2

some numbers will be prime and some will be non prime

9 -> 7! 3! 3! 2!
8 -> 7! 2! 2! 2!
7 -> 7!
6 -> 5! 3!
5 -> 5!
4 -> 3! 2! 2!
3 -> 3!
2 -> 2!

*/

#include <bits/stdc++.h>
using namespace std;

std::vector<string> v({"0", "1", "2", "3", "322", "5", "53", "7", "7222", "7332"});

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	string s;cin >> s;
	string ans = "";
	for(char c : s) if(c > '1') ans += v[c-'0'];
	sort(ans.rbegin(), ans.rend());
	cout << ans << endl;


	return 0;
}