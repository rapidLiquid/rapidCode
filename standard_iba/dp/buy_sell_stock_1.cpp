int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;int mn=-1;
    for(int i : A) {
        if(mn == -1) mn = i;
        else {
            ans = max(ans, i - mn);
            mn = min (mn, i);
        }
    }
    return ans;
}
// this is not a question but a joke
