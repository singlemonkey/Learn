
typedef int Rank;

template<typename T>
class MyVector {
protected:
    Rank _size;
    int _capacity;
    T *_elem;

    void copyFrom(T const *A, Rank lo, Rank hi);

    void expand();

    void shrink();

public:
//构造函数
    MyVector(int capacity = 3, int size = 0, T v = 0) {
        _capacity = capacity;
        _elem = new T[_capacity];
        for (_size = 0; _size < size; _size++) {
            _elem[_size] = v;
        }
    };

    MyVector(T const *A, Rank n) {
        copyFrom(A, 0, n);
    };

    MyVector(T const *A, Rank lo, Rank hi) {
        copyFrom(A, lo, hi);
    }

    MyVector(MyVector<T> const &V) {
        copyFrom(V._elem, 0, V._size);
    }

    MyVector(MyVector<T> const &V, Rank lo, Rank hi) {
        copyFrom(V._elem, lo, hi);
    }

//析构函数
    ~MyVector() {
        delete[] _elem;
    }

//只读访问接口
    Rank find(T const &e, Rank lo, Rank hi) const;

    Rank find(T const &e) const {
        return find(e, 0, _size);
    };

    Rank binSearch(T const &e, Rank lo, Rank hi) const;

    Rank fibSearch(T const &e, Rank lo, Rank hi) const;

    int disordered() const;

//可写访问接口
    Rank insert(Rank n, T const &e);

    int remove(Rank lo, Rank hi);

    T remove(Rank r);

    T put(Rank p,T const &e);

    int deduplicate();

    int uniquify();

    void bubbleSort(Rank lo, Rank hi);

    bool bubble(Rank lo, Rank hi);

    void mergeSort(Rank lo, Rank hi);

    void merge(Rank lo, Rank mi, Rank hi);

//遍历
    template<typename VST>
    void traverse(VST &);
};

