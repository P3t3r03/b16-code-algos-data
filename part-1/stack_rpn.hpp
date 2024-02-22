#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

template<typename T>
void plus(Stack<T>& Stack) {
    T temp1 = Stack.top();
    Stack.pop();
    T temp2 = Stack.top();
    Stack.pop();

    T value = temp1 + temp2;
    Stack.push(value);
}
// WRITE YOUR CODE HERE
template<typename T>
void multiplies(Stack<T>& Stack) {
    T temp1 = Stack.top();
    Stack.pop();

    T temp2 = Stack.top();
    Stack.pop();

    T value = temp1 * temp2;
    Stack.push(value);
}

template<typename T>
void divides(Stack<T>& Stack) {
    T temp1 = Stack.top();
    Stack.pop();

    T temp2 = Stack.top();
    Stack.pop();

    T value = temp1 / temp2;
    Stack.push(value);
}

template <typename T> class StackRpn : public Stack<T> {
public:
    using Stack<T>::Stack;

    StackRpn<T> &operator<<(const T value) {
        this->push(value);
        return *this;
    }
    
    StackRpn<T> &operator<<(std::function<void(StackRpn<T>&)> func) {
        func(*this);
        return *this;
    }
};



#endif // __stack_rpn__