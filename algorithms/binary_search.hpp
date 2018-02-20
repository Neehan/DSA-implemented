#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#include<bits/stdc++.h>

namespace dsa{
    template<typename ForwardIterator, typename T>
    ForwardIterator binary_search(ForwardIterator first, ForwardIterator last, const T &val);
    template<typename ForwardIterator, typename T, typename Compare>
    ForwardIterator binary_search(ForwardIterator first, ForwardIterator last, const T &val,
                                       Compare comp);


//           === I N T E R N A L  F U N C T I O N S ===
    template<typename ForwardIterator, typename T, typename Compare>
    ForwardIterator inner_binary_search(ForwardIterator first, ForwardIterator last,
                                        const T &val, Compare comp);

//                  === D E F I N I T I O N ===
    template<typename ForwardIterator, typename T>
    ForwardIterator binary_search(ForwardIterator first, ForwardIterator last, const T& val){
        typedef typename std::iterator_traits<ForwardIterator>::value_type
        ValueType;

        // concept requirements
        __glibcxx_function_requires(ForwardIteratorConcept<ForwardIterator>)
        __glibcxx_function_requires(LessThanOpConcept<T, ValueType>)
        __glibcxx_requires_partitioned_lower(first, last, val);
        __glibcxx_requires_partitioned_upper(first, last, val);

        return dsa::inner_binary_search(first, last, val,
                               [](ValueType a, ValueType b) {return a <= b;});
    }


    template<typename ForwardIterator, typename T, typename Compare>
    ForwardIterator binary_search(ForwardIterator first, ForwardIterator last, const T &val,
                                       Compare comp){
        typedef typename std::iterator_traits<ForwardIterator>::value_type
        ValueType;

        // concept requirements
        __glibcxx_function_requires(ForwardIteratorConcept<ForwardIterator>)
        __glibcxx_function_requires(_BinaryPredicateConcept<Compare, T, ValueType>)
        __glibcxx_requires_partitioned_lower(first, last, val);
        __glibcxx_requires_partitioned_upper(first, last, val);

        return dsa::inner_binary_search(first, last, val, comp);
    }

    template<typename ForwardIterator, typename T, typename Compare>
    ForwardIterator inner_binary_search(ForwardIterator first, ForwardIterator last,
                                        const T &val, Compare comp){
        auto len = std::distance(first, last);
        while(len > 0){
            auto half = len >> 1;
            ForwardIterator mid = first;
            std::advance(mid, half);
            if(comp(*mid, val)){
                first = mid;
                first++;
                len = std::distance(first, last);//len - half - 1;
            }
            else{
                len = half;
            }
        }
        //if(first != last and comp(*first, val) == comp(val, *first)){
            return first;
        //}
        //else{
        //    return last;
        //}
    }
}

#endif // BINARY_SEARCH_HPP
