#include <bits/stdc++.h>
using namespace std;

//TODO using XOR operator  for parity
int tot = 0;
std::vector<std::vector<int> > G;
std::vector<int> deg;
std::vector<int> eve;
std::vector<int> odd;
void dfs(int u, int pr) {
	for(int v : G[u])
		if(v!=pr)dfs(v, u);
	int leaves=0;//connected to this one
	for(int v : G[u])
		if(deg[v]==1) ++leaves;
	tot-=leaves;
	if(leaves)++tot;
	for(int v : G[u]) {
		if(v==pr)continue;
		eve[u]+=odd[v];
		odd[u]+=eve[v];
	}
	if(deg[u]==1)
		eve[u]=1;

}



int main(int argc, char const *argv[])
{
	/* code */

	int n; cin >> n;
	G = std::vector<std::vector<int> > (n,std::vector<int> ());
	deg = std::vector<int> (n,0);
	eve = std::vector<int> (n,0);
	odd = std::vector<int> (n,0);
	tot = n-1;int root=-1;
	for(int i = 0; i < n-1; ++i) {
		int u, v;cin >> u >> v;
		--u;--v;
		++deg[u]; ++deg[v];
		G[u].push_back(v);
		G[v].push_back(u);
		if(deg[u]>0) root=u;
		if(deg[v]>0) root=v;
	}
	assert(root > 0);
	dfs(root,-1);
	if(odd[root] && eve[root]) cout << "3 ";
	else cout << "1 ";
	cout << tot << endl;



	return 0;
}