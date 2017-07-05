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

long long dsa_implemented::bgcd(long long a, long long b){
    if( a * b == 0){
    	return (a - b > 0) ? a - b : b - a;
    }
    if(a == b){
    	return a;
    }
    if(a % 2 == 0){
    	return (b % 2 == 1) ? gcd(a / 2, b) : 2 * gcd(a / 2, b / 2);
    }
    else if(b % 2 == 0){
    	return gcd(a, b / 2);
    }
    return (a > b) ? gcd((a - b) / 2, b) : gcd((b - a) / 2, a);
}