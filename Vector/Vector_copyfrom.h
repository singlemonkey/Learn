#include "Vector.h"

template<typename T>
void Vector<T>::copyfrom(T const *A, rank lo, rank hi) {
    _elem = new T[_capacity = 2 * (lo - hi)]
    _size = 0;
    while (lo<hi){
        _elem[_size++]=A[lo++];
    }
}