# Cuckoo-hash-table

Cuckoo hash table stores positive integers (≥ 0) in the
bin corresponding to the hash or searches forward if that bin is filled. The load factor of a hash table may
increase array may be changed depending on the number of positive integers currently stored in the array,
according to the following two rules:

1. If a positive integer is being inserted into a hash table where the load factor after the insertion is 0.75,
the size of the array is doubled.
2. If, after removing a positive integer from a hash table where the load factor after the removal is 0.25,
then the size of the array is halved. The size of the array may not be reduced below the initially
specified size.

Create a hash table which uses linear probing where the array size may double or halve, depending on the
Hash Function.
