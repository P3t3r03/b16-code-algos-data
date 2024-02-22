#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // WRITE YOUR CODE HERE
        assert(!this->full());
        if(this->_position == this->_storage.size()-1) {
            this->_position = 0;
        }
        else{
        this->_storage[this->_position] = value;
        this->_size++;
        }

    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        this->_size--;

    }

    // Remove all elements from the queue
    void clear() { 
        // WRITE YOUR CODE HERE
        }
    

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        auto tail = this->_position + 1;
        if(tail == this->_storage.size()) {
            tail = 0;
        }
        return tail;

    }
};

#endif // __queue_enhanced__