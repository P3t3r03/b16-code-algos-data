#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    // WRITE YOUR CODE HERE
    for(size_t i = index; i < A.size() - 1; i++){
        A.at(i) = A.at(i+1);
    }
    A.pop_back();



}

#endif // __array_delete__