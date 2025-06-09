#include "LinkedQueue.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void count_sort(std::vector<int>& values, int exp) {
    const int base = 10;
    Queue all, q[base];

    for (int num : values) {
        int digit = (num / exp) % base;
        q[digit].push(num);
    }

    for (int i = 0; i < base; i++) {
        while (!q[i].empty()) {
            all.push(q[i].pop());  
        }
    }
    int index = 0;
    while (!all.empty()) {
        values[index++] = all.pop();  
}
}
int max_in_vector(const std::vector<int>& values) {
    return *std::max_element(values.begin(), values.end());
}
void radix(std::vector<int>& v) {
    int max_value = max_in_vector(v);

    for (int exp = 1; max_value / exp > 0; exp *= 10) {
        count_sort(v, exp);
    }
}
int main() {
    std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    radix(v);
    for (const auto& i : v) {
        std::cout << i << std::endl;
    }
    return 0;
}
