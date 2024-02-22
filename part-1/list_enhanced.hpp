
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    // WRITE YOUR CODE HERE
    if (node == nullptr || node->next == nullptr) {
        return;
    }
    Node<T> *NodeToDelete = node->next.get();

    node->next = std::move(NodeToDelete->next);

}

#endif // __list_enhanced__