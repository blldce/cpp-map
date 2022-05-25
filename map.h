

#ifndef MAP_H
#define MAP_H

template <typename K = int, typename V = int>
struct node
{
    K key;
    V value;
    struct node<K, V>(*next_node);
    struct node<K, V>(*prev_node);
};

template <typename K = int, typename V = int>
class Map
{
private:
    int size;
    struct node<K, V>(*head);
    bool check_key(K);

public:
    explicit Map();
    bool add(K, V);
    bool remove_item(K);
    V peek(K);
    void print_items();
};

#include "map.tpp"

#endif
