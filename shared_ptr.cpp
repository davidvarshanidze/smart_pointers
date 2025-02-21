template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* ref_count;
public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}
    
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++; // Increase reference count
    }

    ~SharedPtr() {
        (*ref_count)--;
        if (*ref_count == 0) { 
            delete ptr;
            delete ref_count;
        }
    }
};
