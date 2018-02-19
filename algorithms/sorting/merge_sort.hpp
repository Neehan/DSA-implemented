#ifndef SORTING_HPP
#define SORTING_HPP
#include <bits/stdc++.h>
namespace dsa{
    template<typename RandomAccessIterator>
    void merge_sort(RandomAccessIterator first, RandomAccessIterator last);
    /**
     * Sorts the elements in a sequence within [first, last)
     * the sorting has O(n * lg n) worst case and average case run time behavior
     * the elements are sorted in ascending order
    **/
    template<typename RandomAccessIterator, typename Compare>
    void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
        Compare comp);
    /**
     * Sorts the elements in a sequence within [first, last). The comp function is
     * used to determine order
     * the sorting has O(n * lg n) worst case and average case run time behavior
    **/

    template<typename RandomAccessIterator, typename Compare>
    void inner_merge_sort(RandomAccessIterator first, RandomAccessIterator last,
        Compare comp);




//            === I N T E R N A L  F U N C T I O N S ===


    /**
     * Used by both versions of the merge_sort(). This function defines
     * the principal merge sort algorithm as described in Introduction to
     * Algorithms.
    **/

    template<typename RandomAccessIterator, typename Compare>
    void inner_merge(RandomAccessIterator& first, RandomAccessIterator& mid,
	    RandomAccessIterator& last, Compare comp);
    /**
     * Used by inner_merge_sort to merge two sorted subsequences
    **/

}



//                  === D E F I N I T I O N ===


template<typename RandomAccessIterator>
void dsa::merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type
	ValueType;

	// concept requirements
    __glibcxx_function_requires(_MutableRandomAccessIteratorConcept<
	  RandomAccessIterator>)
    __glibcxx_function_requires(_LessThanComparableConcept<ValueType>)
    __glibcxx_requires_valid_range(first, last);

    dsa::inner_merge_sort(first, last,
        [](ValueType a, ValueType b) {return a <= b;});
}

template<typename RandomAccessIterator, typename Compare>
void dsa::merge_sort(RandomAccessIterator first, RandomAccessIterator last,
    Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type
	ValueType;

    // concept requirements
    __glibcxx_function_requires(_MutableRandomAccessIteratorConcept<
	  RandomAccessIterator>)
    __glibcxx_function_requires(_BinaryPredicateConcept<Compare, ValueType,
				ValueType>)
    __glibcxx_requires_valid_range(first, last);

    dsa::inner_merge_sort(first, last, comp);
}

template<typename RandomAccessIterator, typename Compare>
void dsa::inner_merge_sort(RandomAccessIterator first, RandomAccessIterator last,
    Compare comp)
{
    if(last - first > 1){
        RandomAccessIterator mid = first + (last - first) / 2;
        dsa::inner_merge_sort(first, mid, comp);
        dsa::inner_merge_sort(mid, last, comp);
        dsa::inner_merge(first, mid, last, comp);
    }
}

template<typename RandomAccessIterator, typename Compare>
void dsa::inner_merge(RandomAccessIterator& first, RandomAccessIterator& mid,
	RandomAccessIterator& last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type
	ValueType;

    // copying two sorted halves
    std::vector<ValueType> L(first, mid), R(mid, last);

    //merging two sorted halves
    unsigned long long i = 0, j = 0;
    RandomAccessIterator& it = first;
    while(i < L.size() and j < R.size()){
    	*it = comp(L[i], R[j]) ? L[i++] : R[j++];
    	it++;
    }

    // copying the rest of the elements of L
    for(; i < L.size(); i++, it++){
        *it = L[i];
    }

    // copying the rest of the elements of R
    for(; j < R.size(); j++, it++){
        *it = R[j];
    }
}
#endif
