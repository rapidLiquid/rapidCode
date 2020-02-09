## LCS

LCS can be computed with a dp approach, DP(i,j) = longest subsequence we can form till position i in string A and j in string B
<pre><code>
if(A[i] == B[j] )	DP(i,j) = 1 + DP(i-1,j-1)
else 			DP(i,j) = max ( DP(i-1,j) , DP(i,j-1) )
</code></pre>
## EDIT DISTANCE

todo
