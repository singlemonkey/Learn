
#include "MyVector.h"

template<typename T>
void MyVector<T>::copyFrom(T *const A, rank lo, rank hi) {
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
    if (_capacity < DefaultCapacity << 1)
        return;
    if (_size << 2 > _capacity)   //如果_size只占到_capacity的25%，则缩容
        return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];   //容量减半
    for (int i = 0; i < _size; i++) {
        _elem[i]=oldElem[i];
    }
    delete [] oldElem;
}

/*
 * 无序向量顺序查找，如果不存在则返回lo-1，存在则返回hi
 */
template<typename T>
rank MyVector<T>::find(const T &e, rank lo, rank hi) const {
    while ((lo < hi--) && e != _elem[hi]);
    return hi;
}

template<typename T>
rank MyVector<T>::insert(rank n, const T &e) {
    expand();
    for (int i = _size; i > n; i--) {
        _elem[i] = _elem[i - 1];
    }
    _elem[n] = e;
    _size++;
    return n;
}

/*
 * 区间删除
 */
template<typename T>
int MyVector<T>::remove(rank lo, rank hi) {
    if (lo == hi) return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    return hi - lo;
}

/*
 * 单元素删除
 */
template<typename T>
T MyVector<T>::remove(rank r) {
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

/*
 * 无序向量唯一化
 */
template<typename T>
int MyVector<T>::deduplicate() {
    int oldSize = _size;
    rank i = 1;
    while (i < _size) {
        (find(_elem[i], 0, i) < 0) ?
        i++ : remove(i);
    }
    return oldSize - _size;
}

template<typename T>
int MyVector<T>::uniquify() {
    rank i = 0, j = 0;
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








