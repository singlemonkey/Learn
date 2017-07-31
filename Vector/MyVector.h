
#ifndef VECTOR_MYVECTOR_H
#define VECTOR_MYVECTOR_H

typedef int rank;
int DefaultCapacity=3;

template <typename T> class MyVector{
protected:
    rank _size;
    int _capacity;
    T* _elem;
    void copyFrom(T* const A,rank lo,rank hi);
    void expand();
    void shrink();
public:
//构造函数
    MyVector(int capacity=DefaultCapacity,int size=0,T v=0){
        _capacity=capacity;
        _elem=new T[_capacity];
        for (_size = 0; _size< size;_size++) {
            _elem[_size]=v;
        }
    };
    MyVector(T const* A,rank n){
        copyFrom(A,0,n);
    };
    MyVector(T const* A,rank lo,rank hi){
        copyFrom(A,lo,hi);
    }
    MyVector(MyVector<T> const& V){
        copyFrom(V._elem,0,V._size);
    }
    MyVector(MyVector<T> const& V,rank lo,rank hi){
        copyFrom(V._elem,lo,hi);
    }
//析构函数
    ~MyVector(){
        delete [] _elem;
    }
//只读访问接口
    rank find(T const& e,rank lo,rank hi) const ;
    rank find(T const& e) const {
        return find(e,0,_size);
    };
    int disordered() const;
//可写访问接口
    rank insert(rank n, T const &e);
    int remove(rank lo,rank hi);
    T remove(rank r);
    int deduplicate();
    int uniquify();
//遍历
    template <typename VST> void traverse(VST&);
};

#endif //VECTOR_MYVECTOR_H
