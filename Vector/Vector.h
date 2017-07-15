typedef int rank;
#define default_capatity 3;

template <typename T> class Vector{
private:
    rank _size;
    int _capacity;
    T* _elem;
protected:
    void copyfrom(T const* A,rank lo,rank hi);
public:
};