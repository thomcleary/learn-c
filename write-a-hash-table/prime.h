#ifndef PRIME_H
#define PRIME_H

/**
 * @returns whether x is prime or not
 * @retval
 * - 1 = prime
 *
 * - 0 = not prime
 *
 * - 1 = undefined (i.e. x < 2)
 */
int is_prime(const int x);

/**
 * @returns the next prime after x, or x if x is prime
 */
int next_prime(int x);

#endif