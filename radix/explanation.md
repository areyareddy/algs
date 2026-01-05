radix sort works like this:
[explanation to be added]

the best one in general is 8-bit radix sort (1 bit radix was my first implementation.)

You see a lot online that radix sort runs in O(kx) time, where k is "the number of passes of the sorting algorithm". Operations in radix sort are effectively 2*O(32/b*N) + 32/b * 2^b, with space complexity O(2^b). \
In big O this is just O(N) and space O(2^b), but in reality, the constant term very much does matter: 32-bit radix sort (which on signed ints is just bucket sort) is O(N), but has a constant term of ~4 billion, making it very slow (also takes that amount in space complexity). \
Thus, a good middle ground is b=8 radix sort, giving us 4 passes, and 256 buckets, instead of 1 pass and 4 billion buckets. An alternative is b=1, which involves 10 passes and 2 buckets. \
An O(4N) sorting algorithm is very good compared to O(N log N), especially once you get to higher values of N. 
