int Solution::solve(vector<int> &A) {
    // stack<int> stk; 
    int n= (int)A.size();
    //TODO solve using stack
    // vector<int> nex(n);
    // for(int i = 0; i < n; ++i){
    //     if(stk.empty()) stk.push(i);
    //     else {
    //         while( !stk.empty() && A[stk.top()] < A[i]){
    //             nex[stk.top()] = i;
    //             stk.pop();
    //         }
    //         stk.push(i);
    //     }
    // }
    // while(!stk.empty()){
    //     nex[stk.top()] = n-1;
    //     stk.pop();
    // }
    // int ans = 0;
    // for(int i = 0; i < n; ++i) {
    //     // cout << i << " n " << nex[i] << endl;
    //     ans += nex[i] - i;
    // }
    // return ans;
    
    vector<pair<int,int>> p;
    for(int i = 0; i < n; ++i) {
        p.push_back({A[i],i});
    }
    sort(p.rbegin(), p.rend());
    set<int> s;
    s.insert(p[0].second);
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        int idd= p[i].second;
        auto x = s.lower_bound(idd);
        if(x!=s.begin()) ans ++;
        auto y = s.upper_bound(idd);
        if(y!=s.end()) ans ++;
        s.insert(idd);
    }
    return ans;
    
}

