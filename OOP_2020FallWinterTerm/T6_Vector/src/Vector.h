#include <iostream>
template <class T>
class Vector{
public:
    Vector(){                      // creates an empty vector
        m_nSize = m_nCapacity = 0;
        m_pElements = nullptr;
    }                      
    Vector(int size){              // creates a vector for holding 'size' elements
        m_nSize = 0;
        m_nCapacity = size;
        m_pElements = new T[size];
    }
    Vector(const Vector& r){       // the copy ctor
        this->m_nSize = r.m_nSize;
        this->m_nCapacity = r.m_nCapacity;
        this->m_pElements = new T[r.m_nSize];
        for(int i = 0;i < this->size();++i){
            *(this->m_pElements + i) = *(r.m_pElements + i);
        }
    }
    ~Vector(){                     // destructs the vector 
        delete[] m_pElements;
        std::cout << "D'tor done\n";
    }
    T& operator[](int index){      // accesses the specified element without bounds checking
        return *(m_pElements + index);
    }
    T& at(int index){              // accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
        if(0 <= index && index < m_nSize){
            return (*this)[index];
        } else {
            throw std::out_of_range("index out of range");
        }
    }
    int size() const{              // return the size of the container
        return this->m_nSize;
    }
    void push_back(const T& x){    // adds an element to the end 
    if(m_nSize == m_nCapacity) this->inflate();
        *(m_pElements + m_nSize++) = x;
    }
    void clear(){                  // clears the contents
        this->m_nSize = 0;
    }
    bool empty() const{            // checks whether the container is empty 
        return m_nSize == 0;
    }
private:
    void inflate(){                // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
        m_nCapacity <<= 1;
        T *tmp = new T[m_nCapacity];
        for(int i = 0;i < m_nSize;++i){
            *(tmp + i) = *(m_pElements + i);
        }
        delete[] m_pElements;
        m_pElements = tmp;
    }
    T *m_pElements;                // pointer to the dynamically allocated storage
    int m_nSize;                   // the number of elements in the container
    int m_nCapacity;               // the number of elements that can be held in currently allocated storage
};
