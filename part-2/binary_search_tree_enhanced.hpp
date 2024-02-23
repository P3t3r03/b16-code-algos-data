#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    // WRITE YOUR CODE HERE
    auto temp = tree;
    while(left(temp)) {
        temp = left(temp);
    }
    return temp;

}

template <typename T> T bst_max(const T &tree)
{
    auto temp = tree;
    while(right(temp)) {
        temp = right(temp);
    }
    return temp;
}

#endif // __binary_saerch_tree_enhanced__