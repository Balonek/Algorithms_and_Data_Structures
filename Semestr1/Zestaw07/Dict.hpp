#pragma once
#include <string>
#include <utility>  
#include <iostream>   
#include <stdexcept> 
#include <vector>

static const std::size_t input_capacity = 31;

unsigned int hash(const std::string& key) {
    unsigned int hash = 2166136261u; 
    for (unsigned char c : key) {
        hash ^= c;           
        hash *= 16777619u;   
    }
    return hash;
}
template <class K, class V>
class Dict {
    using Pair = std::pair<K, V>;

private:
    struct Node {
        Pair pair;  
        Node* next;
        Node(const K& k, const V& v, Node* n = nullptr)
            : pair(k, v), next(n) {}
    };

    std::vector<Node*> table;
    int currentSize;

public:
    Dict(std::size_t capacity = input_capacity): table(capacity, nullptr), currentSize(0) {}

    ~Dict() {
        clear();
    }
    void clear() {
        for (std::size_t i = 0; i < table.size(); i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        currentSize = 0;
    }
    bool insert(const Pair& p) {
    std::size_t index = hash(p.first) % table.size(); 
    Node* curr = table[index];

    while (curr) {
        if (curr->pair.first == p.first) {
            curr->pair.second = p.second;
            return false;
        }
        curr = curr->next;
    }

    Node* newNode = new Node(p.first, p.second, table[index]);
    table[index] = newNode;
    ++currentSize;
    return true;
}

    bool find(const K& k) {
    std::size_t index = hash(k) % table.size();
    Node* curr = table[index];
    while (curr) {
        if (curr->pair.first == k) {
            return true; 
        }
        curr = curr->next;
    }
    return false; 
}

    V& operator[](const K& k) {
    std::size_t index = hash(k) % table.size();
    Node* curr = table[index];

    while (curr) {
        if (curr->pair.first == k) {
            return curr->pair.second; 
        }
        curr = curr->next;
    }

    Node* newNode = new Node(k, V(), table[index]);
    table[index] = newNode;
    ++currentSize;
    return newNode->pair.second;
}

    bool erase(const K& k) {
            std::size_t index = hash(k) % table.size();
            Node* curr = table[index];
            Node* prev = nullptr;
            while(curr) {
                if(curr->pair.first == k) {
                    if (prev == nullptr) {
                    table[index] = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    --currentSize;
                    return true;
                }
                prev = curr;
                curr = curr->next;
            }
            return false;
        }
    int size() const {
        return currentSize;
    }

    bool empty() const {
        return (currentSize == 0);
    }
    void buckets() {
        std::size_t min_len = static_cast<std::size_t>(-1);
        std::size_t max_len = 0;
        std::size_t buckets = table.size();

        for (std::size_t i = 0; i < buckets; i++) {
            std::size_t length = 0;
            Node* curr = table[i];
            while (curr) {
                length++;
                curr = curr->next;
            }
            if (length < min_len) {
                min_len = length;
            }
            if (length > max_len) {
                max_len = length;
            }
        }
        if (empty()) {
            min_len = 0;
        }
        std::cout << "# " 
                  << currentSize << " " 
                  << buckets << " "
                  << min_len << " "
                  << max_len << std::endl;
    }
    
};
