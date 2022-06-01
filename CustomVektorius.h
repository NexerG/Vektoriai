#pragma once

template<typename vector>
class VectorIterator
{
public:
    using ValueType = typename vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    VectorIterator(PointerType ptr)
        : m_Ptr(ptr) {}

    VectorIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }
    VectorIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index)
    {
        return *(m_Ptr + index);
    }

    PointerType operator->()
    {
        return m_Ptr;
    }

    ReferenceType operator*()
    {
        return *m_Ptr;
    }

    bool operator==(const VectorIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator& other) const
    {
        return !(*this == other);
    }

private:
    PointerType m_Ptr;
};


template<typename T>
class Customvector
{
private:
    T* Data = nullptr;

    size_t size = 0; //used memory
    size_t capacity = 0; // available memory

public:
    using ValueType = T;
    using Iterator = VectorIterator<Customvector<T>>;
    Customvector() //constructor
    {
        ReAlloc(sizeof(ValueType));
    }

    ~Customvector() { delete[] Data; }//destructor

    Customvector& operator=(const Customvector& a)//operator=
    {
        if (this == &a)
        {
            return *this;
        }
        this->capacity = a.capacity;
        ReAlloc(capacity);
        memcpy(this->Data, a.Data, a.size*sizeof(ValueType));

        return *this;
    }

    Customvector(const Customvector& value)
    {
        *this = value;
    }

    void PushBack(const T& value) // add new element to back
    {
        if (size >= capacity)
        {
            ReAlloc(size * sizeof(ValueType));
        }

        Data[size] = value;
        size++;
    }

    const T& operator[](size_t index)const //access at index
    {
        return Data[index];
    }

    T& operator[](size_t index) //access at index and edit
    {
        return Data[index];
    }

    size_t Size() const { return size; } //size of container

    size_t Capacity() const { return capacity; } //size of capacity

    void assign(size_t count, const T& value)
    {
        ReAlloc(count);
        for (int i = 0; i <= count; i++)
        {
            Data[size] = value;
            size++;
        }
    }

    T& front() //access first element
    {
        return Data[0];
    }

    T& back() //access last element
    {
        return Data[size - 1];
    }

    const T* data() const //pointer to container
    {
        return Data;
    }

    void shrink_to_fit() //set capacity=size
    {
        capacity = size;
    }

    void reserve(size_t new_cap)// increase the capacity of the vector
    {
        capacity = new_cap;
    }

    bool empty() const //check if container is empty
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    void PopBack()
    {
        if (size > 0)
        {
            size--;
            Data[size].~T();
        }

    }

    void Clear()
    {
        for (size_t i = 0; i < size; i++)
        {
            Data[i].~T();
        }
        size = 0;
    }

    Iterator begin()
    {
        return Iterator(Data);
    }
    Iterator end()
    {
        return Iterator(Data + size);
    }


private:
    void ReAlloc(size_t newCapacity) //increase capacity of container
    {

        T* newBlock = new T[newCapacity];

        if (newCapacity < size)
        {
            size = newCapacity;
        }

        for (size_t i = 0; i < size; i++)
        {
            newBlock[i] = Data[i];
        }
        delete[] Data;
        Data = newBlock;
        capacity = newCapacity;
    }
};