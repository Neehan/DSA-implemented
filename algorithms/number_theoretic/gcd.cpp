#include "gcd.h"

long long dsa_implemented::gcd(long long a, long long b){
    long long r;
    while(b != 0){
        r =  a % b;
        a = b;
        b = r;
    }
    return (a > 0) ? a : -a;
}