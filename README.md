# `CSC 121 - C Programs`

Code and algorithms I implement while going through Paul & Harvey Dietel's C: How to Program book.

## Interesting bits

Knowing about algorithms and complexity is cool, for instance I was able to reduce the number of recursions required to generate 20 fibonacci numbers from 57291 to only 53! By using a technique in Dynamic Programming called "memoization", which really just means to cache previously generated results to we don't waste compute doing it again.

```c
// Cached version of the Fibonacci algorithm
unsigned long fibCached(unsigned int n, unsigned long cache[CACHE_SIZE], unsigned int *iters)
{
    *iters += 1;
    if (n == 0 || n == 1)
        return 1;

    if (cache[n] == 0)
    {
        cache[n] = fibCached((n - 1), cache, iters) + fibCached((n - 2), cache, iters);
        return cache[n];
    }
    else
        return cache[n];
}
```

### Output:

```sh
> Generate fibonacci numbers up to: 20
Cached: 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 
Uncached: 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 
Took: 53 recursions (cached)
Took: 57291 recursions (uncached)
```

## Compilation

I've streamlined the compilation process, to get started install the `make` build tool for your OS. Then run:

```sh
make
```

All the source code should be compiled into a `build` folder if everything is setup correctly.
