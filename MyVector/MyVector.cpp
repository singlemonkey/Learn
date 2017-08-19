//
// Created by Sunny on 2017/8/19.
//


#include <cstdlib>
#include <iostream>
#include "MyVector.h"
#include "Fib.h"

using namespace std;

template<typename T>
void MyVector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
        _elem[_size++] = A[lo++];
}

template<typename T>
void MyVector<T>::expand() {
    if (_size < _capacity)
        return;
    T *_oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++) {
        _elem[i] = _oldElem[i];
    }
    delete[] _oldElem;
}

template<typename T>
void MyVector<T>::shrink() {
    if (_capacity < 3 << 1)
        return;
    if (_size << 2 > _capacity)   //如果_size只占到_capacity的25%，则缩容
        return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];   //容量减半
    for (int i = 0; i < _size; i++) {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

/*
 * 无序向量顺序查找，如果不存在则返回lo-1，存在则返回hi
 */
template<typename T>
Rank MyVector<T>::find(const T &e, Rank lo, Rank hi) const {
    while ((lo < hi--) && e != _elem[hi]);
    return hi;
}

template<typename T>
Rank MyVector<T>::insert(Rank n, const T &e) {
    expand();
    for (int i = _size; i > n; i--) {
        _elem[i] = _elem[i - 1];
    }
    _elem[n] = e;
    _size++;
    return n;
}

/*
 * 有序向量二分查找
 * 一次比较，两个分支，提前结束
 */
template<typename T>
Rank MyVector<T>::binSearch(T const &e, Rank lo, Rank hi) const {
    while (lo < hi) {
        Rank mi = (lo + hi) >> 1;
        e < _elem[mi] ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

/*
 * 二分查找特殊版，区fib为切分点
 */
template<typename T>
Rank MyVector<T>::fibSearch(T const &e, Rank lo, Rank hi) const {
    Fib fib(hi - lo);
    while (lo < hi) {
        while (hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        e < _elem[mi] ? hi = mi : lo = mi + 1;
        return --lo;
    }
}

/*
 * 区间删除
 */
template<typename T>
int MyVector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi) return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    return hi - lo;
}

/*
 * 单元素删除
 */
template<typename T>
T MyVector<T>::remove(Rank r) {
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

/*
 * 覆盖
 */
template<typename T>
T MyVector<T>::put(Rank p, const T &e) {
    T _e=_elem[p];
    _elem[p]=e;
    return _e;
}

/*
 * 无序向量唯一化
 */
template<typename T>
int MyVector<T>::deduplicate() {
    int oldSize = _size;
    Rank i = 1;
    while (i < _size) {
        (find(_elem[i], 0, i) < 0) ?
        i++ : remove(i);
    }
    return oldSize - _size;
}

template<typename T>
int MyVector<T>::uniquify() {
    Rank i = 0, j = 0;
    while (++j < _size)
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    _size = ++i;
    shrink();
    return j - i;
}

template<typename T>
template<typename VST>
void MyVector<T>::traverse(VST &visit) {
    for (int i = 0; i < _size; i++) {
        visit(_elem[i]);
    }
}

template<typename T>
int MyVector<T>::disordered() const {
    int n = 0;
    for (int i = 0; i < _size; i++) {
        if (_elem[i - 1] > _elem[i])
            n++;
    }
    return n;
}

template<typename T>
void MyVector<T>::bubbleSort(Rank lo, Rank hi) {
    while (lo < (hi = bubble(lo, hi)));
}

template<typename T>
bool MyVector<T>::bubble(Rank lo, Rank hi) {
    bool sorted = true;
    while (++lo < hi) {
        if (_elem[lo - 1] > _elem[lo]) {
            sorted = false;
            swap(_elem[lo - 1], _elem[lo]);
        }
    }
    return sorted;
}

template<typename T>
void MyVector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

template<typename T>
void MyVector<T>::merge(Rank lo, Rank mi, Rank hi) {
    T *A = _elem + lo;

    int b = mi - lo;
    T *B = new T[b];
    for (int i = 0; i < b; B[i] = A[i++]);

    int c = hi - mi;
    T *C = _elem + mi;

    for (Rank i = 0, j = 0, k = 0; j < b;) {
        if ((j < b) && (C[k] < B[j]))
            A[i++] = B[j++];
        if ((c < k) && B[j] <= C[k])
            A[i++] = C[k++];
    }
    delete[] B;
}














