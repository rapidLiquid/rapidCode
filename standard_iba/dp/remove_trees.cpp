/*
Remove trees

Given N trees in a line with ith tree having height h[i].

You have to remove all the trees except the first one and the last one.

The cost of removing ith tree is height[i - 1] * height[i] * height[i + 1].

As soon as the tree is removed it will not exist in the line anymore.

You have to remove the trees in such a way that minimizes the cost.
*/

int _fL(int sbit, int A) {
    int s = -1;
    for(int i = 0; i < sbit; ++i) if((1<<i) & A) s = i;
    return s;
}

int _fR(int sbit, int A) {
    int s =  -1;
    for(int i = sbit+1; (1<<i) < A+1; ++i) if((1<<i) & A) return i;

}
int cnt_bit(int A) {
    int c=0;
    while(A){if(A&1)c++;A>>=1;}
    return c;
}

long long  _go(int bit, vector<int>& h,vector<long long>& dp) {
    if(cnt_bit(bit)==2){return 0;}
    long long ans  = LLONG_MAX;
    int n = (int)h.size();
    if(dp[bit]!=-1)return dp[bit];
    for(int i = 1; i < n-1; ++i){
        if((1<<i) & bit) {
            long long cost = h[_fL(i,bit)] * h[_fR(i,bit)] * h[i];
            ans = min(ans,cost + _go(bit^(1<<i),h,dp) );
        }
    }
    return dp[bit] = ans;
}


int Solution::solve(vector<int> &A) {
    int n = (int)A.size();
    vector<long long> dp((1<<n),-1);
    int bit = (1<<n)-1;
    return _go(bit, A,dp);
}

