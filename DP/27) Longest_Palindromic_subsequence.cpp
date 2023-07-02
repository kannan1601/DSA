what are we doing LCS? Finding the longest common subsequence right.

what does palindrome mean? if we reverse them, they stay as it is.

so if we find lcs between original string and reversed string 
that will be the longest palindromic subsequence.

This works because we are finding the LCS between original string and
reversed version of it. They still same even though we reversed it.

same code like lcs with the function call return f(N, N, S, T)
where N is length of the string and T is the reversed version of it.