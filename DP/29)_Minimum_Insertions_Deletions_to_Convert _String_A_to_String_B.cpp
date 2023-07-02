

This is always possible in N + M operations where N is 
length of first string and M is length of second string
by deleting all N characters of string 1 and inserting  
all M characters of string 2

How to minimize this?

KEY IDEA : Do not touch the characters that
           are already present in both the 
           strings

This gives a hint about finding LCS of 2 strings

for eg : S1 = abcd    S2 = anc

we have a c in common in both the strings right
unwanted characters are b d, remove it and insert
the remaining characters of S2 to make strings equal

Deletions = N - length of LCS
Insertions = M - length of LCS

Total = N + M - 2 * length of LCS