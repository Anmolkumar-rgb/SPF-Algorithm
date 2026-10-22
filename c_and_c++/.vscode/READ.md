
# Smallest Prime Factor (SPF)

## What is SPF?
SPF stands for Smallest Prime Factor. It stores the smallest prime factor of every number in an array.

Example:
- SPF[12] = 2
- SPF[15] = 3
- SPF[35] = 5
- SPF[49] = 7

## Why Do We Use SPF?
- Normal Sieve identifies prime numbers.
- SPF stores the smallest prime factor of every number.
- It helps us find prime factorization efficiently for multiple queries.
- We can access the smallest prime factor directly using `spf[n]`.

## How Does SPF Work?
1. Initially, set `spf[i] = i` for every number.
2. Iterate through numbers from 2 to sqrt(N).
3. If `spf[i] == i`, then `i` is prime.
4. Visit multiples of `i`, starting from `i * i`.
5. If a multiple has not been marked yet, store `i` as its SPF.

## Example: Prime Factorization of 12

- `spf[12] = 2` → divide 12 by 2 → 6
- `spf[6] = 2` → divide 6 by 2 → 3
- `spf[3] = 3` → divide 3 by 3 → 1

Therefore:

`12 = 2 × 2 × 3`

## Time Complexity
- Preprocessing: `O(N log log N)`
- Each query: `O(log N)` worst case
- Q queries: `O(Q log N)` worst case
- Space complexity: `O(N)`

## Why Is Each Query O(log N)?
In each iteration, we divide `n` by its smallest prime factor, which is at least 2.

Therefore, `n` becomes at most half its previous value in every iteration.

The maximum number of iterations is `O(log N)`.

Note: Accessing `spf[n]` takes `O(1)` time, but the complete factorization loop takes `O(log N)` time.

## Conclusion
SPF is useful when we need prime factorization for many numbers. It avoids repeatedly searching for prime divisors by storing the smallest prime factor of each number in advance.
