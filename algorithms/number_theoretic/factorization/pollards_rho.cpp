#include "pollards_rho.h"

#define MAX       2147483647
#define A         1
#define B         1

long long dsa_implemented::__pollards_rho_poly(long long x, long long N){
    if(x < MAX) 
        return (x * x + A * x + B) % N;
    long long y = x, output = (A * x + B) % N;
    while(y > 0){
        if(y % 2 == 1)
            output += x;
        x *= 2;
        y /= 2;
        output %= N;
        x %= N;
    }
    return output;
}
 
long long dsa_implemented::pollards_rho(long long N){
    if(abs(N) < 2){
        return N;
    }
    long long tortoise = __pollards_rho_poly(1, N), hare = __pollards_rho_poly(1, N), power = 1, lead = 0, d = 1;
    while(d == 1){
        if(lead == power){
            hare = tortoise;
            power *= 2;
            lead = 0;
        }
        tortoise = __pollards_rho_poly(tortoise, N);
        lead++;
        d = gcd(N, tortoise - hare);
    }
    return d;
}