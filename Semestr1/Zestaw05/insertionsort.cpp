#include <iostream>
#include <chrono>
#include <vector>
#include <iterator>
#include <algorithm>

template <class T> 
void sort(std::vector<T>& v) {
    {
       for (auto it = v.begin() + 1; it != v.end(); ++it) {
        auto x = *it; 
        auto pos = it;  
        while (x < *(pos -1)) {
            *pos = *(pos - 1); 
            --pos;
        }
        *pos = x;
    }
}
}

int main() {

    std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    sort(v);
    for(const auto& i : v){
        std::cout << i << std::endl;
    }
}