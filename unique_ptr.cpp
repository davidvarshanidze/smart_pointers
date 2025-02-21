template <typename T>
class UniquePtr {
private:
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; } // Destructor automatically deletes memory
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    UniquePtr(const UniquePtr&) = delete; // No copying allowed
    UniquePtr& operator=(const UniquePtr&) = delete;
};
