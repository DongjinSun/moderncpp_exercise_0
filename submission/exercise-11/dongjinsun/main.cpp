#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class MyVector {
    public:
        MyVector(): capacity_(3), size_(0){
            data_ = new T[3];
        }
        ~MyVector(){
            delete[] data_;
        }

        T& operator[](std::size_t i) &{
                return data_[i];
        }

        const T& operator[](std::size_t i) const &{
                return data_[std::move(i)];
        }

        T&& operator[](std::size_t i)&& {
                return std::move(data_[i]);
        }

        void push_back(const T& n){
            if (size_ == capacity_-1){
                capacity_ *= 2;
                T* temp = new T[capacity_];
                std::copy(data_,data_+(int)size_,temp);
                delete[] data_;
                data_ = temp;
            }
            data_[size_] = n;
            size_++;
        }
        
        void pop_back(){
            size_--;
        }

        std::size_t size() const {
            return size_;
        }

        MyVector(const MyVector& other) 
                : capacity_(other.capacity_),
                size_(other.size_)
        {
            data_ = new T[capacity_];
            std::copy(other,other+(int)size_,data_);
        }
        MyVector(MyVector&& other) {
            std::cout << "rvalue" << std::endl;
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = other.data_;
            other.capacity_ = 0;
            other.size_ = 0;
            other.data_ = nullptr;
        }

        template<typename... Args>
        void emplace_back(Args&&... args){
            if (size_ == capacity_-1){
                capacity_ *= 2;
                T* temp = new T[capacity_];
                std::copy(data_,data_+(int)size_,temp);
                delete[] data_;
                data_ = temp;
            }
            size_++;
            data_[size_] = T(std::forward<Args>(args)...);

        }

        MyVector& operator=(const MyVector& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new T[capacity_];
        std::copy(other,other+(int)size_,data_);
        return *this;
        }

        MyVector& operator=(MyVector&& other) { 
            std::cout << "rvalue = " << std::endl;
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = other.data_;
            other.capacity_ = 0;
            other.size_ = 0;
            other.data_ = nullptr;
            return *this;
        }
    private:
        T* data_;
        int capacity_;
        size_t size_;
    
  
    
  
};


// Use case
int main() {

  {
    MyVector<std::string> v;
    
    v.push_back("hello");
    v.push_back("world");
    
    const char str[] = "hello again";
    
    v.emplace_back(std::begin(str), std::end(str));
    v.emplace_back(std::string("hello last time")); // No copy of `std:string` should be performed
    std::cout << v[0];
  } // v, v2 소멸


  return 0;
}