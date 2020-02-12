// is there subsequence that repeats itself
// aabb -> 1
// abba -> 0
// simple brute force for constraint 100
// waht is the definition of subsequence , simply the start and end shouldnt be equal for both
// if subsequence of x length is there ,x > 1 then subsequence of 2 is always there, simple
int Solution::anytwo(string A) {
    int n = A.length();
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            for(int k = i+1; k < n; ++k) {
                for(int l = k+1; l < n; ++l) {
                    if(k!=i && l!=j) {
                        if(A[i]==A[k]&&A[j]==A[l])return 1;
                    }
                }
            }
        }
    }
    return 0;
}

