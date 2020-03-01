


int getS(int mask, vector<int>& a) {
    if(!mask) return -1;
    int s= 0;
    for(int i = 0; i < 15; ++i)
        if((1<<i) & mask) s+=a[i];
    return s;
}

int Solution::solve(vector<int> &A) {

    int n = (int)A.size();
    vector<bool> dp2( (1<<n),false);
    for(int mask = 1; mask < (1<<n); ++mask) {
        int S = getS(mask, A);
        if(S&1) continue;
        for(int sb = mask; sb; sb=(sb-1)&mask) {
            // currMask is s
            int other = mask ^ sb;
            int Ss = getS(other, A);
            if(Ss*2 == S) { dp2[mask] = true; break; }
        }
    }
    
    int ans = -1;
    for(int mask = 1; mask < (1<<n); ++mask) {
        for(int sb = mask; sb; sb=(sb-1)&mask) {
            int other = mask ^ sb;
            if(  dp2[other] && dp2[sb]  ) {
                int a = getS(other,A);
                int b = getS(sb, A);
                ans = max(ans, (a/2)*(b/2));
            }
        }
    }
    return ans;
    
}

/*
 * 
 * a great problem for understanding submask enumeration
 * and dp
 *
 * */
