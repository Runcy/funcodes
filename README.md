# funcodes
Algorithm for finding sum of very large Integers
1. Read input as objects of type String
2. Convert String Objects in to character arrays
3. Convert the character array to integer array. (i.e)character ’1’ is converted as numeric digit ‘1’ by subtracting ascii values
4. Strat the process of addition from the right end of both the arrays. If the result is greater than 9, use modulo arithmetic to retrieve Least signiﬁcant digit.
5. Carry over the addition to next cells; towards the left end of both the arrays recursively.
6. The size of result array is equal to or one more than the size of the largest input string.
