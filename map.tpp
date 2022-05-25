

#include <iostream>
#include "map.h"

template <typename K, typename V>
Map<K, V>::Map() : size(0), head(nullptr)
{
}

template <typename K, typename V>
bool Map<K, V>::add(K key, V value)
{
    struct node<K, V>(*new_node_ptr);
    if (this->head == nullptr) // first time?
    {
        // we do not need to check key, its first addition anyway
        new_node_ptr = new struct node<K, V>;
        new_node_ptr->next_node = nullptr;
        new_node_ptr->prev_node = nullptr;
        new_node_ptr->key = key;
        new_node_ptr->value = value;
        this->head = new_node_ptr;
    }
    else
    {
        if (check_key(key)) // check key is exist
            return false;
        new_node_ptr = new struct node<K, V>;
        new_node_ptr->key = key;
        new_node_ptr->value = value;
        head->next_node = new_node_ptr;
        new_node_ptr->next_node = nullptr;
        new_node_ptr->prev_node = this->head;
        this->head = new_node_ptr;
    }
    this->size++;
    return true;
}

template <typename K, typename V>
bool Map<K, V>::remove_item(K key)
{
    if (!check_key(key))
        return false;
    struct node<K, V>(*iter) = this->head;
    while (iter != nullptr)
    {
        if (iter->key == key)
        {
            struct node<K, V>(*curr_next_node) = iter->next_node;
            struct node<K, V>(*curr_previous_node) = iter->prev_node;
            if (curr_next_node != nullptr)
                curr_next_node->prev_node = curr_previous_node;
            if (curr_previous_node != nullptr)
                curr_previous_node->next_node = curr_next_node;
            delete iter;
            this->size--;
            return true;
        }
        iter = iter->prev_node;
    }
    return false;
}

template <typename K, typename V>
V Map<K, V>::peek(K key)
{
    struct node<K, V>(*iter) = this->head;
    while (iter != nullptr)
    {
        if (iter->key == key)
            return iter->value; // ret value
        iter = iter->prev_node;
    }
    return static_cast<V>(0); // false
}

template <typename K, typename V>
bool Map<K, V>::check_key(K key)
{
    struct node<K, V>(*iter) = this->head;
    while (iter != nullptr)
    {
        if (iter->key == key)
            return true;
        iter = iter->prev_node;
    }
    return false;
}
template <typename K, typename V>
void Map<K,V>::print_items()
{
    printf("**********************\n");
    struct node<K,V>(*iter) = this->head;
    while (iter != (void(*))0)
    {
        std::cout << "Address : " << iter << " -- Key : " << iter->key << " -- Value : " << iter->value << " -- previous node : " << iter->prev_node << " -- next node : " << iter->next_node << std::endl;
        iter = iter->prev_node;
    }
}
