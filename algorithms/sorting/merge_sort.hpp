#ifndef SORTING_HPP
#define SORTING_HPP
#include <bits/stdc++.h>
namespace dsa_implemented{
    template<typename _RandomAccessIterator>
    void merge_sort(_RandomAccessIterator first, _RandomAccessIterator last);
    /**
     * Sorts the elements in a sequence within [first, last)
     * the sorting has O(n * lg n) worst case and average case run time behavior
     * the elements are sorted in ascending order
    **/
    template<typename _RandomAccessIterator, typename _Compare>
    void merge_sort(_RandomAccessIterator first, _RandomAccessIterator last,
        _Compare comp);
    /**
     * Sorts the elements in a sequence within [first, last). The comp function is
     * used to determine order
     * the sorting has O(n * lg n) worst case and average case run time behavior
    **/
    template<typename _RandomAccessIterator, typename _Compare>
    void __merge_sort(_RandomAccessIterator first, _RandomAccessIterator last,
        _Compare comp);
    /**
     * Internally used by both versions of the merge_sort(). This function defines
     * the principal merge sort algorithm as described in Introduction to Algorithms
    **/

    template<typename _RandomAccessIterator, typename _Compare>
    void ___merge(_RandomAccessIterator& first, _RandomAccessIterator& mid, 
	    _RandomAccessIterator& last, _Compare comp);
    /**
     * Internally used by __merge_sort to merge two sorted subsequences
    **/

}



//                  === D E F I N I T I O N ===


template<typename _RandomAccessIterator>
void dsa_implemented::merge_sort(_RandomAccessIterator first, _RandomAccessIterator last)
{
    typedef typename std::iterator_traits<_RandomAccessIterator>::value_type
	_ValueType;

	// concept requirements
    __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept<
	  _RandomAccessIterator>)
    __glibcxx_function_requires(_LessThanComparableConcept<_ValueType>)
    __glibcxx_requires_valid_range(first, last);
    
    dsa_implemented::__merge_sort(first, last, [](_ValueType a, _ValueType b)
        {return a <= b;});
}

template<typename _RandomAccessIterator, typename _Compare>
void dsa_implemented::merge_sort(_RandomAccessIterator first, _RandomAccessIterator last,
    _Compare comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type
	_ValueType;

    // concept requirements
    __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept<
	  _RandomAccessIterator>)
    __glibcxx_function_requires(_BinaryPredicateConcept<_Compare, _ValueType,
				_ValueType>)
    __glibcxx_requires_valid_range(first, last);
    
    dsa_implemented::__merge_sort(first, last, comp);
}

template<typename _RandomAccessIterator, typename _Compare>
void dsa_implemented::__merge_sort(_RandomAccessIterator first, _RandomAccessIterator last,
    _Compare comp)
{   
    if(last - first > 1){
        _RandomAccessIterator mid = first + (last - first) / 2;
        dsa_implemented::__merge_sort(first, mid, comp);
        dsa_implemented::__merge_sort(mid, last, comp);
        dsa_implemented::___merge(first, mid, last, comp);
    }
}

template<typename _RandomAccessIterator, typename _Compare>
void dsa_implemented::___merge(_RandomAccessIterator& first, _RandomAccessIterator& mid, 
	_RandomAccessIterator& last, _Compare comp)
{
    typedef typename std::iterator_traits<_RandomAccessIterator>::value_type
	_ValueType;

    // copying two sorted halfs
    std::vector<_ValueType> L(first, mid), R(mid, last);

    //merging two sorted halfs
    unsigned long long i = 0, j = 0;
    _RandomAccessIterator& it = first;
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