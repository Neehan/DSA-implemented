# DSA-implemented
This is my implementation of various data structures and algorithms. 

## Index
- `algorithms`
  - `sorting`
    - `merge_sort`
  - `number_theoretic`
    - `gcd`
    - `factorization`
      - `pollards_rho`

## How to Use
All the functions are in `dsa` namespace. Call them like `dsa:merge_sort(parameters)`. Functions starting with `inner` are for internal use only. If you are reading this project, remember that `.h' `, `.cpp`, and `hpp` files represent header files, implementations, and template implementatins, respectively. Header files contain specifications and you only need to include a header file in your program to use its functions/classes. `hpp` files contain both documentation and implementation, and they need to be included in your program to be used.

## Notes 
I wish there were a better way to seperate the internal library functions in C++. The only two ways I know of are--

1. Start all internal function names with a special character like underscore. The problem is STL itself follows this approach, and consequently, any identifier name staring with an underscore is reserved. ( There are some specifications though. For instance, I could have gotten away by using one underscore followed by a lowercase letter, as everything is in my private namespace. However, if I did that, all the internal classnames would have to start with lowercase letters.)

2. Put everything in a giant class and define private static methods. That could seriously work. I once thought about it, but writing a class that spans multiple pages is plainly ugly and a bad programming practice.

I am still looking for any alternative that would require me minimal ammount of work to restructure the project. Any suggestion would be appreciated.

## License
GPL 3.0 or any later version in your opinion.